# oled brick library
Arduino library for OLED displays with the SSD1307 chip.
So far only tested with seeedstudios [Electronic brick OLED 96x16 display](http://www.seeedstudio.com/depot/Electronic-brick-OLED-96x16-Display-With-Free-Cable-p-704.html "Electronic brick OLED 96x16").

Perhaps it works also with bigger displays incorporation the SSD1306.

The API is mostly compatible with the standard LCD-library commands, apart from some minor differences.

When initializing no pin-number are needed because this works via I2C and has a fixed address.

    #include "OLED.h"
    
    OLED oled;
    oled.begin();
    
    oled.clear();
    oled.setCursor(0, 0);
    oled.print("Hello World");
    oled.print(12.3456f, 2); // prints float 2-digit precision: 12.34
     

In case you get an error saying that Wire.h wasn't found just include the wire.h before OLED.h.

    #include <Wire.h>
    #include "OLED.h" 