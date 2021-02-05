////Evolution (a spore de-make for the Arduboy)
////Noble Song Watson
////January 26th, 2021
#include <Arduboy2.h>
Arduboy2 arduboy;
#include "vars.h"
#include "func.h"
#include "cellfunc.h"
#include "creaturefunc.h"

void setup() {
  arduboy.begin();
  arduboy.setFrameRate(45);
  
  north=1;
}

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
  arduboy.clear();
  switch (gamestate) {
    case TITLE:
      titleScreen();
      if (arduboy.justPressed(A_BUTTON)) {
        arduboy.clear();
        initCells();
        arduboy.initRandomSeed();
        gamestate = CELL;
      }
  break;

case CELL:
  cellStage();
  break;

case CELL_LOSE:
  resetCellStage();
  break;

case CREATURE_TITLE:
  creatureTitle();
  break;

case CREATURE:
  creatureStage();
  break;

case CREATURE_LOSE:
  break;
case TRIBAL:
  tribalStage();
  break;

case INDUSTRIAL:
  industryStage();
  break;

case SPACE:
  spaceStage();
  break;

case WIN:
  winScreen();
  break;
}
arduboy.display();
}
