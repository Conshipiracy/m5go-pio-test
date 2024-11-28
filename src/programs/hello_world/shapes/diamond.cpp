#include "../hello_world.h"

void shape_diamond(LGFX_Sprite *shape, int color)
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