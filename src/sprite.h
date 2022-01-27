#ifndef SPRITE
#define SPRITE

#include "core.h"

void
InitSprite(Sprite *sprite, char *file, Vector2 pos, float scale, int frameCount);

void
DrawSprite(Sprite *sprite);

void
SetSpriteScale(Sprite *sprite, float scale);

#endif
