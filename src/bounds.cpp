#include "game.hpp"

game::ScreenBounds game::get_screen_bounds(const game::GameConfig &c) {
  game::ScreenBounds bounds = {
      .x_min = 0,
      .x_max = c.win_width,
      .y_min = 0,
      .y_max = c.win_height,
  };

  return bounds;
}
