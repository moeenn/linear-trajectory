#include "game.hpp"

game::Game::Game(const GameConfig &config) {
  this->config = config;
  this->bounds = get_screen_bounds(config);
  this->state = GameState{.balls = {}};
}

void game::Game::spawn_ball() {
  state.balls.push_back(Ball{bounds, config.ball_default_speed});
}

int game::Game::render_loop() {
  InitWindow(config.win_width, config.win_height, config.win_name);

  SetTargetFPS(config.fps);
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(BLACK);

    for (Ball &ball : state.balls) {
      ball.update_trajectory();
      DrawCircleV(ball.position(), config.ball_size, WHITE);
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
