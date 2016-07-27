//#include <Time.h>
//#include <TimeLib.h>
#include "Wire.h"
#include <LiquidCrystal_I2C.h>

#define DS1307_I2C_ADDRESS 0x68

LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3, POSITIVE);
 
byte bcdToDec(byte val){
  return ( (val/16*10) + (val%16) );
}

byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}
 
void getDate(byte *second,byte *minute,byte *hour,byte *dayOfWeek,byte *dayOfMonth,byte *month,byte *year){
  Wire.beginTransmission(DS1307_I2C_ADDRESS);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(DS1307_I2C_ADDRESS, 7);
  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}

void setDate(
byte second,        // 0-59
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
  Wire.begin();
  lcd.begin (20,4);
  //setTime(8,29,0,1,2,10,14); // set time to Saturday 8:29:00am Jan 1 2011
   //setTime(8,10,12,1,1,16);
//byte second,        // 0-59
//byte minute,        // 0-59
//byte hour,          // 1-23
//byte dayOfWeek,     // 1-7 1=Mon, 7=Sun
//byte dayOfMonth,    // 1-28/29/30/31
//byte month,         // 1-12
//byte year           // 0-99
   //setDate(0,33,22,3,26,7,16);
}
 
void loop(){
  byte second, minute, hour, dayOfWeek, dayOfMonth, month, year;
  String s, m, d, mth, h;
  getDate(&second, &minute, &hour, &dayOfWeek, &dayOfMonth, &month, &year);
  
  if (second < 10) { 
     s = "0" + String(second); 
  } else { 
    s = String(second); 
  }
  
  if (minute < 10) {
     m = "0" + String(minute); 
  } else {
    m = String(minute); 
  }
  
  h = String(hour);
  
  if (dayOfMonth < 10) {
    d = "0" + String(dayOfMonth); 
  } else { 
    d = String(dayOfMonth); 
  }
  
  if (month < 10) { 
     mth = "0" + String(month); 
  } else {
     mth = String(month); 
  }
   
  char* days[] = { "NA", "Seg", "Ter", "Qua", "Qui", "Sex", "Sab", "Dom" };
   
  lcd.clear();
  lcd.setCursor(12,0);
  lcd.print(h + ":" + m + ":" + s);
  lcd.setCursor(0,1);
  lcd.print(String(days[dayOfWeek]) + " " + d + "-" + mth + "-20" + year);
  delay(1000);
}
