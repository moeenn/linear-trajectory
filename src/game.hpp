#pragma once

#include "raylib.h"
#include <iostream>
#include <vector>

namespace game {

enum class Direction : uint { Left, Right };

struct GameConfig {
  uint win_width;
  uint win_height;
  const char *win_name;
  uint fps;
  uint ball_size;
  float ball_default_speed;
  uint num_balls;
};

struct ScreenBounds {
  uint x_min;
  uint x_max;
  uint y_min;
  uint y_max;
};

ScreenBounds get_screen_bounds(const GameConfig &c);
int random_int(int min, int max);
float random_float(float min, float max);
unsigned char random_char();

class Ball {
public:
  Vector2 pos;
  float speed;
  Color color;
  float m, c;
  Direction direction;
  ScreenBounds bounds;

  explicit Ball(const ScreenBounds &b, float speed);
  void update_trajectory();
  Vector2 position();
};

struct GameState {
  std::vector<Ball> balls;
};

class Game {
public:
  GameConfig config;
  ScreenBounds bounds;
  GameState state;

  explicit Game(const GameConfig &config);
  void spawn_ball();
  int render_loop();
};
}; // namespace game
