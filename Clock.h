#include <Wire.h>              //RW I2C
#define CLOCK_ADDRESS 0x68

/* Adjust date in clock device
 * 
 * second,        // 0-59
 * minute,        // 0-59
 * hour,          // 1-23
 * dayOfWeek,     // 1-7 1=Mon, 7=Sun
 * dayOfMonth,    // 1-28/29/30/31
 * month,         // 1-12
 * year           // 0-99
 */
void writeDate(byte second, byte minute, byte hour, byte dayOfWeek, byte dayOfMonth, byte month, byte year){
  Wire.beginTransmission(CLOCK_ADDRES);
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

/*
 * Read date in clock device
 * 
 * second,        // 0-59
 * minute,        // 0-59
 * hour,          // 1-23
 * dayOfWeek,     // 1-7 1=Mon, 7=Sun
 * dayOfMonth,    // 1-28/29/30/31
 * month,         // 1-12
 * year           // 0-99
 */
void readDate(byte *second, byte *minute, byte *hour, byte *dayOfWeek, byte *dayOfMonth, byte *month, byte *year){
  Wire.beginTransmission(CLOCK_ADDRES);
  Wire.write(0);
  Wire.endTransmission();
  Wire.requestFrom(CLOCK_ADDRES, 7);
  *second     = bcdToDec(Wire.read() & 0x7f);
  *minute     = bcdToDec(Wire.read());
  *hour       = bcdToDec(Wire.read() & 0x3f);
  *dayOfWeek  = bcdToDec(Wire.read());
  *dayOfMonth = bcdToDec(Wire.read());
  *month      = bcdToDec(Wire.read());
  *year       = bcdToDec(Wire.read());
}

/*
 * Convert Byte to Decimal
 */
byte bcdToDec(byte val){
  return ( (val/16*10) + (val%16) );
}

/*
 * Convert Decimal to Byte
 */
byte decToBcd(byte val){
  return ( (val/10*16) + (val%10) );
}

/*
 * Return date in format dd/mm/yyyy
 */
String getDate(byte day, byte month, byte year){
	String d, m, y; 
	d = String(day);
	if(dayOfMonth < 10) d = "0" + String(day);
	m = String(month);
	if(month < 10) m = "0" + String(month); 	
	y = "20"+ String(year); 
    return d+"/"+m+"/"+y;
}

/*
 * Return time in format hh:mm:ss 
 *
 */
String getTime(byte second, byte minute, byte hour){
	String h, m, s; 
	h = String(hour);
	if(hour < 10) d = "0" + String(hour); 
	m = String(minute);
	if(minute < 10) m = "0" + String(minute); 	
	s = String(secound);
	if(secound < 10) s = "0" + String(secound); 	
    return h+":"+ m +":"+ s;
}