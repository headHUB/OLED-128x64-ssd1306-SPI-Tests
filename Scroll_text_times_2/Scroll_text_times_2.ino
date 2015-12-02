#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11); //sck=10, mosi=9, cs=12, a0=11 [, reset=nc]) (oledpin=arduinopin) 
int txt=0;
int xPos=0;
int xPos2=0;
int xPos3=0;
int xPos4=0;
char message[]="this is a text written by me";
char message2[]="Waoow new line and new colour!!";
char message3[]="This makes no sense, wrong way";
char message4[]=":-)  ;-)  :-(  o_O";
void drawstr(char text[], int x, int y);
int drawprint(int var1, int x, int y);

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
  // picture loop
  u8g.firstPage();  
  do {
    drawprint(message,xPos,10);
    drawprint(message2,xPos2,27);
    drawprint(message3,xPos3,44);
    drawprint(message4,xPos4,61);
  } while( u8g.nextPage() );

if(xPos < 128){
    // if it's too slow, you could increment y by a greater number
    xPos--;  }
if(xPos2 < 128){
    // if it's too slow, you could increment y by a greater number
    xPos2-=2;  }
if(xPos3 >= 0){
    // if it's too slow, you could increment y by a greater number
    xPos3+=3;  }
if(xPos4 < 128){
    // if it's too slow, you could increment y by a greater number
    xPos4-=5;  }  
}
  // rebuild the picture after some delay
//  delay(50);
//  txt++;


/*void drawstr(char text[],int x,int y) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  int w = u8g.getStrWidth(text);
  u8g.drawStr(x-(w/2), y, text);
}
*/
int drawprint(char var1[], int x, int y) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(x, y); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print(var1);
  
}
