#include <FastLED.h>

FASTLED_USING_NAMESPACE


#define DATA_PIN    3
#define CLK_PIN   9
#define LED_TYPE     WS2812 //APA102
#define COLOR_ORDER GRB
#define NUM_LEDS    24 //64
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  100

void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  //FastLED.addLeds<LED_TYPE,DATA_PIN,CLK_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}

void loop() {
        int val = analogRead(A1);
        int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS+1);

        // First, clear the existing led values
        FastLED.clear();
        for(int led = 0; led <= (numLedsToLight); led++) { 
            leds[led-1].setRGB((255/led),(led*10),(30)); 
        }
        FastLED.show();
        Serial.println(numLedsToLight);
    }
