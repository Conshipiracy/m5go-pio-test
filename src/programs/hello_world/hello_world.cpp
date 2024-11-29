#include "hello_world.h"
#include "shapes/shapes.h"
using namespace std;

void HelloWorld::reset_shape(LGFX_Sprite* shape) {
  shape->setColorDepth(8);
  shape->createSprite(WIDTH, HEIGHT);
  shape->fillSprite(TFT_BLACK);
}

void HelloWorld::push_sprite(LGFX_Sprite* sprite) {
  sprite->pushSprite(ScreenX::MIDDLE - HALF_WIDTH, ScreenY::MIDDLE - HALF_HEIGHT);
}

void HelloWorld::setup() {
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

  M5.Lcd.setTextColor(colors[print_color++]);
  M5.Lcd.setTextSize(4);
  M5.Lcd.setCursor(0, 0);
  print_next = millis();
}

void HelloWorld::print_text() {
  if (!print_done && millis() >= print_next)
  {
    print_next += 75;
    M5.Lcd.print(text[print_pos]);
    print_pos += 1;

    if (print_pos >= text.length())
    {
      if (print_color >= sizeof(colors) / sizeof(colors[0])) {
        print_color = 0;
      }

      M5.Lcd.setTextColor(colors[print_color]);
      M5.Lcd.setCursor(0, 0);
      print_pos = 0;
      print_color++;
    }
  }
}

void HelloWorld::loop() {
  M5.update();
  print_text();

  if (M5.BtnA.wasPressed()) {
    push_sprite(&sprite1);
  }
  else if (M5.BtnB.wasPressed()) {
    push_sprite(&sprite2);
  }
  else if (M5.BtnC.wasPressed()) {
    push_sprite(&sprite3);
  }
}
