#pragma once
#include "vars.h"
#include "arrays.h"

////cells[].x stage functions
Cells cells[7] ={
  {0, 0, cell, cell},
  {random(0, 512), random(0, 512), cell, cell},
  {random(0, 512), random(0, 512), cell, cell},
  {random(0, 512), random(0, 512), cell, cell},
  {random(0, 512), random(0, 512), cell, cell},

  {random(0, 512), random(0, 512), cell, cell},
  {random(0, 512), random(0, 512), cell, cell},
};
void initCells() {
  plantx = 0;
  planty = 0;
  plant1x = 54;
  plant1y = 76;
  plant2x = 14;
  plant2y = 93;
  plant3x = 126;
  plant3y = 100;
  plant4x = 220;
  plant4y = 34;
  plant5x = 210;
  plant5y = 176;
}
void resetCellStage() {
  arduboy.clear();
  arduboy.setCursor(5, HEIGHT / 2 - 12);
  arduboy.print("All things Great \n");
  arduboy.setCursor(8, HEIGHT / 2);
  arduboy.print("return to\n");
  arduboy.setCursor(5, HEIGHT / 2 + 12);
  arduboy.print("Primal Simplicity.\n");
  arduboy.pollButtons();
  if (arduboy.justPressed(A_BUTTON)) {
    HP = 3;
    plant0 = true;
    plant1 = true;
    plant2 = true;
    plant3 = true;
    plant4 = true;
    plant5 = true;
    plant6 = true;
    plant7 = true;
    plant8 = true;
    plant9 = true;
    plant10 = true;
    plant11 = true;
    gamestate = TITLE;
    cameraxoffset = 255;
    camerayoffset = 255;
  }
}

