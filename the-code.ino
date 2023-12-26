#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> 
#endif
#define LED_PIN    2
#define LED_COUNT 24
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
int k;
int val;

void setup()
{
Serial.begin(9600);
#if defined(__AVR_ATtiny85__) && (F_CPU == 16000000)
  clock_prescale_set(clock_div_1);
#endif
  strip.begin();           
  strip.show();            
  strip.setBrightness(100); 
}

void loop()
{
  if (Serial.available())
  {
   val = Serial.read();
   
       if (val == 'r')//ROUGE
       {
        colorWipe(strip.Color(255, 0, 0), 100);    
       }
       if (val == 'v')//VERT
       {
        colorWipe(strip.Color(0, 255, 0), 100);    
       }
        if (val == 'b')//BLEU
       {
        colorWipe(strip.Color(0, 0, 255), 100);    
       }
        if (val == 'b')//BLANC
       {
        colorWipe(strip.Color(255, 255, 255), 100); 
       }
        if (val == 'j')//JAUNE
       {
        colorWipe(strip.Color(255, 255, 0), 100); 
       }
        if (val == 'm')//MAGENTA
       {
        colorWipe(strip.Color(255, 0, 255), 100); 
       }
        if (val == 'c')//CYAN
       {
        colorWipe(strip.Color(0, 255, 255), 100); 
       }
        if (val == 'p')//VIOLET
       {
        colorWipe(strip.Color(238, 130, 238), 100); 
       }
        if (val == 'o')//OFF
       {
        colorWipe(strip.Color(0, 0, 0), 100); 
       }
  }  
}
void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);         
    strip.show();                          
    delay(wait);                           
  }
}