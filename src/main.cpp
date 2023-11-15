#include "game.hpp"

int main() {
  const game::GameConfig config = {
      .win_width = 1200,
      .win_height = 800,
      .win_name = "Game",
      .fps = 60,
      .ball_size = 5,
      .ball_default_speed = 8.0f,
      .num_balls = 20,
  };

  game::Game game{config};
  return game.render_loop();
}
