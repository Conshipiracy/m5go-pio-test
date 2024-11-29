#pragma once

#include <programs/ProgramInterface.h>
#include <M5Unified.h>
#include <util/grid/grid.h>
#include <string>
#include <util/color/color.h>
using namespace std;

#define WIDTH 100
#define HALF_WIDTH WIDTH / 2
#define QUART_WIDTH WIDTH / 4

#define HEIGHT 100
#define HALF_HEIGHT HEIGHT / 2
#define QUART_HEIGHT HEIGHT / 4

class HelloWorld : public ProgramInterface {
public:
  LGFX_Sprite sprite1 = LGFX_Sprite(&M5.Lcd);
  LGFX_Sprite sprite2 = LGFX_Sprite(&M5.Lcd);
  LGFX_Sprite sprite3 = LGFX_Sprite(&M5.Lcd);

  // Used when printing hello world to the screen "async"
  string text = "Hello world!";
  int print_color = 0;
  bool print_done = false;
  int print_pos = 0;
  int print_next = 0;

  void setup() override;
  void loop() override;

private:
  void push_sprite(LGFX_Sprite* sprite);
  void reset_shape(LGFX_Sprite* sprite);
  void print_text();
};
