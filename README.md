# Apple-Newton-Keyboard-USB-Adapter
A USB adapter for the Apple Newton Keyboard

http://http://jimandnoreen.com/?p=259

Back in the pre-smartphone days, the Apple Newton was the first device in the PDA category.  Newtons were only sold for five years between 1993 and 1998, when Steve Jobs pulled the plug on the program.  Although Apple frequently took a ribbing for problems with the Newton’s handwriting recognition feature, its main problem with achieving market dominance was Newton’s high cost.  Although it beat the wildly successful Palm Pilot to market, Newton could not compete on price.

One of Newton’s accessories was a very compact keyboard (just a hair over 10 inches wide).  I had one rattling around in my spare parts bin and it was the perfect size to use with the SunFounder Display and Raspberry Pi one-piece computer that I recently assembled.

Only one problem, no way to plug it in.  The Newton keyboard outputs a serial data stream and the RasPi (like most other modern computers) requires a USB keyboard.  Further complicating matters, the Newton keyboard does not produce ASCII characters.  Like the legacy IBM XT and AT keyboards, the Newt keyboard outputs a unique scan code for each key.  One code is sent when the key is pressed and another gets sent when the key is released.

I was surprised to find that nobody currently sells a pre-built adapter to do the serial to USB conversion.  (Such adapters exist for IBM keyboards, but are not pin or code compatible with the Newt keyboard).  The only homebrew solution I could locate was from a guy in Japan who posted this video but little else in the way of details.

I was able to piece together the following information from various sources:

    The Newton keyboard runs at 5V (technically 4.5 volts) and produces a 5V TTL compatible signal
    Baud rate is 9600-N-8-1
    We can connect it to a microcontroller using three pins:  pin 2 – +5V, pin 8 – signal, shield – ground
    The key scan codes are similar but not identical to those use by IBM AT keyboards

To make the Newt keyboard impersonate a USB keyboard, I would need to remap the serial data to USB.  This job calls for a small, cheap, 5V tolerant microcontroller having both serial and USB interfaces.

The Teensy 2.0 board is perfect for this purpose.  It can impersonate all kinds of HID devices like mice, keyboards, joysticks, etc. and it is compatible with the Arduino IDE, which comes with a great keyboard library that can do all the heavy lifting.

If you want to build your own adapter and are familiar with building Arduino projects, feel free to grab the sketch here.  Pinouts are in the readme file and you can install the Teensy (or MC board of your choice) within the Newton keyboard or in an external enclosure.

If you’d like step-by-step directions for my build, please continue reading.
Bill of Materials

    Teensy 2.0 microcontroller development board (there are several Teensy versions;  make sure you use one that operates at 5 volts).
    An 8-pin mini-DIN M/F or F/F cable like this one from Cables to Go.  We will be cutting off the female end to connect to the Newton keyboard.  Any similar legacy Apple serial cable would work
    A suitable enclosure for the Teensy.  Note that there is plenty of room inside the Newton keyboard case.  If you don’t mind opening it up, you can mount the Teensy board inside.
    A short USB A to mini B cable to connect your computer to the Teensy board

Hardware Assembly

    Cut off the female end of your serial cable leaving at least a couple inches of wire.
    If you are using the Cables to Go cable, solder the brown  wire to VCC (+5 Volts), the purple wire to D2, and the uninsulated shield to GND (ground) as shown above.  Use a piece of shrink wrap tube or tape to cover the shield wire so it doesn’t short anything on the Teensy.

    If you are using a different mini-DIN connector, use a multimeter to find the wires attached to pins 2, 8 and the connector outer case.  Pin 2 gets soldered to VCC and pin 8 gets soldered to D2.  Looking at the female connector that you will plug the keyboard into, pin 8 is on the upper left.  Here is my sketch of the connector that will surely end up hanging in the Louvre:

    Connect the keyboard to the connector you just soldered on and connect a USB cable to the Teensy.  Mount it either inside the keyboard case or in a suitable enclosure.

Programming the Teensy

    Install the latest Arduino IDE, if necessary.  It can be downloaded here.
    Download and install Teensyduino, which is an add-on for the Arduino software that adds Teensy support to it.
    Download the Apple Newton Keyboard to USB Converter library  (Mac users:  please Ctrl-click and choose Save As to prevent the ZIP file from automatically unpacking)
    Launch Arduino and install from the ZIP file by selecting
    Sketch–>Include Library–>Add .ZIP Library
    Open the Sketch named NewtonKeyboardToUSB, which is located in the folder Arduino/libraries/newtonKeyboard/examples
    Upload the sketch to the Teensy.  If this is the first time you are uploading a sketch from the Arduino IDE, you will need to
    Your computer should immediately recognize that a new keyboard has been plugged in

Further improvements

There are lots of digital inputs and outputs available on the Teensy.  It might be nice to use one of the outputs to drive an LED that indicates Caps Lock state.  Or perhaps it would be useful to assign some inputs to keyboard macros.
