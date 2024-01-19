#include "game.hpp"

game::Ball::Ball(const ScreenBounds &b, float speed) {
  this->bounds = b;
  this->pos = Vector2{
      .x = random_float(b.x_min, b.x_max),
      .y = random_float(b.y_min, b.y_max),
  };
  this->speed = speed;
  this->m = std::rand() / (float)RAND_MAX,
  this->c = random_int(-1 * b.y_max, b.y_max);
  this->direction =
      (random_int(1, 2) % 2 == 0) ? Direction::Right : Direction::Left;

  /** spawn with a random color */
  this->color = Color {
    .r = random_char(),
    .g = random_char(),
    .b = random_char(),
    .a = 255,
  };
}

void game::Ball::update_trajectory() {
  pos.x = (direction == Direction::Right) ? pos.x + speed : pos.x - speed;

  // bounce against right
  if (pos.x > bounds.x_max) {
    direction = Direction::Left;
    m *= -1;
    c = pos.y - (m * pos.x);
  }

  // bounce against left
  if (pos.x < bounds.x_min) {
    direction = Direction::Right;
    m *= -1;
    c = pos.y;
  }

  // bounce against bottom
  if (pos.y < bounds.y_min) {
    m *= -1;
    c *= -1;
  }

  // bounce against top
  if (pos.y > bounds.y_max) {
    m *= -1;
    c = bounds.y_max - (m * pos.x);
  }

  pos.y = (m * pos.x) + c;
}

Vector2 game::Ball::position() {
  return Vector2{.x = pos.x, .y = bounds.y_max - pos.y};
}
