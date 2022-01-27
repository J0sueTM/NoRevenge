#include "sprite.h"

void
InitSprite(Sprite *sprite, char *file, Vector2 pos, float scale, int frameCount)
{
  sprite->texture = LoadTexture(file);

  sprite->src.x = 0.f;
  sprite->src.y = 0.f;
  sprite->src.width = sprite->texture.width / frameCount;
  sprite->src.height = sprite->texture.height;

  sprite->dest.x = (float)pos.x;
  sprite->dest.y = (float)pos.y;
  sprite->dest.width = sprite->texture.width / frameCount;
  sprite->dest.height = sprite->texture.height;

  SetSpriteScale(sprite, scale);

  sprite->frameCount = frameCount;
  sprite->currentFrame = 0;

  sprite->color = WHITE;
}

void
DrawSprite(Sprite *sprite)
{
  DrawTexturePro(sprite->texture,
                 sprite->src,
                 sprite->dest,
                 sprite->origin,
                 0.f,
                 sprite->color);
}

void
SetSpriteScale(Sprite *sprite, float scale)
{
  sprite->scale = scale;

  sprite->dest.width *= scale;
  sprite->dest.height *= scale;

  sprite->origin.x = sprite->dest.width * 0.5f;
  sprite->origin.y = sprite->dest.height * 0.5f;
}
