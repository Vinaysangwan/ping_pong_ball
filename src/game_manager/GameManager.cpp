#include "GameManager.hpp"

GameMode e_GameMode = home_screen;

sf::Vector2u window_size = sf::Vector2u{800, 600};

const sf::Vector2f entity_enemy_size = sf::Vector2f{30.0f, 120.0f};
const sf::Vector2f entity_player_size = sf::Vector2f{30.0f, 120.0f};
const float entity_ball_radius = 10.0f;

const float entity_speed = 300.0f;
const float entity_ball_speed = 400.0f;

int player_score = 0;
int enemy_score = 0;

const std::string font_address = "assets/fonts/Roboto-Regular.ttf";