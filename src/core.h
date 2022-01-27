#ifndef CORE
#define CORE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "raylib.h"

#define TARGET_PROPORTION (Vector2){ 16.f, 9.f }
#define TARGET_SOURCE_SIZE (Vector2){ 64.f, 36.f }

#define DEFAULT_FRAMERATE 12

/* Colour scheme: https://lospec.com/palette-list/oil-oak */
#undef BLACK
#undef GRAY
#define BLACK       (Color){ 9,   1,   16, 255 }
#define GRAY        (Color){ 26,  30,  37, 255 }
#define DARK_GREEN  (Color){ 61,  62,  50, 255 }
#define LIGHT_GREEN (Color){ 111, 101, 61, 255 }

typedef enum State State;
typedef struct Sprite Sprite;
typedef struct Data Data;

typedef enum State
{
  STATE_NONE,
  STATE_LOGO,
  STATE_MENU,
  STATE_ABOUT,
  STATE_SCENE_0,
} State;

typedef struct Sprite
{
  Texture2D texture;
  Vector2 size, origin;
  Rectangle src, dest;
  int scale;

  int frameCount, currentFrame;

  Color color;
} Sprite;

typedef struct Data
{
  Vector2 windowSize;

  State currentState, lastState;

  RenderTexture2D renderTarget;
  Vector2 targetSize, targetOrigin;
  Rectangle targetSrc, targetDest;

  /* Sprites */
  Sprite logo, logoTitle;
  Sprite title, button;

  /* Sounds */
  Sound bubble;
  Music menuMusic;

  /* Misc */
  double currentTime, lastTime;
  unsigned int currentFrame, lastFrame;
} Data;

Data *
InitGame();

void
UpdateGame(Data *data);

void
DrawGame(Data *data);

void
EndGame(Data *data);

void
SwitchState(Data *data, State newState);

#endif
