#define WIDTH 100
#define HALF_WIDTH WIDTH / 2
#define QUART_WIDTH WIDTH / 4

#define HEIGHT 100
#define HALF_HEIGHT HEIGHT / 2
#define QUART_HEIGHT HEIGHT / 4

#define ANPANMAN_SKIN 0xE5B1
#define ANPANMAN_CHEEK 0xDBEC
#define ANPANMAN_NOSE 0xCB08
#define ANPANMAN_MOUTH 0x926A

#include "hello_world.h"

TFT_eSprite sprite1 = TFT_eSprite(&M5.Lcd);
TFT_eSprite sprite2 = TFT_eSprite(&M5.Lcd);
TFT_eSprite sprite3 = TFT_eSprite(&M5.Lcd);

void reset_shape(TFT_eSprite *shape)
{
  shape->setColorDepth(8);
  shape->createSprite(WIDTH, HEIGHT);
  shape->fillSprite(TFT_BLACK);
}

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

void shape_star(TFT_eSprite *shape, int color)
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

void push_sprite(TFT_eSprite *sprite)
{
  sprite->pushSprite(ScreenX::MIDDLE - HALF_WIDTH, ScreenY::MIDDLE - HALF_HEIGHT);
}

void HelloWorld::setup()
{
  M5.begin();
  M5.Lcd.fillScreen(BLACK);

  // Initialize sprites
  reset_shape(&sprite1);
  shape_heart(&sprite1, RED);

  reset_shape(&sprite2);
  shape_star(&sprite2, CYAN);

  reset_shape(&sprite3);
  shape_diamond(&sprite3, YELLOW);

  // Place initial sprite
  push_sprite(&sprite1);

  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 0);

  M5.Lcd.print("Hello World!");
}

void HelloWorld::loop()
{
  M5.update();

  if (M5.BtnA.wasPressed())
  {
    push_sprite(&sprite1);
  }
  else if (M5.BtnB.wasPressed())
  {
    push_sprite(&sprite2);
  }
  else if (M5.BtnC.wasPressed())
  {
    push_sprite(&sprite3);
  }
}