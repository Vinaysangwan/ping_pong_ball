#include "GameManager.hpp"

GameMode e_GameMode = home_screen;

sf::Vector2u window_size = sf::Vector2u{800, 600};

float entity_speed = 300.0f;

int player_score = 0;
int enemy_score = 0;

const std::string font_address = "assets/fonts/Roboto-Regular.ttf";