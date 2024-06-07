#include "Arduino.h" 

struct Color {
  int R, G, B;
};

class Size2D
{
public:
    int width , height;
    int SizeWH(){
        return width * height;
    }
    
};