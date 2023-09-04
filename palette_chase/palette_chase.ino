#include <FastLED.h>

#define DATA_PIN    3
//#define CLK_PIN   4

#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    24 //64
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  100

DEFINE_GRADIENT_PALETTE( heatmap_gp ) {
0  , 255, 0  , 0  ,   //red
60 , 240, 240, 0  ,   //yellow
140 , 10 , 250, 10 ,  //greeish
220, 70 ,   0, 160,   //purple
240, 255, 0  , 0  ,   //red
255, 255, 0  , 0  };  //red

void setup() {
    delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}


void loop() {
  CRGBPalette16 myPal = heatmap_gp;
  for(int i = 0; i < 240; i++) {
    
    uint8_t heatindex = (i);
    leds[i % NUM_LEDS] = ColorFromPalette( myPal, heatindex); // normal palette access
    FastLED.show();
    FastLED.delay(60);

    for(int k = 0; k < NUM_LEDS; k++) {
      leds[k].fadeToBlackBy( 110 );
    }
  }

}
