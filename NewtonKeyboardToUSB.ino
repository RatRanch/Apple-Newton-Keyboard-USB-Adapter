/* @file   NewtonKeyboardToUSB
|| @version .90
|| @author Jim Lombardo
|| @contact http://jimandnoreen.com
||
||  03/7/2017 - Initial release
||
|| @description
|| |    This sketch converts an Apple Newton serial keyboard to USB
|| |    It was tested with a Teensy 2.0 but should be easily adaptible to any
|| |    Arduino-compatible board that provides USB support, e.g., Due or Zero
|| | 
|| |    Connections:  Newton pin    Teensy pin
|| |                  2             VCC (+5V)
|| |                  8             7
|| |                  shield        GND
|| |  
|| |   From Tools, USB Type, you must select "Keyboard+Mouse+Joystick" prior to compiling
|| #
*/

#include <appleKeyboard.h>

// set this to the hardware serial port
#define HWSERIAL Serial1  //Teensy pin 7 (RX)  PCB label D2

void setup() {

  // Serial.begin(9600);
  HWSERIAL.begin(9600);
  Keyboard.begin();
}

void loop() {
  byte incomingByte;

  if (HWSERIAL.available() > 0) {
    incomingByte = HWSERIAL.read();


    // Serial.print("UART received: ");
    // Serial.println(incomingByte, HEX);

    switch (incomingByte) {

      //Key press mappings
      case keyPressed_ANSI_A:
        Keyboard.press('a');
        break;
      case keyPressed_ANSI_S:
        Keyboard.press('s');
        break;
      case keyPressed_ANSI_D:
        Keyboard.press('d');
        break;
      case keyPressed_ANSI_F:
        Keyboard.press('f');
        break;
      case keyPressed_ANSI_H:
        Keyboard.press('h');
        break;
      case keyPressed_ANSI_G:
        Keyboard.press('g');
        break;
      case keyPressed_ANSI_Z:
        Keyboard.press('z');
        break;
      case keyPressed_ANSI_X:
        Keyboard.press('x');
        break;
      case keyPressed_ANSI_C:
        Keyboard.press('c');
        break;
      case keyPressed_ANSI_V:
        Keyboard.press('v');
        break;
      case keyPressed_ANSI_B:
        Keyboard.press('b');
        break;
      case keyPressed_ANSI_Q:
        Keyboard.press('q');
        break;
      case keyPressed_ANSI_W:
        Keyboard.press('w');
        break;
      case keyPressed_ANSI_E:
        Keyboard.press('e');
        break;
      case keyPressed_ANSI_R:
        Keyboard.press('r');
        break;
      case keyPressed_ANSI_Y:
        Keyboard.press('y');
        break;
      case keyPressed_ANSI_T:
        Keyboard.press('t');
        break;
      case keyPressed_ANSI_1:
        Keyboard.press('1');
        break;
      case keyPressed_ANSI_2:
        Keyboard.press('2');
        break;
      case keyPressed_ANSI_3:
        Keyboard.press('3');
        break;
      case keyPressed_ANSI_4:
        Keyboard.press('4');
        break;
      case keyPressed_ANSI_6:
        Keyboard.press('6');
        break;
      case keyPressed_ANSI_5:
        Keyboard.press('5');
        break;
      case keyPressed_ANSI_Equal:
        Keyboard.press('=');
        break;
      case keyPressed_ANSI_9:
        Keyboard.press('9');
        break;
      case keyPressed_ANSI_7:
        Keyboard.press('7');
        break;
      case keyPressed_ANSI_Minus:
        Keyboard.press('-');
        break;
      case keyPressed_ANSI_8:
        Keyboard.press('8');
        break;
      case keyPressed_ANSI_0:
        Keyboard.press('0');
        break;
      case keyPressed_ANSI_RightBracket:
        Keyboard.press(']');
        break;
      case keyPressed_ANSI_O:
        Keyboard.press('o');
        break;
      case keyPressed_ANSI_U:
        Keyboard.press('u');
        break;
      case keyPressed_ANSI_LeftBracket:
        Keyboard.press('[');
        break;
      case keyPressed_ANSI_I:
        Keyboard.press('i');
        break;
      case keyPressed_ANSI_P:
        Keyboard.press('p');
        break;
      case keyPressed_ANSI_L:
        Keyboard.press('l');
        break;
      case keyPressed_ANSI_J:
        Keyboard.press('j');
        break;
      case keyPressed_ANSI_Quote:
        Keyboard.press('\'');
        break;
      case keyPressed_ANSI_K:
        Keyboard.press('k');
        break;
      case keyPressed_ANSI_Semicolon:
        Keyboard.press(';');
        break;
      case keyPressed_ANSI_Backslash:
        Keyboard.press('\\');
        break;
      case keyPressed_ANSI_Comma:
        Keyboard.press(',');
        break;
      case keyPressed_ANSI_Slash:
        Keyboard.press('/');
        break;
      case keyPressed_ANSI_N:
        Keyboard.press('n');
        break;
      case keyPressed_ANSI_M:
        Keyboard.press('m');
        break;
      case keyPressed_ANSI_Period:
        Keyboard.press('.');
        break;
      case keyPressed_ANSI_Grave:
        Keyboard.press('`');
        break;

      //Modifier keys, see https://www.arduino.cc/en/Reference/KeyboardModifiers
      case keyPressed_Return:
        Keyboard.press(KEY_RETURN);
        break;
      case keyPressed_Tab:
        Keyboard.press(KEY_TAB);
        break;
      case keyPressed_Space:
        Keyboard.press(' ');
        break;
      case keyPressed_Delete:
        Keyboard.press(KEY_BACKSPACE);
        break;
      case keyPressed_Escape:
        Keyboard.press(KEY_ESC);
        break;
      case keyPressed_Command:
        Keyboard.press(KEY_LEFT_GUI);
        break;
      case keyPressed_Shift:
        Keyboard.press(KEY_LEFT_SHIFT);
        break;
      case keyPressed_CapsLock:
        Keyboard.press(KEY_CAPS_LOCK);
        break;
      case keyPressed_Option:
        Keyboard.press(KEY_LEFT_ALT);
        break;
      case keyPressed_Control:
        Keyboard.press(KEY_LEFT_CTRL);
        break;
      case keyPressed_RightShift:
        Keyboard.press(KEY_RIGHT_SHIFT);
        break;
      case keyPressed_RightOption:
        Keyboard.press(KEY_RIGHT_GUI);
        break;
      case keyPressed_RightControl:
        Keyboard.press(KEY_RIGHT_CTRL);
        break;
      case keyPressed_LeftArrow:
        Keyboard.press(KEY_LEFT_ARROW);
        break;
      case keyPressed_RightArrow:
        Keyboard.press(KEY_RIGHT_ARROW);
        break;
      case keyPressed_DownArrow:
        Keyboard.press(KEY_DOWN_ARROW);
        break;
      case keyPressed_UpArrow:
        Keyboard.press(KEY_UP_ARROW);
        break;

      //Key release mappings
      case keyReleased_ANSI_A:
        Keyboard.release('a');
        break;
      case keyReleased_ANSI_S:
        Keyboard.release('s');
        break;
      case keyReleased_ANSI_D:
        Keyboard.release('d');
        break;
      case keyReleased_ANSI_F:
        Keyboard.release('f');
        break;
      case keyReleased_ANSI_H:
        Keyboard.release('h');
        break;
      case keyReleased_ANSI_G:
        Keyboard.release('g');
        break;
      case keyReleased_ANSI_Z:
        Keyboard.release('z');
        break;
      case keyReleased_ANSI_X:
        Keyboard.release('x');
        break;
      case keyReleased_ANSI_C:
        Keyboard.release('c');
        break;
      case keyReleased_ANSI_V:
        Keyboard.release('v');
        break;
      case keyReleased_ANSI_B:
        Keyboard.release('b');
        break;
      case keyReleased_ANSI_Q:
        Keyboard.release('q');
        break;
      case keyReleased_ANSI_W:
        Keyboard.release('w');
        break;
      case keyReleased_ANSI_E:
        Keyboard.release('e');
        break;
      case keyReleased_ANSI_R:
        Keyboard.release('r');
        break;
      case keyReleased_ANSI_Y:
        Keyboard.release('y');
        break;
      case keyReleased_ANSI_T:
        Keyboard.release('t');
        break;
      case keyReleased_ANSI_1:
        Keyboard.release('1');
        break;
      case keyReleased_ANSI_2:
        Keyboard.release('2');
        break;
      case keyReleased_ANSI_3:
        Keyboard.release('3');
        break;
      case keyReleased_ANSI_4:
        Keyboard.release('4');
        break;
      case keyReleased_ANSI_6:
        Keyboard.release('6');
        break;
      case keyReleased_ANSI_5:
        Keyboard.release('5');
        break;
      case keyReleased_ANSI_Equal:
        Keyboard.release('=');
        break;
      case keyReleased_ANSI_9:
        Keyboard.release('9');
        break;
      case keyReleased_ANSI_7:
        Keyboard.release('7');
        break;
      case keyReleased_ANSI_Minus:
        Keyboard.release('-');
        break;
      case keyReleased_ANSI_8:
        Keyboard.release('8');
        break;
      case keyReleased_ANSI_0:
        Keyboard.release('0');
        break;
      case keyReleased_ANSI_RightBracket:
        Keyboard.release(']');
        break;
      case keyReleased_ANSI_O:
        Keyboard.release('o');
        break;
      case keyReleased_ANSI_U:
        Keyboard.release('u');
        break;
      case keyReleased_ANSI_LeftBracket:
        Keyboard.release('[');
        break;
      case keyReleased_ANSI_I:
        Keyboard.release('i');
        break;
      case keyReleased_ANSI_P:
        Keyboard.release('p');
        break;
      case keyReleased_ANSI_L:
        Keyboard.release('l');
        break;
      case keyReleased_ANSI_J:
        Keyboard.release('j');
        break;
      case keyReleased_ANSI_Quote:
        Keyboard.release('\'');
        break;
      case keyReleased_ANSI_K:
        Keyboard.release('k');
        break;
      case keyReleased_ANSI_Semicolon:
        Keyboard.release(';');
        break;
      case keyReleased_ANSI_Backslash:
        Keyboard.release('\\');
        break;
      case keyReleased_ANSI_Comma:
        Keyboard.release(',');
        break;
      case keyReleased_ANSI_Slash:
        Keyboard.release('/');
        break;
      case keyReleased_ANSI_N:
        Keyboard.release('n');
        break;
      case keyReleased_ANSI_M:
        Keyboard.release('m');
        break;
      case keyReleased_ANSI_Period:
        Keyboard.release('.');
        break;
      case keyReleased_ANSI_Grave:
        Keyboard.release('`');
        break;
      case keyReleased_Return:
        Keyboard.release(KEY_RETURN);
        break;
      case keyReleased_Tab:
        Keyboard.release(KEY_TAB);
        break;
      case keyReleased_Space:
        Keyboard.release(' ');
        break;
      case keyReleased_Delete:
        Keyboard.release(KEY_BACKSPACE);
        break;
      case keyReleased_Escape:
        Keyboard.release(KEY_ESC);
        break;
      case keyReleased_Command:
        Keyboard.release(KEY_LEFT_GUI);
        break;
      case keyReleased_Shift:
        Keyboard.release(KEY_LEFT_SHIFT);
        break;
      case keyReleased_CapsLock:
        Keyboard.release(KEY_CAPS_LOCK);
        break;
      case keyReleased_Option:
        Keyboard.release(KEY_LEFT_ALT);
        break;
      case keyReleased_Control:
        Keyboard.release(KEY_LEFT_CTRL);
        break;
      case keyReleased_RightShift:
        Keyboard.release(KEY_RIGHT_SHIFT);
        break;
      case keyReleased_RightOption:
        Keyboard.release(KEY_RIGHT_ALT);
        break;
      case keyReleased_RightControl:
        Keyboard.release(KEY_RIGHT_CTRL);
        break;
      case keyReleased_LeftArrow:
        Keyboard.release(KEY_LEFT_ARROW);
        break;
      case keyReleased_RightArrow:
        Keyboard.release(KEY_RIGHT_ARROW);
        break;
      case keyReleased_DownArrow:
        Keyboard.release(KEY_DOWN_ARROW);
        break;
      case keyReleased_UpArrow:
        Keyboard.release(KEY_UP_ARROW);
        break;
      default:
        // We received an unexpected byte.  Ignore it.
        break;
    }
  }
}
