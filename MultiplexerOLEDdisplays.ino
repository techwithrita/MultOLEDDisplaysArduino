/**
 *  TCA9548A I2c Multiplexer Sketch for 4 OLED display's
 *  Original sketch by E.Heideveld 14-12-2018
 *  Edits by TechWithRita
 *  >>>To add more OLED displays, just add another tcaselect(#) 
 *  call in the setup function & to the loop
 *  >>no need to adjust any wiring, the I2C protocol along with the libraries takes care of all that! It's really that simple! :)
 ***LAST UPDATED: 11/25/2023 -TechWithRita
 */
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_Address 0x3C
Adafruit_SSD1306 oled(1);
#include "Wire.h"
#define TCAADDR 0x70
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

//Adafruit's logo, here for later use if desired
static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

void tcaselect(uint8_t i) {
  if (i > 7) return;
  Wire.beginTransmission(TCAADDR);
  Wire.write(1 << i);
  Wire.endTransmission(); 
}

void setup()
{
oled.begin(SSD1306_SWITCHCAPVCC, OLED_Address);
Wire.begin();
 //Clear all the displays
 tcaselect(0);
  oled.begin();
  //oled.clearDisplay();
  oled.display();
  tcaselect(1);
  oled.begin();
  oled.clearDisplay();
  oled.display();
  tcaselect(2);
  oled.begin();
  oled.clearDisplay();
  oled.display();
  tcaselect(3);
  oled.begin();
  oled.clearDisplay();
  oled.display();

}
//draw triangle function
 void testdrawtriangle(void) {
    oled.clearDisplay();
  
    for(int16_t i=0; i<max(oled.width(),oled.height())/2; i+=5) {
      oled.drawTriangle(
        oled.width()/2  , oled.height()/2-i,
        oled.width()/2-i, oled.height()/2+i,
        oled.width()/2+i, oled.height()/2+i, SSD1306_WHITE);
      oled.display();
      delay(1);
    }
  
    delay(2000);
  }
  //fill triangle function
  void testfilltriangle(void) {
  oled.clearDisplay();

  for(int16_t i=max(oled.width(),oled.height())/2; i>0; i-=5) {
    // The INVERSE color is used so triangles alternate white/black
    oled.fillTriangle(
      oled.width()/2  , oled.height()/2-i,
      oled.width()/2-i, oled.height()/2+i,
      oled.width()/2+i, oled.height()/2+i, SSD1306_INVERSE);
    oled.display();
    delay(1);
  }

  delay(2000);
}

//draws Adafruit's  logo feat. above, if code calls function, star will show... else, not applied
void testdrawbitmap(void) {
  oled.clearDisplay();

  oled.drawBitmap(
    (oled.width()  - LOGO_WIDTH ) / 2,
    (oled.height() - LOGO_HEIGHT) / 2,
    logo_bmp, LOGO_WIDTH, LOGO_HEIGHT, 1);
  oled.display();
}

/*
* END OF FUNCTIONS
* START OF LOOP
*/

void loop() 
{

  tcaselect(0); // Text to Oled display 1
  oled.begin();
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.setTextSize(1.5);
  oled.println("Hello YouTube!");
  oled.setCursor(24,12);
  oled.println("Welcome to \n TechWithRita! \n");
  oled.display();
  
  tcaselect(1);//Text to Oled display 2
  oled.begin();
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(24,0);
  //oled.println("Let's build \n cool stuff \n together!");
  oled.setTextSize(1);
  oled.display();
  // Clear the buffer
  oled.clearDisplay();
  testdrawtriangle(); //draw triangles (outlines)
   // Invert and restore display, pausing in-between
  oled.invertDisplay(true);
  delay(1000);
  oled.invertDisplay(false);
  delay(1000);
  testfilltriangle();  // Draw triangles (filled)
  delay(2500);
  oled.clearDisplay();
  oled.setTextColor(WHITE);
  oled.setCursor(0,0);
  oled.setTextSize(2);
  oled.println("LIKE &");
  //oled.setCursor(26,15);
  oled.println("SUBSCRIBE!");
  oled.display();
  delay(100000); // Wait --- sec.
  oled.setTextSize(1);
}