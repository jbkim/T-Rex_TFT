#include <Adafruit_GFX.h>
#include "WROVER_KIT_LCD.h"
#include "DinoGame.h"

#define USE_NOINTERNET

#ifdef USE_NOINTERNET
#include "no_internet.h"
#endif

WROVER_KIT_LCD tft;
DinoGame game(tft);

void setup(void) {
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);
  game.newGame();
  pinMode(37, INPUT_PULLUP);
  pinMode(39, INPUT_PULLUP);
  #ifdef USE_NOINTERNET
  tft.drawBitmap(0, 131, 320, 109, no_internet);
  #endif
}

void loop() {
  char c = Serial.read();
  if(c >= '0' && c <= '9') game.setSpeedModifier(c - '0');
  if(!digitalRead(37)) game.jump();
  else{
    if(!digitalRead(39)) game.duck();
    else game.stand();  
  }
  while(game.isGameOver()){
    if(!digitalRead(37)){
      game.newGame();
      #ifdef USE_NOINTERNET
      tft.drawBitmap(0, 131, 320, 109, no_internet);
      #endif   
      break;
    }
  }
  game.loop();
}
