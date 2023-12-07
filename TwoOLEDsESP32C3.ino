//Original code by 'Mark's Bench' (Mark) <<minor tweaked edits by TechWithRita>>
//LEONARDO - TWO I2C OLEDS
// Using two displays: the 128x64 SH1106 OLED (0x3C/0x78), and the 128x32 SSD1306
// (0x3D/0x7A).
// The 128x64 display will be DISPA, the 128x32 display will be DISPB.
// This program is a bit of a pig, using 60% of the program storage space and 95% of
// the dynamic memory.
// Sometimes when running this program, the Leonardo doesn't respond to serial port
// data/uploads. If that happens, start the compile/upload, immediately ground the
// RESET pin very briefly, and it should work.
// **THIS PROGRAM IS FREE TO USE AND MODIFY AS YOU SEE FIT**

// Need this to use the I2C bus. I2C pins on Leonardo are broken
// out but are also 2 (SDA) and 3 (SCL).
#include <Wire.h> 

// Need this to make displays do things and stuff.
#include <U8g2lib.h> 

// Select proper constructor (driver) for this particular 128x64 OLED display and
// call it DISPA. See https://github.com/olikraus/u8g2/wiki/u8g2setupcpp for other
// drivers. There are lots of different OLED board configurations out there!
U8G2_SSD1306_128X64_NONAME_F_HW_I2C DISPA(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);
U8G2_SSD1306_128X64_NONAME_F_HW_I2C DISPB(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);                                                                              
// Select constructor for this particular 128x32 OLED display, call it DISPB.                                                                               
//U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C DISPB(U8G2_R0, U8X8_PIN_NONE);

// Set aliases for the I2C pins. They're broken out on the Leonardo but I'm using
// the numbered pins so it's seamless with other boards like the Pro Micro.
#define SDA 4  
#define SCL 5


void setup() {
  // put your setup code here, to run once:

  // Setting the pins that control the displays to all outputs. There are no inputs
  // on these two OLED displays to worry about - others may be different!
  pinMode(SDA, OUTPUT);  
  pinMode(SCL, OUTPUT);


  // Set I2C bus speed on Arduino and both displays. This may not be necessary
  // but I put it in anyway - one less thing to troubleshoot if things don't work.
  Wire.setClock(100000);
  DISPA.setBusClock(100000);
  DISPB.setBusClock(100000);

  // Some devices say they're 0x78/0x7A, but others may say they're 0x3C/0x3D. It's
  // like that because the address is 7 bits but some places (u8g2 included) pad it
  // out to 8 bits. Adding a 0 on the end multiplies the value by 2.
  // Most of the small OLED displays out there seem to be set to 0x3C(0x78). Some
  // can be changed, but not all of them.
  // See https://www.arduino.cc/en/Reference/Wire for details.
  DISPA.setI2CAddress(0x7A); //or 0x3C OR 0x3D
  DISPB.setI2CAddress(0x78);
  
  // Fire up the displays and get them ready to accept data.
  // Remember, DISPA is the 128x64px OLED, DISPB is the 128x32px OLED.                           
  DISPA.begin();
  DISPB.begin();

  // Select a font to use on DISPA and DISPB. They don't have to be the same, and
  // you can change them throughout the program, too. 
  // Check https://github.com/olikraus/u8g2/wiki for others, there are LOTS.
  DISPA.setFont(u8g2_font_logisoso30_tf );
  DISPB.setFont(u8g2_font_logisoso16_tf ); //smaller font to show difference

  // Let's put some writing on DISPA. Make sure the display buffer is clear before
  // writing or drawing anything.
  DISPA.clearBuffer();

  // Move the starting position of what will be written/drawn next to x=0, y=32.
  // As shown in the above picture, coordinates start at 0,0 at the top left.
  // If you want to properly display text, make sure you set the y-value to at least
  // as large as how many pixels tall your font is.
  // If your display shows nothing, make sure you have set the y-value or everything
  // will end up being drawn beyond the edges of the display...
  
  // This just puts Howdy! in the selected font in the buffer. Nothing gets written
  // to the screen yet. You could move the cursor position again and write more text
  // to the buffer or draw some shapes if you wanted. At this point you're just
  // setting bits that will turn on the associated pixels.
  // See https://github.com/olikraus/u8g2/wiki/u8g2reference to find out how to
  // draw shapes and lines or even set individual pixels.

  // Now, do the same thing for DISPB.
  DISPB.clearBuffer(); 

}

void loop() {
    //Display #1 or A (DISPA)
    DISPA.clearBuffer();
    DISPA.setCursor(0, 31);
    DISPA.print("Display");
    DISPA.setCursor(40, 63);
    DISPA.print("A");
    DISPA.sendBuffer();
    
    //Display #2 or B (DISPB)
    DISPB.clearBuffer();
    DISPB.setCursor(0, 31);
    DISPB.print("Display");
    DISPB.setCursor(40, 63);
    DISPB.print("B");
    DISPB.sendBuffer();
}
