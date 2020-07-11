#include <Font.h>
#include <Wire.h>
#include <OLED.h>
OLED oled;

void setup() {
  oled.begin();
  oled.clear();
}

void loop() {
  oled.setCursor(0, 0);
  oled.print("Hello ");
  oled.print(12.34f, 1); // prints float 2-digit precision: 12.34
}
