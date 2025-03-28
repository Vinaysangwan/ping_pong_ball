#pragma once

#include "../common.hpp"
#include <string.h>

enum GameMode
{
    home_screen,
    play_screen,
    quit,
};

extern GameMode e_GameMode;
extern sf::Vector2u window_size;
extern float entity_speed;
extern int player_score;
extern int enemy_score;
extern const std::string font_address;