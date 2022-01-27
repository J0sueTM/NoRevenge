#include "core.h"

int
main
(
  void
)
{
  Data *data = InitGame();

  while (!WindowShouldClose())
  {
    UpdateGame(data);
    DrawGame(data);
  }

  EndGame(data);

  return 0;
}
