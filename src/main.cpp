#include "game.hpp"

int main() {
  const game::GameConfig config = {
      .win_width = 1200,
      .win_height = 800,
      .win_name = "Game",
      .fps = 60,
      .ball_size = 5,
      .ball_default_speed = 8.0f,
  };

  game::Game game{config};
  for (uint i = 0; i < 10; i++) {
    game.spawn_ball();
  }

  return game.render_loop();
}