void animate() {
  if (arduboy.everyXFrames(10)) {
    if (currentFrame < 1) {
      ++currentFrame;
    }
    else {
      currentFrame = firstFrame;
    }
  }
}
void drawPlants() {

  if (plant0 == true) {

    Sprites::drawOverwrite(plantx - cameraxoffset, planty - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant1 == true) {

    Sprites::drawOverwrite(plant1x - cameraxoffset, plant1y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant2 == true) {

    Sprites::drawOverwrite(plant2x - cameraxoffset, plant2y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant3 == true) {

    Sprites::drawOverwrite(plant3x - cameraxoffset, plant3y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant4 == true) {


    Sprites::drawOverwrite(plant4x - cameraxoffset, plant4y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant5 == true) {


    Sprites::drawOverwrite(plant5x - cameraxoffset, plant5y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant6 == true) {

    Sprites::drawOverwrite(plant6x - cameraxoffset, plant6y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant7 == true) {
    Sprites::drawOverwrite(plant7x - cameraxoffset, plant7y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant8 == true) {
    Sprites::drawOverwrite(plant8x - cameraxoffset, plant8y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant9 == true) {
    Sprites::drawOverwrite(plant9x - cameraxoffset, plant9y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant10 == true) {
    Sprites::drawOverwrite(plant10x - cameraxoffset, plant10y - camerayoffset, plantmaterial, currentFrame);
  }
  if (plant11 == true) {
    Sprites::drawOverwrite(plant11x - cameraxoffset, plant11y - camerayoffset, plantmaterial, currentFrame);
  }

}

void driftPlant0() {
  if (plantx < 512 && planty < 512) {
    plantx += 0.04;
    planty += 0.03;

  }
}



void drawCells() {
  Sprites::drawSelfMasked(cells[0].x - cameraxoffset, cells[0].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[1].x - cameraxoffset, cells[1].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[2].x - cameraxoffset, cells[2].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[3].x - cameraxoffset, cells[3].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[4].x - cameraxoffset, cells[4].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[5].x - cameraxoffset, cells[5].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[6].x - cameraxoffset, cells[6].y - camerayoffset, cell, currentFrame);
  Sprites::drawSelfMasked(cells[7].x - cameraxoffset, cells[7].y - camerayoffset, cell, currentFrame);

}
void cellsBrain() {
  for (int i=0; i < 8; i++) {
    if (cells[i].x > cameraxoffset + WIDTH / 2 - 2) {
      cells[i].x -= 0.3;
    }
    else if (cells[i].x != cameraxoffset) {
      cells[i].x += 0.3;
    }

    if (cells[i].y > camerayoffset + HEIGHT / 2 - 2) {
      cells[i].y -= 0.3;
    }
    else if (cells[i].y != camerayoffset) {
      cells[i].y += 0.3;
    }
  }
}
void drawPlayerCellEast() {
  Sprites::drawSelfMasked (playercellx, playercelly, amoebaTailE, currentFrame);
}
void drawPlayerCellNorth() {
  Sprites::drawSelfMasked (playercellx, playercelly, amoebaTailN, currentFrame);
}
void drawPlayerCellSouth() {
  Sprites::drawSelfMasked (playercellx, playercelly, amoebaTailS, currentFrame);
}
void drawPlayerCellWest() {
  Sprites::drawSelfMasked (playercellx, playercelly, amoebaTailW, currentFrame);
}

void drawPlayer() {
  if (west == 1) {
    drawPlayerCellWest();
  }
  if (east == 1) {
    drawPlayerCellEast();
  }
  if (south == 1) {
    drawPlayerCellSouth();
  }
  if (north == 1) {
    drawPlayerCellNorth();
  }
}
void drawCellBorders() {
  arduboy.drawLine(255 - WIDTH / 2 - 2, 255 - HEIGHT / 2 - 2, -25 - WIDTH / -2, -25 - HEIGHT / -2, WHITE);
}
void cellControls() {
  arduboy.pollButtons();
  if (arduboy.pressed(UP_BUTTON) && camerayoffset > 0) {
    north = 1;
    south = 0;
    west = 0;
    east = 0;
    camerayoffset--;
  }
  if (arduboy.pressed(DOWN_BUTTON) && camerayoffset < 512) {
    north = 0;
    south = 1;
    west = 0;
    east = 0;
    camerayoffset++;
  }
  if (arduboy.pressed(LEFT_BUTTON) && cameraxoffset > 0) {
    north = 0;
    south = 0;
    west = 1;
    east = 0;
    cameraxoffset--;
  }
  if (arduboy.pressed(RIGHT_BUTTON) && cameraxoffset < 512) {
    north = 0;
    south = 0;
    west = 0;
    east = 1;
    cameraxoffset++;
  }


}


void playerLife() {
  ///draw three hearts
  Rect player_point = Rect{playercellx, playercelly, 5, 5};
  Rect cell0box = Rect{cells[0].x - cameraxoffset, cells[0].y - camerayoffset, 7, 7};
  Rect cell1box = Rect{cells[1].x - cameraxoffset, cells[1].y - camerayoffset, 7, 7};
  Rect cell2box = Rect{cells[2].x - cameraxoffset, cells[2].y - camerayoffset, 7, 7};
  Rect cell3box = Rect{cells[3].x - cameraxoffset, cells[3].y - camerayoffset, 7, 7};
  Rect cell4box = Rect{cells[4].x - cameraxoffset, cells[4].y - camerayoffset, 7, 7};
  Rect cell5box = Rect{cells[5].x - cameraxoffset, cells[5].y - camerayoffset, 7, 7};
  Rect cell6box = Rect{cells[6].x - cameraxoffset, cells[6].y - camerayoffset, 7, 7};
  Rect plant0box = Rect{plantx - cameraxoffset, planty - camerayoffset, 4, 4};
  Rect plant1box = Rect{plant1x - cameraxoffset, plant1y - camerayoffset, 4, 4};
  Rect plant2box = Rect{plant2x - cameraxoffset, plant2y - camerayoffset, 4, 4};
  Rect plant3box = Rect{plant3x - cameraxoffset, plant3y - camerayoffset, 4, 4};
  Rect plant4box = Rect{plant4x - cameraxoffset, plant4y - camerayoffset, 4, 4};
  Rect plant5box = Rect{plant5x - cameraxoffset, plant5y - camerayoffset, 4, 4};
  Rect plant6box = Rect{plant6x - cameraxoffset, plant6y - camerayoffset, 4, 4};
  Rect plant7box = Rect{plant7x - cameraxoffset, plant7y - camerayoffset, 4, 4};
  Rect plant8box = Rect{plant8x - cameraxoffset, plant8y - camerayoffset, 4, 4};
  Rect plant9box = Rect{plant9x - cameraxoffset, plant9y - camerayoffset, 4, 4};
  Rect plant10box = Rect{plant10x - cameraxoffset, plant10y - camerayoffset, 4, 4};
  Rect plant11box = Rect{plant11x - cameraxoffset, plant11y - camerayoffset, 4, 4};
  player_point.x = playercellx;
  player_point.y = playercelly;

  if (HP == 11) {
    gamestate = CREATURE_TITLE;
  }
  else if (HP == 10) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
    Sprites::drawOverwrite(30, 0, heart, 0);
    Sprites::drawOverwrite(36, 0, heart, 0);
    Sprites::drawOverwrite(42, 0, heart, 0);
    Sprites::drawOverwrite(48, 0, heart, 0);
    Sprites::drawOverwrite(54, 0, heart, 0);
  }
  else if (HP == 9) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
    Sprites::drawOverwrite(30, 0, heart, 0);
    Sprites::drawOverwrite(36, 0, heart, 0);
    Sprites::drawOverwrite(42, 0, heart, 0);
    Sprites::drawOverwrite(48, 0, heart, 0);
  }
  else if (HP == 8) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
    Sprites::drawOverwrite(30, 0, heart, 0);
    Sprites::drawOverwrite(36, 0, heart, 0);
    Sprites::drawOverwrite(42, 0, heart, 0);
  }
  else if (HP == 7) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
    Sprites::drawOverwrite(30, 0, heart, 0);
    Sprites::drawOverwrite(36, 0, heart, 0);
  }
  else if (HP == 6) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
    Sprites::drawOverwrite(30, 0, heart, 0);
  }
  else if (HP == 5) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
    Sprites::drawOverwrite(24, 0, heart, 0);
  }
  else if (HP == 4) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
    Sprites::drawOverwrite(18, 0, heart, 0);
  }
  else if (HP == 3) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
    Sprites::drawOverwrite(12, 0, heart, 0);
  }
  else if (HP == 2) {
    Sprites::drawOverwrite(0, 0, heart, 0);
    Sprites::drawOverwrite(6, 0, heart, 0);
  }
  else if (HP == 1) {
    Sprites::drawOverwrite(0, 0, heart, 0);
  }
  ///if cell collides with player, lose a life, knock back
  else if (HP == 0) {
    gamestate = CELL_LOSE;
  }
  if (arduboy.collide(player_point, cell0box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell1box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell2box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell3box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell4box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell5box) || arduboy.everyXFrames(10) && arduboy.collide(player_point, cell6box)) {
    --HP;
    cameraxoffset -= 10;
  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant0box)) {
    plant0 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.everyXFrames(10) && arduboy.collide(player_point, plant1box)) {
    plant1 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant2box)) {
    plant2 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant3box)) {
    plant3 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant4box)) {
    plant4 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant5box)) {
    plant5 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant6box)) {
    plant6 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant7box)) {
    plant7 = false;
    HP += 1;
  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant8box)) {
    plant8 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant9box)) {
    plant9 = false;
    HP += 1;

  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant10box)) {
    plant10 = false;
    HP += 1;
  }
  if (arduboy.everyXFrames(10) && arduboy.collide(player_point, plant11box)) {
    plant11 = false;
    HP += 1;
  }
  ///////-possible mechanic instead of level scalng: collect food to earn more hearts, when everything is eaten, evolve
}

void cameraDebug() {
  arduboy.setCursor(0, 0);
  arduboy.print(cameraxoffset);
  arduboy.setCursor(0, 8);
  arduboy.print(camerayoffset);
}
void scalePlayer() {

}
void scaleLevel() {

}
void cellStage() {
  //arduboy.invert(true);
  //draw plant material
  //cameraDebug();
  drawPlants();
  //drift plant material
  driftPlant0();
  //draw enemycells
  drawCells();
  //enemy cell behavio
  cellsBrain();
  //draw player
  drawPlayer();
  //input player controls
  cellControls();
  playerLife();

  //scale player incrementally by eating
  //when player is 4x original size, scale evrything down,
  //return player to original size
  // repeat ^^ twice, on what should be the third scaling, start next stage
  animate();
  //drawCellBorders();
}
//////end cell stage functions
