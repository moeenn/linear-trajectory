#include "game.hpp"

int main() {
  const game::GameConfig config = {
      .win_width = 800,
      .win_height = 500,
      .win_name = "Game",
      .fps = 60,
      .ball_size = 3,
      .ball_default_speed = 5.0f,
      .num_balls = 30,
  };

  game::Game game{config};
  return game.render_loop();
}
