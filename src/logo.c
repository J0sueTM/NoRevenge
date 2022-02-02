#include "logo.h"
#include "sprite.h"

void
InitLogo(Data *data)
{
  InitSprite(&data->logo,
             "res/sprite/logo.png",
             (Vector2)
             {
               TARGET_SOURCE_SIZE.x * 0.5f,
               TARGET_SOURCE_SIZE.y * 0.5f
             },
             2.f,
             1);
  data->logo.dest.y -= (data->logo.texture.height * 0.5f) + 2.f;

  InitSprite(&data->logoTitle,
             "res/sprite/le_fish_studio_title.png",
             (Vector2)
             {
               TARGET_SOURCE_SIZE.x * 0.5f,
               TARGET_SOURCE_SIZE.y * 0.7f
             },
             2.f,
             1);
//  data->logoTitle.dest.y += data->logoTitle.texture.height + 1.f;

  data->logo.color.a = 0;
  data->logoTitle.color.a = 0;

  data->bubble = LoadSound("res/sound/sfx/bubble.wav");
}

void
UpdateLogo(Data *data)
{
  if (data->currentFrame == 12)
  {
    PlaySound(data->bubble);
    data->logo.color.a = 255;
    data->logoTitle.color.a = 255;
  }
  else if (data->currentFrame == 36)
    SwitchState(data, STATE_MENU);
}

void
DrawLogo(Data *data)
{
  DrawSprite(&data->logo);
  DrawSprite(&data->logoTitle);

#if 0
  DrawTexturePro(data->logo.texture,
                 (Rectangle)
                 {
                   0.f,
                   0.f,
                   data->logo.texture.width,
                   data->logo.texture.height
                 },
                 (Rectangle)
                 {
                   TARGET_SOURCE_SIZE.x * 0.5f,
                   TARGET_SOURCE_SIZE.y * 0.5f,
                   data->logo.texture.width * 2.f,
                   data->logo.texture.height * 2.f
                 },
                 (Vector2)
                 {
                   data->logo.texture.width,
                   data->logo.texture.height
                 },
                 0.f,
                 WHITE);
#endif
}

void
EndLogo(Data *data)
{
  UnloadTexture(data->logo.texture);
  UnloadTexture(data->logoTitle.texture);
  UnloadSound(data->bubble);
}
