#include "../hello_world.h"

void shape_star(LGFX_Sprite *shape, int color)
{
  shape->fillTriangle(
      0, QUART_HEIGHT,
      WIDTH, QUART_HEIGHT,
      HALF_WIDTH, HEIGHT,
      color);

  shape->fillTriangle(
      HALF_WIDTH, 0,
      0, QUART_HEIGHT*3,
      WIDTH, QUART_HEIGHT*3,
      color);
}