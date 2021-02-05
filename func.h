#pragma once
#include "vars.h"
#include "arrays.h"

void titleScreen() {
  arduboy.pollButtons();
  Sprites::drawOverwrite(0, 16, EV, 0);
  Sprites::drawOverwrite(32, 16, galaxyO, 0);
  Sprites::drawOverwrite(64, 16, LUT, 0);
  Sprites::drawOverwrite(96, 16, ION, 0);

}




/////start tribal func
void tribalStage() {

}

/////end tribal func

/////start industry func
void industryStage() {

}
////end industry func

////start space func
void spaceStage() {

}


////end space func
void winScreen() {

}
