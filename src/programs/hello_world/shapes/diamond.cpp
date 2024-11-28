#include "../hello_world.h"

void shape_diamond(TFT_eSprite *shape, int color)
{
  shape->fillTriangle(
      HALF_WIDTH, 0,
      0, HALF_HEIGHT,
      WIDTH, HALF_HEIGHT,
      color);
  shape->fillTriangle(
      0, HALF_HEIGHT,
      WIDTH, HALF_HEIGHT,
      HALF_WIDTH, HEIGHT,
      color);
}