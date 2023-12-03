# The Only File(s) You Need to Quickly Get Started With OLED Displays and a Multiplexer!
This file contains code that claims to be for Arduino, however, this code is uniform in that it functions for other boards in addition to Arduino. I.E, this code file can run ESP32 boards, Seeed Studio XIAO ESP32-C3 boards, and Arduino Nano!\

I've tested this code recently and it's functioning as it should. If you have any questions or would like to view an example of this working, watch this [video tutorial here](https://youtu.be/MO6hbQcX8fE?si=GFrEsCN-FYgjShPb). 

There are no specific wiring changes that need to be made in the code (based on the SDA/SCL I2C protocol), the file should upload to whichever board and run, assuming you have the inlude files already downloaded in your library.

Arduino IDE (.ino files) for multiple OLED displays. Easily understood, simple C++/C code script for your many displays using I2C protocol. 

# If You Don't Use A Multiplexer, or Want Code For Mult. OLEDs Without It:
The "TwoOLEDsESP32C3.ino" file is for you! It allows you to use two OLED displays without a multiplexer (so long as each display is given a different address physically by resoldering the addressing resistor / soldering jumpers on the back of the OLED display) i.e. 0x78 and 0x7A
