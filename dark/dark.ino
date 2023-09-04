#include <FastLED.h>

#define DATA_PIN    3
//#define CLK_PIN   4

#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    12
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
  
  //One Shot to set to black
  for(int i = 0; i < NUM_LEDS-1; i++) { 
    leds[i] = CRGB::Black; 
    leds[i+1] = CRGB::Black;
    FastLED.show();
  }
}
 
 
void loop() 
{
  
}
