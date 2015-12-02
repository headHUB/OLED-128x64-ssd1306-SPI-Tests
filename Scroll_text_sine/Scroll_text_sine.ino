/**
Written by Nikolaj Simonsen - december 2015

Pure nostalgia from the old demo scene days, this is a simple scroll
text generator for a OLED 128x64 display with a SSD1306 controller 
The y position of the text is calculated from a sine wave while the 
X position is scrolled from right to left
Based on: 
https://www.sparkfun.com/tutorials/329
https://code.google.com/p/u8glib/wiki/bdf2u8g
https://github.com/olikraus/u8glib
**/

#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11); //sck=10, mosi=9, cs=12, a0=11 [, reset=nc]) (oledpin=arduinopin) 
int xPos=0; //used for xPosition
float yPos; //used for yPosition
char message[]="Sine controlling Y position while scrolling.... NEAT!"; // text written on display

/***** function prototypes *****/
int drawprint(char var1[], int x, int y); //prints an array to display (nameofarray,xposition,yposition) 
int drawprint2(float var1, int x, int y); //prints a float to display (nameoffloat,xposition,yposition)
// void drawstr(char text[], int x, int y);

void setup() {
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  // u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }
}

void loop() {

for (float in = 0; in < 6.283; in = in + 0.1) //Stepping along the wave, with input values from 0 to 6.283 (2 * pi)
                                                 //to increase number of points add 0.01 to in instead  
{
  yPos = sin(in)*20+44; //yPos = sin(in) * range + offset 
                          //to get to a number that ranges from 0 to n 
                          //use 1/2 n for both the range and offset
  xPos-=3; //Determines x position and x speed with a looping integer. 
    // picture loop
    u8g.firstPage();  
    do {
      drawprint(message,xPos,yPos); //scroll text - string is message
      drawprint2(yPos,103,7); //print value of yPos,xoffset,yoffset
      drawprint2(xPos,0,7); //print value of xPos,xoffset,yoffset
    } 
    while( u8g.nextPage() );
}  
}

/***** functions *****/

//
int drawprint(char var1[], int x, int y) {
  // graphic commands to redraw the complete screen should be placed here  
  // u8g.setFont(u8g_font_unifont); //uncomment to change font
  u8g.setFont(u8g_font_lucasfont_alternate);
  u8g.setPrintPos(x, y); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print(var1);
}  

int drawprint2(float var1, int x, int y) {
  // graphic commands to redraw the complete screen should be placed here  
  // u8g.setFont(u8g_font_unifont);
  // u8g.setFont(u8g_font_unifont);
  u8g.setFont(u8g_font_lucasfont_alternate);
  u8g.setPrintPos(x, y); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print(var1);
} 
/*void drawstr(char text[],int x,int y) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  int w = u8g.getStrWidth(text);
  u8g.drawStr(x-(w/2), y, text);
}
*/
