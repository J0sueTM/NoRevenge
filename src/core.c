#include "core.h"
#include "sprite.h"
#include "logo.h"
#include "menu.h"

Data *
InitGame()
{
  SetWindowState(FLAG_VSYNC_HINT);
  InitWindow(0, 0, "No Revenge | Game Jaaj 7");
  InitAudioDevice();

//  ToggleFullscreen();

  SetTargetFPS(60);
  SetExitKey(0);

  Data *data = malloc(sizeof(Data));

  data->windowSize.x = GetScreenWidth();
  data->windowSize.y = GetScreenHeight();

  /* Target render */
  data->renderTarget = LoadRenderTexture(TARGET_SOURCE_SIZE.x, TARGET_SOURCE_SIZE.y);
  SetTextureFilter(data->renderTarget.texture, TEXTURE_FILTER_POINT);

  data->targetSize.x = data->windowSize.x;
  data->targetSize.y = data->windowSize.y;

  float expectedTargetHeight = (data->windowSize.x * TARGET_PROPORTION.y) / TARGET_PROPORTION.x;
  if (expectedTargetHeight > data->windowSize.y)
    data->targetSize.x = (data->windowSize.y * TARGET_PROPORTION.x) / TARGET_PROPORTION.y;
  else
    data->targetSize.y = expectedTargetHeight;

  data->targetOrigin.x = data->targetSize.x * 0.5f; 
  data->targetOrigin.y = data->targetSize.y * 0.5f; 

  data->targetSrc.x = 0.f;
  data->targetSrc.y = 0.f;
  data->targetSrc.width = TARGET_SOURCE_SIZE.x;
  data->targetSrc.height = -TARGET_SOURCE_SIZE.y;

  data->targetDest.x = data->windowSize.x * 0.5f;
  data->targetDest.y = data->windowSize.y * 0.5f;
  data->targetDest.width = data->targetSize.x;
  data->targetDest.height = data->targetSize.y;

  data->font = LoadFont("res/font/iFlash705.ttf");

  /* Misc */
  data->currentTime = GetTime();
  data->lastTime = data->currentTime;

  data->currentState = STATE_NONE;
  SwitchState(data, STATE_LOGO);

  return data;
}

void
UpdateGame(Data *data)
{
  data->currentTime = GetTime();
  if (data->currentTime - data->lastTime >= (1.f / DEFAULT_FRAMERATE))
  {
    data->lastTime = data->currentTime;
    ++data->currentFrame;
  }

  switch (data->currentState)
  {
  case STATE_LOGO:
    UpdateLogo(data);

    break;
  case STATE_MENU:
    UpdateMenu(data);

    break;
  case STATE_ABOUT:
    break;
  case STATE_SCENE_0:
    break;
  default:
    break;
  }
}

void
DrawGame(Data *data)
{
  BeginTextureMode(data->renderTarget);
  ClearBackground(BLACK);

  switch (data->currentState)
  {
  case STATE_LOGO:
    DrawLogo(data);

    break;
  case STATE_MENU:
    DrawMenu(data);

    break;
  case STATE_ABOUT:
    break;
  case STATE_SCENE_0:
    break;
  default:
    break;
  }

  EndTextureMode();
  
  BeginDrawing();
  ClearBackground(BLACK);

  DrawTexturePro(data->renderTarget.texture,
                 data->targetSrc,
                 data->targetDest,
                 data->targetOrigin,
                 0.f,
                 WHITE);

  EndDrawing();
}

void
EndGame(Data *data)
{
  SwitchState(data, STATE_NONE);

  UnloadRenderTexture(data->renderTarget);
  free(data);

  CloseWindow();
}

void
SwitchState(Data *data, State newState)
{
  data->lastState = data->currentState;
  data->currentState = newState;

  data->currentFrame = 0;

  switch (data->currentState)
  {
  case STATE_LOGO:
    InitLogo(data);

    break;
  case STATE_MENU:
    InitMenu(data);
    
    break;
  case STATE_ABOUT:
    break;
  case STATE_SCENE_0:
    break;
  default:
    break;
  }

  switch (data->lastState)
  {
  case STATE_LOGO:
    EndLogo(data);

    break;
  case STATE_MENU:
    EndMenu(data);
    
    break;
  case STATE_ABOUT:
    break;
  case STATE_SCENE_0:
    break;
  default:
    break;
  }
}
