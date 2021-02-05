#pragma once
#include "arrays.h"
#include "vars.h"

int creaturex =WIDTH/2-6;
int creaturey =HEIGHT/2-6;

/////start creature stage functions
void drawZoid() {
Sprites::drawOverwrite(creaturex, creaturey, zoid, currentFrame);
}
void animateZ() {
  if (arduboy.everyXFrames(10)) {
    if (currentFrame < 3) {
      ++currentFrame;
    }
    else {
      currentFrame = firstFrame;
    }
  }
}
void drawMap() {}
void drawCreatures() {}
void creatureBrains() {}
void drawHealth() {}
void creatureControls() {}
void mate() {}
void matingMenu() {}



void creatureStage() {
  ///draw player
  drawZoid();
  animateZ();
  ///draw campfire
  ///draw map (with trail)
  /// draw enemies
  ///attack player if near enemy campfire
  ///drop upgrades if all of a species is killed
  /// draw enemy campfires
  //draw player health
  ///respawn at campfire if health reaches zero
  ///call to reproduce, draw player species just offscreen
  ///if player touches player species, enter upgrade (reproduction) menu
  /// if player reaches the new nest, move to next stage
}

void creatureTitle() {
  arduboy.setCursor(20, 0);
  arduboy.print("Creature stage: \nMigrate to a new Nest!");
  arduboy.pollButtons();
  if (arduboy.justPressed(A_BUTTON)) {
    arduboy.clear();
    gamestate = CREATURE;
  }
}






////end creature stage functions
