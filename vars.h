#pragma once

#define TITLE 0
#define CELL 1
#define CELL_LOSE 2
#define CREATURE_TITLE 3
#define CREATURE 4
#define CREATURE_LOSE 5
#define TRIBAL 6
#define INDUSTRIAL 7
#define SPACE 8
#define WIN 9

int gamestate = TITLE;
int west = 0;
int east = 0;
int north = 0;
int south = 0;
float plantx=0;
float planty=0;
float plant1x = 54;
float plant1y = 76;
float plant2x = 14;
float plant2y = 93;
float plant3x = 126;
float plant3y = 100;
float plant4x = 220;
float plant4y = 34;
float plant5x = 210;
float plant5y = 176;
float plant6x =random(0, 512);
float plant6y = random(0, 512);
float plant7x =random(0, 512);
float plant7y = random(0, 512);
float plant8x =random(0, 512);
float plant8y =random(0, 512);
float plant9x = random(0, 512);
float plant9y = random(0, 512);
float plant10x =random(0, 512);
float plant10y =random(0, 512);
float plant11x =random(0, 512);
float plant11y =random(0, 512);

//switch these off when eaten
bool plant0=true;
bool plant1 =true;
bool plant2= true;
bool plant3= true;
bool plant4= true;
bool plant5= true;

bool plant6= true;

bool plant7 = true;
bool plant8 = true;

bool plant9 = true;

bool plant10 = true;
bool plant11 = true;

//"it came to me in a dream... the ship doesn't move at all! Instead it moves the entire universe around it..."
int cameraxoffset = 255;
int camerayoffset = 255;

constexpr uint8_t cFrameCount = 3;
constexpr uint8_t frameCount = 1;
constexpr uint8_t firstFrame = 0;
constexpr uint8_t lastFrame = (frameCount - 1);
uint8_t currentFrame = firstFrame;
float cell0x =random(0, 512);
float cell0y =random(0, 512);
float cell1x = random(0, 512);
float cell1y = random(0, 512);
float cell2x =random(0, 512);
float cell2y =random(0, 512);
float cell3x = random(0, 512);
float cell3y = random(0, 512);
float cell4x =random(0, 512);
float cell4y =random(0, 512);
float cell5x = random(0, 512);
float cell5y = random(0, 512);
float cell6x =random(0, 512);
float cell6y =random(0, 512);
float cell7x = random(0, 512);
float cell7y = random(0, 512);
int playercellx = WIDTH / 2 - 2;
int playercelly = HEIGHT / 2 - 2;
struct Cells {
  int x;
  int y;
  const char *image;
  const char *mask;
};

uint8_t HP = 3;
