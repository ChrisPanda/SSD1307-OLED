#ifndef OLED_h 
#define OLED_h

#include <Wire.h>
#include "Font.h"

#define OLED_ADDRESS  0x3c

typedef unsigned char byte;

class OLED {
public:
	OLED();
	void init(void);
	void begin();
	void clear(void);
	void setCursor(unsigned char row, unsigned char line);
	void print(const char *string);
	void print(int number);
	void print(unsigned int number);
	void print(long number);
	void print(unsigned long number);
	void print(float number);
	void print(float number, int precision);
private:
	void sendCmd(unsigned char state);
	void sendChar(char data);
	void ftoa(float f, char *ret, int precision);
};

extern TwoWire Wire;

#endif
