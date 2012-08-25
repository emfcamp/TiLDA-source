#include "lights.h"

int right = 7;
int left = 4;

int blue = 5;
int green = 6;
int red = 10;

Lights::Lights() {
  pinMode(right, OUTPUT);
  pinMode(left, OUTPUT);    
  pinMode(blue, OUTPUT);    
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);    
}
