#pragma once
#define MATRIX_X_MAX 50
#define MATRIX_Y_MAX 50

#include <programs/ProgramInterface.h>
#include <M5Unified.h>
#include <util/color/color.h>
#include <util/grid/grid.h>
#include <array>

class MatrixApp : public ProgramInterface {
public:
  MatrixApp() {
    for (int x = 0; x < MATRIX_X_MAX; x++) {
      for (int y = 0; y < MATRIX_Y_MAX; y++) {
        Point p = Point{ x: x, y : y };
        matrix[y][x] = random_color();
      }
    }
    rerender();
  }

  void setup() override;
  void loop() override;

private:
  int matrix[MATRIX_Y_MAX][MATRIX_X_MAX];

  /** The number of columns to render. */
  int x_render = 10;

  /** The number of rows to render. */
  int y_render = 10;

  /** Width of each cell. */
  int x_size = ScreenX::END / x_render;

  /** Height of each cell. */
  int y_size = ScreenY::END / y_render;

  /** Resizings are multiplied by this value before applied. Should be 1 or -1. */
  int resize_multiplier = 1;

  /** Render a point. */
  void render(Point p);

  /** Change a random point in the matrix. */
  void mutate();

  /** Rerender the whole screen. */
  void rerender();

  /** Add x number of columns and y number of lines. */
  void resize(int x, int y);
};
