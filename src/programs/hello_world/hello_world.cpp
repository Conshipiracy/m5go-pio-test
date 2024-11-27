#include "hello_world.h"

void circle_color(int color) {
  M5.Lcd.fillCircle(ScreenX::MIDDLE, ScreenY::MIDDLE, 50, color);
}

void HelloWorld::setup() {
  M5.begin();
  M5.Lcd.fillScreen(BLACK);

  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setTextSize(3);
  M5.Lcd.setCursor(0, 0);
  M5.Lcd.print("Hello World!");

  circle_color(RED);
}

void HelloWorld::loop() {
  M5.update();

  if (M5.BtnA.wasPressed()) {
    circle_color(CYAN);
  } else if (M5.BtnB.wasPressed()) {
    circle_color(BLACK);
  } else if (M5.BtnC.wasPressed()) {
    circle_color(RED);
  }
}