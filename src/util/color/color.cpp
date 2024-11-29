#include "color.h"

int random_color_idx() {
  return random(0, num_colors);
}

int random_color() {
  return colors[random_color_idx()];
}

int random_new_color_idx(int old) {
  if (num_colors <= 1) return old;

  int new_color;
  do {
    new_color = random_color();
  } while (new_color == old);

  return new_color;
}
