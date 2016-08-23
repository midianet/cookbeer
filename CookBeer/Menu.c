//#include <max6675.h>
//#include <LiquidCrystal_SR3W.h>
//#include <LiquidCrystal_SR2W.h>
//#include <LiquidCrystal_SR.h>
//#include <LiquidCrystal.h>
//#include <LCD.h>
//#include <I2CIO.h>
//#include <FastIO.h>
//#include <Wire.h>
//#include <LiquidCrystal_I2C.h>
//#include <Keypad.h>
//#include <Thread.h>
//#include <ThreadController.h>
//#include <EEPROM.h>
//#include <MenuSystem.h>
//#include <Time.h>
////Carrega a biblioteca do RTC DS1307
//#include <DS3232RTC.h>
///******************************************************************************************/
//enum statusMenu {
//  TELA_INICIAL, 
//  MENU_PRINCIPAL,
//  TEMP_MAX,
//  TEMP_MIN,
//  TEMP_VERIFICA,
//  FORNO_LIGADO,
//  FORNO_DESLIGADO
//};
//
//statusMenu status_menu = TELA_INICIAL;
//
///***************************Menus***************************************************************/
//MenuSystem menuSystem;
//Menu menu("Menu:A,B,C,D,#,*");
//Menu menu0("Forno->");
//    MenuItem menuItem01("  -Ativar Forno");
//    MenuItem menuItem02("  -Desliga Forno");
//Menu menu1("Temperatura->");
//    MenuItem menuItem11("  -Temp Min");
//    MenuItem menuItem12("  -Temp Max");
//  MenuItem menuItem13("  -Verifica Temp");
//Menu menu2("<-  Relogio  ->");
//    MenuItem menuItem21("  -Mostrar");
//    MenuItem menuItem22("  -Acerdar Data");
//  MenuItem menuItem23("  -Acerdar Hora");
// Menu menu3("<- Cronometro ->");
//  MenuItem menuItem31("  -Ativar");
//  MenuItem menuItem32("  -Configurar");
// Menu menu4("<- Perifericos");
//  MenuItem menuItem41("  -Rele");
//  MenuItem menuItem42("  -Beeep");
//
//// Menu Select: determina a navegação pelos menus ou pela tela de inicial
//  boolean menuSelect = false;
//
///***************************threads***************************************************************/
//ThreadController tControle = ThreadController();
//Thread threadLCD = Thread();
//Thread threadLerTemperatura = Thread();
//Thread threadLerTeclado = Thread();
//Thread threadFornoTemperatura = Thread();
//
//
//
///***************************TECLADO***************************************************************/
//const byte numRows = 4; //numero de linha do teclado
//const byte numCols = 4; //numero de colunas do teclado
//
//char keymap[numRows][numCols] =// mapa de teclad o teclado
//{
//  { '1','2','3','A' },
//  { '4','5','6','B' },
//  { '7','8','9','C' },
//  { '*','0','#','D' }
//};
//
////pinos de conexão do teclado com as entradas o arduino
//byte rowPins[numRows] = { 10, 3, 4, 5 }; //linhas de 0 a 3
//byte colPins[numCols] = { 9, 2, 6, 7 }; //colunas de 0 a 3
//// variável que armazena a ultima telca lida
//char ultimaTeclaPressionada = ' ';
//
//
//                   //initializes an instance of the Keypad class
//Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins, numRows, numCols);
//
///***************************LCD***************************************************************/
//LiquidCrystal_I2C lcd(0x27, 2, 4, 0, 4, 5, 6, 7, 3, POSITIVE);  // Endereçamento I2C  do Lcd
//
///***************************SENSOR DE TEMPERATURA*******************************************************/
//int thermoDO = 12;
//int thermoCS = 11;
//int thermoCLK = 13;
//MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);
//double temperaturaAtual = 0.00;
//
//String myTempMax = "";
//String myTempMin = "";
//int contadorTemp = 0;
//float mtempMax = 29.00;
//float mtempMin = 25.00;
//
//
//byte relogio[8] = {// icone de relógio
//  B00000,
//  B01110,
//  B10101,
//  B10111,
//  B10001,
//  B01110,
//  B00000,
//  B00000 };
//
//byte termometro[8] = //icone do termometro
//{
//  B00100,
//  B01010,
//  B01010,
//  B01110,
//  B01110,
//  B11111,
//  B11111,
//  B01110
//};
//
//byte degC[8] = { B01000, B10100, B01000, B00111, B01000, B01000, B01000, B00111 };  //  icone do graus celsius
//byte barra[8] = { B00001, B00001, B00001, B00001, B00001, B00001, B00001, B00001 };  //  Icone Barra Vertical
//
//
///***************************RELOGIO***********************************************/
////clock
//char timebuf[10];  // Time
//char datebuf[10];  // Date
//char settime[12];  //
//int year2digit;    // 2 digit year
//
////alarm
//char alarm[10];    //alarm
//
///***************************Rele***********************************************/
//#define rele A3
//
//
///***************************Alarme***********************************************/
//#define piezoPin A0
//char tempMin[4];
//char tempMax[4];
//
//
///***************************EEPROM***********************************************/
///*
//int horini=EEPROM.read(0); // variavel a ser alterada pelo menu
//int minini=EEPROM.read(1);
//int horfim=EEPROM.read(2);
//int minfim=EEPROM.read(3);
//
//t1[0]= EEPROM.read(0);
//t1[1]= EEPROM.read(1);
//t1[2]= EEPROM.read(2);
//t1[3]= EEPROM.read(3);
//t1[4]= 8;
//t1[5]= 1;
//
//
//#define epsilon ((double)0.000999)
//bool is_approximately_equal(double x, double y)
//{
//return (abs(x - y) < epsilon);
//}
//
//*/
//
//
///***************************FIM CONFIGURAÇÃO***********************************************/
//
//void setup() {
//  pinMode(rele, OUTPUT);// devinido pino do rele como saída
//  digitalWrite(rele, HIGH);// rele desligado
//  
//  /*-----------------Sincronizando Relogio com a lib Time--------------------------*/
//  setSyncProvider(RTC.get);   // the function to get the time from the RTC
//  if (timeStatus() != timeSet)
//    Serial.println("Unable to sync with the RTC");
//  else
//    Serial.println("RTC has set the system time");
//
//  /*-----------------Configurando Menus-----------------------------------*/
//  menu.add_menu(&menu0);
//  menu0.add_item(&menuItem01, &on_ativa_forno);
//  menu0.add_item(&menuItem02, &on_desliga_forno);
//  
//  
//  menu.add_menu(&menu1);
//  menu1.add_item(&menuItem11, &on_temp_min);
//  menu1.add_item(&menuItem12, &on_temp_max);
//  menu1.add_item(&menuItem13, &on_temp_verifica);
//  
//  menu.add_menu(&menu2);
//  menu2.add_item(&menuItem21, &on_item2_selected);
//  menu2.add_item(&menuItem22, &on_item2_selected);
//  menu2.add_item(&menuItem23, &on_item2_selected);
//
//  menu.add_menu(&menu3);
//  menu3.add_item(&menuItem31, &on_item2_selected);
//  menu3.add_item(&menuItem32, &on_item2_selected);
//  
//  menu.add_menu(&menu4);
//  menu4.add_item(&menuItem41, &on_item2_selected);
//  menu4.add_item(&menuItem42, &on_Beep);
//    
//  menuSystem.set_root_menu(&menu);
//  Serial.println("Menu ok.");
//  displayMenu();
//
//  /*-----------------Acerta Relógio-----------------------------------*/
//// código para acertar o relogio
//  //setTime(21, 11, 00, 17, 07, 2016);
//  //time_t t = now();
//  //RTC.set(t);
//
////setSyncProvider(RTC.get);
////if (timeStatus() != timeSet)
////Serial.println("Unable to sync with the RTC");
////else
////Serial.println("RTC has set the system time");
///**/
//pinMode(piezoPin , OUTPUT);  // cofigura o Buzzer
//
///*-----------------Configura tread - Teclado-----------------------------------*/
//threadLerTeclado.onRun(lerTeclado);
//threadLerTeclado.setInterval(100);
///*-----------------Configura tread - Aferir Temperatura-----------------------------------*/
//threadLerTemperatura.onRun(aferirTemperatura);
//threadLerTemperatura.setInterval(600);
///*-----------------Configura tread - Atualizar LCD_____--------------------*/
//threadLCD.onRun(atualizarTela);
//threadLCD.setInterval(500);
///*-----------------Configura tread - Controle Forno Temperatura-------------------*/
//threadFornoTemperatura.onRun(atualizaFornoTemperatura);
//threadFornoTemperatura.setInterval(500);
//
///*-----------------Configura tread - Controle-----------------------------------*/
//tControle.add(&threadLerTeclado);
//tControle.add(&threadLerTemperatura);
//tControle.add(&threadLCD);
//tControle.add(&threadFornoTemperatura);
//
//
//
//
///*-----------------Cria caracteres Especiais e inicializa LCD-----------------------------------*/
//  lcd.begin(16, 2);
//  lcd.createChar(2, degC);
//  lcd.createChar(1, termometro);
//  lcd.createChar(3, relogio);
//  lcd.createChar(4, barra);
//  lcd.backlight();
//  lcd.clear();
///*-----------------Configurações Gerais-----------------------------------*/
//  beep(200, piezoPin);
//  myKeypad.setDebounceTime(10); // delay para  teclado
//  Serial.begin(9600);
//
//}
//
///***************************LOOP PRINCIPAL DO PROGRAMA*****************/
//void loop()
//{
//  /*-----------------Inicia Execução de Threads-----------------------------------*/
//  tControle.run();
//}
//
///***************************REALIZA A LEITURA DO TECLADO*****************/
//void lerTeclado() {
//  // faz a leitura do teclhado e trata dependendo do variável status menu.
//  //TELA_INICIAL,
//  //  MENU_PRINCIPAL,
//  //  TEMP_MAX, statusMenu status_menu = TELA_INICIAL;
//  //  TEMP_MIN
//  switch (status_menu) {
//  case TELA_INICIAL: {
//    char keypressed = myKeypad.getKey();
//    if (keypressed != NO_KEY)
//    {
//      if (keypressed=='#') {
//        status_menu = MENU_PRINCIPAL;
//        beep(200, piezoPin);
//      }
//    }
//  }
//             break;
//  case MENU_PRINCIPAL: {
//    char keypressed = myKeypad.getKey();
//    if (keypressed != NO_KEY)
//    {
//      ultimaTeclaPressionada = keypressed;
//      beep(200, piezoPin);
//      Serial.print("Tecla:");
//      Serial.println(keypressed);
//      executaMenu(keypressed);
//    }
//  }
//    break;
//
//  case TEMP_MAX: {
//    char keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY)  && (keyPressed != '*') && (keyPressed != 'A')
//      && (keyPressed != 'B') && (keyPressed != 'C') && (keyPressed != 'D')) {
//      if (contadorTemp <= 3) {
//        myTempMax.concat(keyPressed);
//        if (contadorTemp == 1) {
//          myTempMax.concat(".");
//        }
//        contadorTemp++;
//      
//      }
//      else {
//        if (keyPressed == '#') {
//          // repassa a tring para a variável double
//           mtempMax = myTempMax.toFloat();
//           contadorTemp = 0;
//          status_menu = TELA_INICIAL;
//        }
//      }
//      beep(200, piezoPin);
//      }
//    }
//           break;
//  case TEMP_MIN: {
//    char keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY) && (keyPressed != '*') && (keyPressed != 'A')
//      && (keyPressed != 'B') && (keyPressed != 'C') && (keyPressed != 'D')) {
//      if (contadorTemp <= 3) {
//        myTempMin.concat(keyPressed);
//        if (contadorTemp == 1) {
//          myTempMin.concat(".");
//        }
//        contadorTemp++;
//
//      }
//      else {
//        if (keyPressed == '#') {
//          // repassa a tring para a variável double
//          mtempMin = myTempMin.toFloat();
//          contadorTemp = 0;
//          status_menu = TELA_INICIAL;
//        }
//      }
//      beep(200, piezoPin);
//    }
//  }
//           break;
//  
//  case TEMP_VERIFICA: {
//    char keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY) && (keyPressed != '*') && (keyPressed != 'A')
//      && (keyPressed != 'B') && (keyPressed != 'C') && (keyPressed != 'D')) {
//      
//        if (keyPressed == '#') {
//          // repassa a tring para a variável double
//          mtempMin = myTempMin.toFloat();
//          contadorTemp = 0;
//          status_menu = TELA_INICIAL;
//          beep(200, piezoPin);
//        }
//      }
//    
//    }
//  
//           break;
//  //FORNO_LIGADO,
//  //FORNO_DESLIGADO
//  case FORNO_LIGADO: {
//    char keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY) && (keyPressed != '*') && (keyPressed != 'A')
//      && (keyPressed != 'B') && (keyPressed != 'C') && (keyPressed != 'D')) {
//
//      if (keyPressed == '#') {
//        // repassa a tring para a variável double
//        
//        status_menu = FORNO_DESLIGADO;
//        beep(200, piezoPin);
//      }
//    }
//
//  }
//
//            break;
//  case FORNO_DESLIGADO: {
//    char keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY) && (keyPressed != '*') && (keyPressed != 'A')
//      && (keyPressed != 'B') && (keyPressed != 'C') && (keyPressed != 'D')) {
//
//      if (keyPressed == '#') {
//        // repassa a tring para a variável double
//
//        status_menu = TELA_INICIAL;
//        beep(200, piezoPin);
//      }
//    }
//
//  }
//
//             break;
//           
//  }
//  
//}
//
///***************************TRATA A LEITURA DO TECLADO E NAVEGA PELO MENU*****************/
//void executaMenu(char tecla) {
//  menuSelect = true;
//  switch (tecla) {
//  case 'B': // Item Anterior
//    menuSystem.prev();
//    break;
//  case 'A': // Proximo Item
//    menuSystem.next();
//    break;
//  case 'D': // Anterior
//    menuSystem.back();
//    break;
//  case 'C': // reset MENU
//    menuSystem.reset();
//    break;
//  case '*': // Seleciona o item de menu 
//    menuSystem.select();
//    break;
//  case '#': // Sai do menu e volta para tela principal
//    status_menu = MENU_PRINCIPAL;
//    break;
//  default:
//    break;
//  }
//}
//  
///***************************FUNÇÃO - MOSTRA MENU*****************/
//void displayMenu() {
//  lcd.clear();
//  lcd.setCursor(0, 0);
//  // Display the menu
//  Menu const* cp_menu = menuSystem.get_current_menu();
//  //lcd.print("Current menu name: ");
//  lcd.print(cp_menu->get_name());
//  lcd.setCursor(0, 1);
//  lcd.print(cp_menu->get_selected()->get_name());
//}
//
///***************************FUNÇÃO - FAZ A LEITURA DO SENSOR DE TEMPERATURA*****************/
//void aferirTemperatura() {
//  temperaturaAtual=thermocouple.readCelsius();
//  Serial.print("Temperatura:");
//  Serial.println( temperaturaAtual);
//}
//
///***************************FUNÇÃO - Controla o Aquecer do forno*****************/
//
//void atualizaFornoTemperatura() {
//  if (status_menu == FORNO_LIGADO) {
//    controleTemperatura();
//  }
//
//}
//
///***************************FUNÇÃO - ATUALIZA A TELA LCD*****************/
//void atualizarTela() {
//  //TELA_INICIAL,
//  //  MENU_PRINCIPAL,
//  //  TEMP_MAX, statusMenu status_menu = TELA_INICIAL;
//  //  TEMP_MIN
//  switch (status_menu) {
//  case TELA_INICIAL: {
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.write((uint8_t)3);// relógio icone
//    lcd.setCursor(2, 0);
//    lcd.print(hour());
//    lcd.print(":");
//    lcd.print(minute());
//    lcd.print(":");
//    lcd.print(second());
//    digitalClockDisplay();
//    lcd.setCursor(0, 10);
//    lcd.write((uint8_t)4);// desenha icone
//    lcd.setCursor(1, 10);
//    lcd.write((uint8_t)4);// desenha icone
//    lcd.setCursor(0, 1);
//    lcd.write((uint8_t)1);// desenha icone
//    lcd.print(F(" "));
//    lcd.print(temperaturaAtual);
//    lcd.print(F(" "));
//    lcd.write((uint8_t)2);// desenha icone
//    lcd.setCursor(11, 1);
//    lcd.print("( # )");
//  
//  }
//             break;
//  case MENU_PRINCIPAL: {
//  
//    displayMenu();// Navega pelo Menu
//  }
//             break;
//  case TEMP_MAX: {
//    lcd.setCursor(0,0);
//    lcd.print("   Temp. Max  ");
//    lcd.setCursor(0, 1);
//    lcd.print("              ");
//    lcd.setCursor(4, 1);
//    lcd.print(myTempMax);
//    
//  
//  }
//             break;
//  case TEMP_MIN: {
//    lcd.setCursor(0, 0);
//    lcd.print("   Temp. Min  ");
//    lcd.setCursor(0, 1);
//    lcd.print("              ");
//    lcd.setCursor(4, 1);
//    lcd.print(myTempMin);
//  
//  
//  }
//             break;
//  case TEMP_VERIFICA: {
//    lcd.setCursor(0, 0);
//    lcd.print("  Min     Max  ");
//    lcd.setCursor(0, 1);
//    lcd.print("                 ");
//    lcd.setCursor(0, 1);
//    lcd.print(myTempMin +"   "+ myTempMax);
//    
//  }
//  break;
//  case FORNO_LIGADO: {
//    lcd.setCursor(0, 0);
//    lcd.print(temperaturaAtual);
//    lcd.setCursor(0, 1);
//    lcd.print("                 ");
//    lcd.setCursor(0, 1);
//    
//  lcd.print(mtempMin);
//  lcd.setCursor(8, 1);
//  lcd.print(mtempMax);
//  
//  }
//  break;
//    }
//  }
//
//
//
///***************************FUNÇÕES CALLBACK MENU*****************/
///*TELA_INICIAL, 
//  MENU_PRINCIPAL,
//  TEMP_MAX,
//  TEMP_MIN,
//  TEMP_VERIFICA,
//  FORNO_LIGADO,
//  FORNO_DESLIGADO
//*/
//void on_ativa_forno(MenuItem* p_menu_item)
//{
//  status_menu = FORNO_LIGADO;
//}
//void on_desliga_forno(MenuItem* p_menu_item)
//{
//  status_menu = FORNO_DESLIGADO;
//}
//
//
//void on_item1_selected(MenuItem* p_menu_item)
//{
//  lcd.setCursor(0, 1);
//  lcd.print("Item1 Selected  ");
//  delay(1500); 
//}
//
//void on_item2_selected(MenuItem* p_menu_item)
//{
//  lcd.setCursor(0, 1);
//  lcd.print("Item2 Selected  ");
//  delay(1500); 
//}
//
//void on_item3_selected(MenuItem* p_menu_item)
//{
//  lcd.setCursor(0, 1);
//  lcd.print("Item3 Selected  ");
//  delay(1500); 
//}
//
//
//void on_temp_min(MenuItem* p_menu_item) {
//  status_menu = TEMP_MIN;
//}
//
//void on_temp_max(MenuItem* p_menu_item) {
//   status_menu = TEMP_MAX;
//  
//  }
//
//void on_temp_verifica(MenuItem* p_menu_item) {
//  status_menu = TEMP_VERIFICA;
//
//}
//
//
//
//
///***************************FUNÇÃO - BEEP*****************/
//void beep(unsigned char delayms, int pino) {
//  //Ligando o buzzer com uma frequencia de 1500 hz.
//  tone(piezoPin, 1500);
//  delay(delayms);
//  //Desligando o buzzer.
//  noTone(piezoPin);
//  delay(delayms);
//
//}
//
//
///***************************FUNÇÃO - TESTA BEEP*****************/
//void on_Beep(MenuItem* p_menu_item) {
//  //beep(200, piezoPin);
//  setTemperatura();
//}
//
//
///***************************FUNÇÃO - RELOGIO*****************/
//void digitalClockDisplay(void)
//{
//  // digital clock display of the time
//  Serial.print(hour());
//  printDigits(minute());
//  printDigits(second());
//  Serial.print(' ');
//  Serial.print(day());
//  Serial.print(' ');
//  Serial.print(month());
//  Serial.print(' ');
//  Serial.print(year());
//  Serial.println();
//}
//
//
///***************************FUNÇÃO - UTILITARIAS*****************/
//void printDigits(int digits)
//{
//  // utility function for digital clock display: prints preceding colon and leading 0
//  Serial.print(':');
//  if (digits < 10)
//    Serial.print('0');
//  Serial.print(digits);
//}
//
//
///***************************FUNÇÃO - ENTRADA DE TEMPERATURA COM DOIS DÍGITOS DEPOIS DA VIRGULA*****************/
//
//void setTemperatura()
//{
//  //clear variables
//  char z = 0;
//  int tempInteira = 0;
//  int tempFracionaria = 0;
//  delay(10);
//  delay(5);
//  int i = 0;
//  while (i < 3)
//  {
//    char key = ultimaTeclaPressionada;
//    if (key)
//    {
//      tempMin[z] = key;
//      lcd.setCursor(0,0);
//      lcd.print(tempMin);
//      z++;
//      i++;
//    }
//  }
//  //char tempMin[4];
//  //char tempMax[4];
//  (sscanf(tempMin, "%02d%02d", &tempInteira, &tempFracionaria));
//  delay(50);
//}
//
///*
//
//void setmytime()
//{
//  //clear variables
//
//  char z = 0;
//  int Hour = 0;
//  int Min = 0;
//  int Sec = 0;
//  int Day = 0;
//  int Month = 0;
//  int Year = 0;
//  tmElements_t tm;
//  //LCD
//
//  delay(10);
//  delay(5);
//  int i = 0;
//  while (i < 10)
//  {
//    char key = keypad.getKey();
//    if (key)
//    {
//      settime[z] = key;
//      z++;
//      i++;
//    }
//  }
//
//  (sscanf(settime, "%02d%02d%02d%02d%02d", &Hour, &Min, &Day, &Month, &Year));
//  tm.Hour = Hour;
//  tm.Minute = Min;
//  tm.Second = Sec;
//  tm.Day = Day;
//  tm.Month = Month;
//
//  tm.Year = (Year + 30);
//  RTC.write(tm);
//  delay(50);
//}*/
//
//String readVal() {
//  String myString = "";
//  char keyPressed = myKeypad.getKey();
//  while (keyPressed != '#') {
//    keyPressed = myKeypad.getKey();
//    if ((keyPressed != NO_KEY) && (keyPressed != '#')) {
//      myString.concat(keyPressed);
//      lcd.print(keyPressed);
//      playTone();
//    }
//  }
//  return(myString);
//}
//
////Beeps on key presses
//void playTone() {
//  tone(piezoPin, 150, 10);
//}
//
//void ligarRele() {
//  digitalWrite(rele, LOW);
//}
//
//void desligarRele() {
//  digitalWrite(rele, HIGH);
//
//}
//
//void playAlarm() {
//  for (int thisNote = 150; thisNote < 1000; thisNote += 1)
//  {
//    tone(piezoPin, thisNote, 10);
//    delay(1);
//  }
//  for (int thisNote = 1000; thisNote > 150; thisNote -= 1)
//  {
//    tone(piezoPin, thisNote, 10);
//    delay(1);
//  }
//
//}
//
///******************************Controle do Rele******************************************/
//
//void controleTemperatura() {
//  Serial.println("Controle do Forno");
//  Serial.println(mtempMax);
//  Serial.println(mtempMin);
//  Serial.println(temperaturaAtual);
//  
//  if (mtempMax > mtempMin) {
//    if (temperaturaAtual > mtempMax) {
//      desligarRele();
//      Serial.println("Relê Desligado");
//    }
//    else if(temperaturaAtual < mtempMin){
//      ligarRele();
//      Serial.println("Relê Ligado");
//    }
//    else if ((temperaturaAtual > mtempMin) && (temperaturaAtual < mtempMax)) {
//      desligarRele();
//      Serial.println("Relê Desligado2");
//    }
//  }
//}
//
//
//

