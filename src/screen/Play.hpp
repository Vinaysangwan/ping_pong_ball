#pragma once

#include "../game_manager/GameManager.hpp"

// Include Entities
#include "../Entity/Player.hpp"
#include "../Entity/Enemy.hpp"
#include "../Entity/Ball.hpp"

class Play
{
private:
    // Private Functions

    // Init Functions
    void initVariables();
    void initPlayer();
    void initEnemy();
    void initBall();

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

    // Enemy
    Enemy *enemy;

    // Ball
    Ball *ball;
};