#include <DS1307RTC.h>         //Clock
#include <LiquidCrystal_I2C.h> //LCD
#include <Wire.h>              //RW I2C

#define bLeft    8
#define bUp      9
#define bRight  10
#define bDown   11
#define bSelect 12
#define CLOCK_ADDRESS 0x68

//byte smiley[8] = {
//  B00000,
//  B10001,
//  B00000,
//  B00000,
//  B10001,
//  B01110,
//  B00000,
//};

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}

/*
 * secound 0-59
 * minute  0-59
 * 
 */
void setDate(
byte second,        // 
byte minute,        // 0-59
byte hour,          // 1-23
byte dayOfWeek,     // 1-7 1=Mon, 7=Sun
byte dayOfMonth,    // 1-28/29/30/31
byte month,         // 1-12
byte year           // 0-99
){
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.write(decToBcd(second));
  Wire.write(decToBcd(minute));
  Wire.write(decToBcd(hour));
  Wire.write(decToBcd(dayOfWeek));
  Wire.write(decToBcd(dayOfMonth));
  Wire.write(decToBcd(month));
  Wire.write(decToBcd(year));
  Wire.endTransmission();
}



void setup(){
  pinMode(bLeft,  INPUT_PULLUP);
  pinMode(bUp,    INPUT_PULLUP);
  pinMode(bRight, INPUT_PULLUP);
  pinMode(bDown,  INPUT_PULLUP);
  pinMode(bSelect,INPUT_PULLUP);



  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  Wire.begin();
 
  // Change these values to what you want to set your clock to.
  // It is best to add 30 seconds to a minute to allow time for your computer to compile and upload the current time.
  // Only run this script once, as running it again will overwrite the time set in the RTC chip!
  // Hours are in 24 hour format
  // Day of week starts with Monday = 1 up to Sunday = 7
  // Year is in YY format, so only use the last 2 digits of the year
  //
  // Once you have run the program, the LED on pin 13 will flash to say it has finished, DO NOT UNPLUG OR RESET.
  // Simply follow the tutorial and upload the LCD code to avoid overwriting the correct time with this time again.
  //
  second = 0;
  minute = 40;
  hour = 21;
  dayOfWeek = 3;
  dayOfMonth = 25;
  month = 6;
  year = 14;
  setDateDs1307(second, minute, hour, dayOfWeek, dayOfMonth, month, year);
  //*/



  
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("CookBeer V1.0");
  lcd.createChar(0, smiley);
  delay(1500);
  screen0();
}




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

void screen0(){
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print(char(0));
  //lcd.print("1.Cozinhar");

  //lcd.setCursor(0,1);

  //lcd.setCursor(0,2);
  //lcd.print("3.Rotacionar");
  //lcd.setCursor(0,3);
  //lcd.print("4.Transferir");
}

void screen1(){

}

void setState(char index){
     switch(index){
       case 0:
          screen0();
          break;
     }
  
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
  }
  
//   if(change){
//     lcd.clear();
//     setState(
//     change = false;
//   }
//}
