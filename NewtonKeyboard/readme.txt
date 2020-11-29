Apple Newton Keyboard library for Arduino including serial to USB conversion
By Jim Lombardo - http://jimandnoreen.com
This software has been placed in the public domain.  Attribution requested.

The file applekeyboard.h has keyboard scan code definitions for the Newton Keyboard.
There is a sketch in the examples folder that converts the serial keypress codes 
to USB HID events, so that the Newton keyboard will behave like a generic USB
keyboard.

This was tested with a Teensy 2.0 but should be easily adaptible to any
Arduino-compatible board that provides USB support, e.g., Due or Zero.


    Connections:  Newton pin    Teensy pin
                  2             VCC (+5V)
                  8             7
                  shield        GND
  
From Tools, USB Type, you must select "Keyboard+Mouse+Joystick" prior to compiling

Please copy to your libraries folder or install from the ZIP file by selecting
Sketch-->Include Library-->Add .ZIP Library

Tested with Arduino IDE version 1.8.1.