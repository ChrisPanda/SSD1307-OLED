#include "OLED.h"

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

void OLED::ftoa(float f, char *ret, int precision) {
  int i=0;
  itoa(f, ret, 10);
  if (precision > 0) {
    long rest = (f - floor(f)) * pow(precision, 10);
    while(ret[i]!='\0') i++;
    ret[i] = '.';
    ret[i+1]='\0';
    char nc[10];
    ltoa(rest, nc, 10);
    strcat(ret, nc);
  }
}


void OLED::init(void) {
  Wire.begin();
  sendCmd(0xae);		//display off
  sendCmd(0xa1);		//seg re-map 127->0
  sendCmd(0xaf);		//display on
  delay(10);
  clear();
  //delay(500);
}

void OLED::begin(byte cols, byte rows) {
  init();
}

OLED::OLED()
{
}

void OLED::clear(void) {
  unsigned char i,k;
  for(k=0;k<2;k++) {	
    setCursor(k,0);    
      for(i=0;i<128;i++) {//clear all COL
        sendChar(0);
      }
    } 
}
//===================================
void OLED::sendChar(char data) {
  Wire.beginTransmission(OLED_ADDRESS); // 
  Wire.write(0x40);//data mode
  Wire.write(data);
  Wire.endTransmission();    // stop transmitting
}
//===================================

void OLED::setCursor(unsigned char row,unsigned char line) {
  unsigned char realrow=row;
  sendCmd(0xb1+line);
  sendCmd(0x00 +(8*realrow&0x0f));
  sendCmd(0x10 +((8*realrow>>4)&0x07));
}

void OLED::sendCmd(unsigned char state) {
  Wire.beginTransmission(OLED_ADDRESS); //
  Wire.write(0x80);//command mode
  Wire.write(state);
  Wire.endTransmission();    // stop transmitting
}

void OLED::print(char *string) {
  char i=0;
  //OLED_setXY(0,0);    
  while(*string) {
    for(i=0;i<8;i++) {
      sendChar(pgm_read_byte_near(OLED_Font+(*string-0x20)*8+i));
    }
    *string++;
  }
}

void OLED::print(int number) {
	char ret[6];
	itoa(number, ret, 10);
  print(ret);
}
void OLED::print(long number) {
  print((float)number, 0);
}
void OLED::print(unsigned long number) {
  print((float)number, 0);
}

void OLED::print(float number) {
	print(number, 2);
}

void OLED::print(float f, int precision) {
  char ret[10];
  ftoa(f, ret, precision);
  print(ret);
}