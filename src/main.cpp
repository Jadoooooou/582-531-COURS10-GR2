#include <Arduino.h>
#include <FastLED.h>
#include <MicroOscSlip.h>
MicroOscSlip<128> monOsc(&Serial);

#define BROCHE_ATOM_PIXEL 27

//CRGB keyPixel;
CRGB atomPixel;

//demarrage
bool demarrage = true; 


void setup() {

  // NE JAMAIS OUBLIER !!!
  Serial.begin(115200);

  // Initialiser FastLED pour contrôler le pixel RGB du M5Atom
  FastLED.addLeds<WS2812, BROCHE_ATOM_PIXEL , GRB>(&atomPixel, 1); 
  atomPixel = CRGB(255,255,255); // BLANC

}

void loop() {

  if (demarrage == true) {
    atomPixel = CRGB(255,0,0); // ROUGE
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    atomPixel = CRGB(255,255,0); // JAUNE
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    atomPixel = CRGB(0,255,0); // VERT
    FastLED.show();
    delay(1000); // PAUSE 1 SECONDE
    demarrage = false;
  } else {
    atomPixel = CRGB(0,0,0);
    FastLED.show(); 
  }
  
  
}