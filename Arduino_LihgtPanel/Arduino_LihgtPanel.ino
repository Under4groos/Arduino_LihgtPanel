#include <LightlibNeoPixel.h>
#include <Adafruit_NeoPixel.h>

 
int LED_COUNT = 13 * 9;

#define LED_PIN 4

Size2D SizeWindow {13,9};
Adafruit_NeoPixel strip = Adafruit_NeoPixel(SizeWindow.SizeWH(), LED_PIN, NEO_GRB + NEO_KHZ800);
Color Data[13][9];
int opacity = 130;

void setup() {
 



  int count = 0;
  for (int x = 0; x < SizeWindow.width; x++) {
    for (int y = 0; y < SizeWindow.height; y++) {
      Data[x][y] = Color{ 0, 0, 0 };
    }
  }
  strip.begin();
  strip.clear();
  strip.show();
  Data[12][3] = Color{ 33, 255, 0 };
  // for (int y = 0; y < 9; y++){
  //   Data[y][y] = Color{ 255, 0, 0 };
  // }
  // Data[13][2] = Color{ 33, 255, 0 };
   Data[12][3] = Color{ random(11, 255),  random(11, 255),  random(11, 255) };
}




Color rgb;
int count_l = 0;
int line = 0;
int linex_ = 0;
void loop() {


  
  for (int y = 0; y < SizeWindow.height; y++) {

    for (int x = 0; x < SizeWindow.width; x++) {
      linex_ = (12 - x);
      rgb = Data[x][y];
      if(y % 2 == 1){
        strip.setPixelColor(13 * y + linex_, strip.Color(rgb.R / opacity, rgb.G / opacity, rgb.B / opacity));
      }else{
        strip.setPixelColor(count_l, strip.Color(rgb.R / opacity, rgb.G / opacity, rgb.B / opacity));
      }
        
      count_l++;
      
      // delay(1);
      // strip.show();
    }
  }




  if (count_l > LED_COUNT) {
    count_l = 0;
    //strip.clear();
  }

  strip.show();
}
