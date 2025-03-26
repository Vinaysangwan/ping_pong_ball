#pragma once

#include "../common.hpp"

enum GameMode
{
    home_screen,
    play_screen,
    quit,
};

extern GameMode e_GameMode;
extern sf::Vector2u window_size;