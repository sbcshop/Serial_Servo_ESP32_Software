// Demo code to test onboard TFT Display
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789
#include <SPI.h>

// define Display SPI pins 
#define TFT_CS        10
#define TFT_RST       14
#define TFT_DC        13
#define TFT_MOSI      11
#define TFT_CLK       12
#define BACKLIGHT     9

// configure SPI and create instance for display 
Adafruit_ST7789 tft = Adafruit_ST7789(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

void displayText(String msg, uint16_t txtcolor = ST77XX_WHITE, uint8_t x=10, uint8_t y=10, uint8_t txtsize = 3, uint8_t rotation = 1){
  tft.setRotation(rotation);
  tft.setCursor(x, y);
  tft.setTextSize(txtsize);
  tft.setTextColor(txtcolor);
  tft.println(msg);
}

void setup(void) {
  pinMode(BACKLIGHT, OUTPUT);
  digitalWrite(BACKLIGHT, HIGH);
  
  tft.init(135, 240);  // Init display controlled by ST7789 and pass resolution of display to init function
  
  tft.fillScreen(ST77XX_BLACK);
  tft.setTextWrap(false);
  tft.setRotation(1);
  displayText("Hello...", ST77XX_WHITE, 20, 30); // displayText(msg, color, x, y, size, rotation)

  tft.fillScreen(ST77XX_BLACK);
  displayText("Serial Servo ", ST77XX_YELLOW, 10, 30);
  displayText("ESP32", ST77XX_YELLOW, 10, 70);
  delay(500);
  
  testtriangles();
  delay(500);
  
  tft.fillScreen(ST77XX_BLACK);
  testdrawcircles(10, ST77XX_RED);
  delay(1000);

  tft.fillScreen(ST77XX_BLACK);
  displayText("Hello World", ST77XX_GREEN, 10, 30, 2, 3); // displayText(msg, color, x, y, size, rotation)
  delay(500);

  tft.fillScreen(ST77XX_BLACK);
  displayText("Bye..!", ST77XX_WHITE, 10, 30, 4); // displayText(msg, color, x, y, size, rotation)
  
}

void loop() {
  delay(50);
}

void testdrawcircles(uint8_t radius, uint16_t color) {
  for (int16_t x=0; x < tft.width()+radius; x+=radius*2) {
    for (int16_t y=0; y < tft.height()+radius; y+=radius*2) {
      tft.drawCircle(x, y, radius, color);
    }
  }
}

void testtriangles() {
  tft.fillScreen(ST77XX_BLACK);
  uint16_t color = 0xF800;
  int t;
  int w = tft.width()/2;
  int x = tft.height()-1;
  int y = 0;
  int z = tft.width();
  for(t = 0 ; t <= 15; t++) {
    tft.drawTriangle(w, y, y, x, z, x, color);
    x-=4;
    y+=4;
    z-=4;
    color+=100;
  }
}
