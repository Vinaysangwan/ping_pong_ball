#pragma once

#include "../common.hpp"
#include "../game_manager/GameManager.hpp"

class Player : public sf::RectangleShape
{
private:
    // Private Functions

    // Init Functions
    void init_Variables();
    void init_Player();

    // Player Movement
    void player_Movement(float delta_time);

public:
    // Public Functions

    Player();
    ~Player();

    // Main Player Functions
    void update_Player(float delta_time);

private:
    // Private Members

    // Player Variable
    sf::Vector2f player_size;
    sf::Color player_color;

    // Player Stats
    float player_speed;
};