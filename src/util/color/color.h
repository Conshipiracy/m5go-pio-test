#pragma once

#include <M5Unified.h>

constexpr int colors[] = {
  WHITE,
  RED,
  ORANGE,
  YELLOW,
  GREENYELLOW,
  CYAN,
  BLUE,
  PURPLE
};

constexpr int num_colors = sizeof(colors) / sizeof(colors[0]);

int random_color();
int random_color_idx();
int random_new_color_idx(int old);
