#include "matrix.h"
using namespace std;

void MatrixApp::rerender() {
  for (int x = 0; x < MATRIX_X_MAX; x++) {
    for (int y = 0; y < MATRIX_Y_MAX; y++) {
      Point p = Point{ x: x, y : y };
      render(p);
    }
  }
}

void MatrixApp::mutate() {
  int x = random(0, x_render);
  int y = random(0, y_render);
  matrix[y][x] = random_color();
  render(Point{ x: x, y : y });
}

void MatrixApp::resize(int x, int y) {
  int new_x = x_render + x;
  if (new_x > 0 && new_x < MATRIX_X_MAX) {
    x_render = new_x;
    x_size = ScreenX::END / x_render;
  }

  int new_y = y_render + y;
  if (new_y > 0 && new_y < MATRIX_Y_MAX) {
    y_render = new_y;
    y_size = ScreenY::END / y_render;
  }

  rerender();
}

void MatrixApp::render(Point p) {
  M5.Lcd.fillRect(
    p.x * x_size,
    p.y * y_size,
    x_size,
    y_size,
    matrix[p.y][p.x]
  );
  M5.Lcd.drawRect(
    p.x * x_size,
    p.y * y_size,
    x_size,
    y_size,
    BLACK
  );
}

void MatrixApp::setup() {
  M5.begin();
}

void MatrixApp::loop() {
  M5.update();
  mutate();

  if (M5.BtnA.wasPressed()) {
    resize(1 * resize_multiplier, 0);
  }
  else if (M5.BtnB.wasPressed()) {
    resize_multiplier *= -1;
  }
  else if (M5.BtnC.wasPressed()) {
    resize(0, 1 * resize_multiplier);
  }
  delay(5);
}
