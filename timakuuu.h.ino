#include <LiquidCrystal_I2C.h>
#include <Wire.h>

//#define Buzzer   6
//#define Display  7
//#define bMenu    A0  // Os pinos analógicos podem ser
//#define bChange  A1  // usados como digitais, bastando
//#define bUp      A2  // referenciá-los por A0, A1..
//#define bDown    A3

//#define bMenu0  90
//#define bChange0  91
//#define bUp0 92
//#define bDown0  93

//boolean aMenu, aChange, aUp, aDown;  // Grava o ultimo valor lidos nos botões.
//int variavel;  // variavel a ser alterada pelo menu

//boolean aMenu, aChange, aUp aDown;
//char state = 1;

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);

void setup(){
//
//  pinMode(13, OUTPUT);
//  pinMode(12,OUTPUT);
//  pinMode(11,OUTPUT);
//  pinMode(10,OUTPUT);
//  pinMode(9,OUTPUT);
//  pinMode(8,OUTPUT);
  pinMode(8,INPUT_PULLUP);
  pinMode(9,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);

  
   lcd.begin (20,4);
   lcd.setCursor(0,0);
  lcd.print("Sobrinhas V.1.0");
   delay(1500);
  //           screen0();
}

void screen0(){
  lcd.setCursor(0,0);
  lcd.print("1.Cozinhar");
  lcd.setCursor(0,1);
  lcd.print("2.Sugar");
  lcd.setCursor(0,2);
  lcd.print("3.Rotacionar");
  lcd.setCursor(0,3);
  lcd.print("4.Transferir");
}

void screen1(){

}

void setState(char index){
//     switch(index){
//       case 0:
//          screen0();
//          break;
//     }
//  
}

//char actionButton(){
//  if(aMenu!= digitalRead(bMenu)){
//    aMenu=!aMenu;
//    if(aMenu) 
//      return bMenu0;
//    else
//      return bMenu;
//  }else
//    if(aChange!=digitalRead(bChange)){
//      aChange=!aChange;
//      if(aChange)
//        return bChange0;
//      else
//        return bChange;  
//    }
//  
//}
 
void loop(){

 if (digitalRead(8) == LOW) { // Botão Pressionado;
    lcd.clear();    
    lcd.setCursor(0,0);
    lcd.print("Timakuuuu....");
  }
if (digitalRead(9) == LOW) { // Botão Pressionado;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Cabe no bolso....");
  }

if (digitalRead(10) == LOW) { // Botão Pressionado;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Xuxu");
  }
if (digitalRead(11) == LOW) { // Botão Pressionado;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Custoso...");
  }
if (digitalRead(12) == LOW) { // Botão Pressionado;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Xiiii");
  }
  
  
  //else {                       // Botão Não Pressionado
   // digitalWrite(8, LOW);     // Desliga led.
  //}

  
//  switch(state){
//    case 1:
//      switch (actionButton()){
//        case bUp:
//          lcd.clear();
//          setState(4);
//          break;
//        case bDown:
//          setState(2);
//        default:
//          setState(1); 
//      }
//      break;
//    case 2:
//      switch(actionButton()){
//        case bUp:
//          lcd.clear();
//          setState(1);
//          break;
//        case bDown:
//          lcd.clear();
//          setState(3);
//          break;
//        default:
//          setState(2);
//          break;
//      }
//      break;
//    case 3:
//      switch(actionButton()){
//        case bUp:
//           lcd.clear();
//           setState(2);
//           break;
//        case bDown:
//           lcd.clear();
//           setState(4);
//           break;
//        default:
//           setState(3);
//      }
//      break;
//    case 4:
//       switch(actionButton()){
//        case bUp:
//           lcd.clear();
//           setState(3);
//           break;
//        case bDown:
//           lcd.clear();
//           setState(1);
//           break;
//        default:
//           setState(4);
//       }
//  }
//  
//   if(change){
//     lcd.clear();
//     setState(
//     change = false;
//   }
}
