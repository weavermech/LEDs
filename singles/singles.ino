#include <FastLED.h>

#define DATA_PIN    3
//#define CLK_PIN   4

#define LED_TYPE    WS2812
#define COLOR_ORDER GRB
#define NUM_LEDS    24 //64
CRGB leds[NUM_LEDS];

#define BRIGHTNESS          96
#define FRAMES_PER_SECOND  120

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))
const int customArray[] = {12,24,36,48};
const int customArraySize = ARRAY_SIZE(customArray);


void setup() {
  delay(3000); // 3 second delay for recovery
  
  // tell FastLED about the LED strip configuration
  FastLED.addLeds<LED_TYPE,DATA_PIN,COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // set master brightness control
  FastLED.setBrightness(BRIGHTNESS);
}


void loop()
{

    //Set the RGB values separately, 255 is max, 0 is off
    leds[0].r = 200;
    leds[0].g = 200;
    leds[0].b = 200;

    //Some different values
    leds[4].r = 255;
    leds[4].g = 68;
    leds[4].b = 221;

    //Can set with Hexidecimal values FF=255 44=68 DD=55
    leds[6] = 0xFF44DD;


    //Can set values in one line, note 
    leds[8].setRGB(255, 0, 0);
    leds[9].setRGB(0, 255, 0);
    leds[10].setRGB(0, 0, 255);
    leds[11].setRGB(255, 165, 0);


    //set RGB from a standard named web/HTML color code
    leds[15] = CRGB::Red;
    leds[16] = CRGB::Green;
    leds[17] = CRGB::Blue;
    leds[20] = CRGB::HotPink;

    leds[23] = leds[16];


    //Skip to FastLED.show();




    //Ignore this for now
    int val = analogRead(A1);
        int numLedsToLight = map(val, 0, 1023, 0, NUM_LEDS+1);

        // First, clear the existing led values
        //FastLED.clear();
        for(int led = numLedsToLight; led < NUM_LEDS; led++) { 
            leds[led] = CRGB::Black; 
        }
     
        Serial.println(numLedsToLight);


    //Show what we've assigned, and the loop ends.
    FastLED.show();

}

