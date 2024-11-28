#include "hello_world.h"
#include "shapes/shapes.h"

TFT_eSprite sprite1 = TFT_eSprite(&M5.Lcd);
TFT_eSprite sprite2 = TFT_eSprite(&M5.Lcd);
TFT_eSprite sprite3 = TFT_eSprite(&M5.Lcd);

void reset_shape(TFT_eSprite *shape)
{
  shape->setColorDepth(8);
  shape->createSprite(WIDTH, HEIGHT);
  shape->fillSprite(TFT_BLACK);
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