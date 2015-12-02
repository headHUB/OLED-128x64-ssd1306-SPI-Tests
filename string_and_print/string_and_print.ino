#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(10, 9, 12, 11); //sck=10, mosi=9, cs=12, a0=11 [, reset=nc]) (oledpin=arduinopin) 
int txt=0;
void drawstr(void);
int drawprint(int var1);

void setup() {
  // flip screen, if required
  // u8g.setRot180();
  
  // set SPI backup if required
  //u8g.setHardwareBackup(u8g_backup_avr_spi);

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
    drawprint(txt);
  } while( u8g.nextPage() );

  // rebuild the picture after some delay
  delay(1000);
  txt++;
}

void drawstr(void) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr( 0, 10, "Hello World!");
}

int drawprint(int var1) {
  // graphic commands to redraw the complete screen should be placed here  
  u8g.setFont(u8g_font_unifont);
  u8g.setPrintPos(0, 10); 
  // call procedure from base class, http://arduino.cc/en/Serial/Print
  u8g.print(var1);
}
