#include "SSD1306.h"
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>

#include "Ultrasonic.h"
Ultrasonic ultrasonic(D1,D0); //ultrasonic(Trigger Pin, Echo Pin)

#define OLED_RESET 4
#define O_SDA D3
#define O_CLK D5
SSD1306 display(0x3C, O_SDA, O_CLK);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

//#if (SSD1306_LCDHEIGHT != 64)
//#error("Height incorrect, please fix Adafruit_SSD1306.h!");
//#endif


void setup() {
  Serial.begin(115200);

  display.init();

  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
  display.clear();  

}

void loop() {
  int distance = ping();
  write(distance);
  delay(100);
}


int ping(void){
  return(ultrasonic.Ranging(INC)); //INC or CM
}

void write(int words){
  Serial.println(words);
  display.clear();
  display.drawString(0, 0, "distance: ");
  display.drawString(0, 15, String(words));
  display.display();
  return;
}

