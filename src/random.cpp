#include "game.hpp"

int game::random_int(int min, int max) {
  int value = std::rand();
  return (value % max) + min;
}

float game::random_float(float min, float max) {
  float value = min + (max - min) * (float)rand() / (float)RAND_MAX;
  return value;
}

unsigned char game::random_char() {
  int value = std::rand();
  unsigned char v = value % 256;
  return v;
}
