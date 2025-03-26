#pragma once

#include "../Entity/Player.hpp"
#include "../game_manager/GameManager.hpp"

class Play
{
private:
    // Private Functions

    // Init Functions
    void initVariables();
    void initPlayer();

    void game_mode_switch();

public:
    // Public Functions

    // Constructors & Destructors
    Play();
    ~Play();

    // Main Play Functions
    void update_Play();
    void render_Play(sf::RenderWindow &window);

private:
    // Private Members

    // Player
    Player *player;
};