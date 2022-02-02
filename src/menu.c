#include "menu.h"

void
InitMenu(Data *data)
{
  InitSprite(&data->title,
             "res/sprite/title.png",
             (Vector2)
             {
               TARGET_SOURCE_SIZE.x * 0.5f,
               TARGET_SOURCE_SIZE.y * 0.4f
             },
             1.f,
             1);

  InitSprite(&data->button,
             "res/sprite/button.png",
             (Vector2)
             {
               0.f,
               TARGET_SOURCE_SIZE.y * 0.78f
             },
             1.f,
             3);

  data->menuMusic = LoadMusicStream("res/sound/stream/menu.wav");
  PlayMusicStream(data->menuMusic);
}

void
UpdateMenu(Data *data)
{
  UpdateMusicStream(data->menuMusic);
}

void
DrawMenu(Data *data)
{
  ClearBackground(GRAY);

  DrawSprite(&data->title);

  /* Left button */
  data->button.dest.x = (TARGET_SOURCE_SIZE.x * 0.5f) - (data->button.dest.width * 0.5f) - 1.f;
  DrawSprite(&data->button);

  /* Right button */
  data->button.dest.x = (TARGET_SOURCE_SIZE.x * 0.5f) + (data->button.dest.width * 0.5f) + 1.f;
  DrawSprite(&data->button);
}

void
EndMenu(Data *data)
{
  UnloadTexture(data->title.texture);
  UnloadTexture(data->button.texture);
  UnloadMusicStream(data->menuMusic);
}
