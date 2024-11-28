#include "../hello_world.h"

void shape_heart(TFT_eSprite *shape, int color)
{
  shape->fillCircle(QUART_WIDTH, QUART_HEIGHT, QUART_WIDTH, color);
  shape->fillCircle(WIDTH - QUART_WIDTH, QUART_HEIGHT, QUART_WIDTH, color);
  shape->fillRect(0, QUART_HEIGHT, WIDTH, HEIGHT, BLACK);
  shape->fillTriangle(
    0, QUART_HEIGHT,
    WIDTH, QUART_HEIGHT,
    HALF_WIDTH, HEIGHT,
    color
  );
}