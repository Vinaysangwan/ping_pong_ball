#include "Play.hpp"

// ********************************************************************************************************
// ************************************************* Private Functions ************************************
// ********************************************************************************************************

// Initialize Variables
void Play::initVariables()
{
}

// Initialize Player
void Play::initPlayer()
{
    player = new Player();
}

// Initialize Enemy
void Play::initEnemy()
{
    enemy = new Enemy();
}

// Initialize Ball
void Play::initBall()
{
    ball = new Ball();
}

// Switch Game Mode
void Play::game_mode_switch()
{
    /*
        if,
            - Escape = Home Screen
    */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
    {
        e_GameMode = home_screen;
    }
}

// ********************************************************************************************************
// ************************************************* Public Functions *************************************
// ********************************************************************************************************

// Constructor
Play::Play()
{
    initVariables();
    initPlayer();
    initEnemy();
    initBall();

    enemy->getBallRadius(ball->getRadius());
    ball->getEntitySize(player->getSize(), enemy->getSize());
}

// Destructor
Play::~Play()
{
    delete player;
    delete enemy;
    delete ball;
}

// Update Function
void Play::update_Play()
{
    game_mode_switch();

    player->update_Player();

    enemy->getBallPosition(ball->getPosition());
    enemy->update_Enemy();

    ball->getPlayerPosition(player->getPosition());
    ball->getEnemyPosition(enemy->getPosition());
    ball->update_Ball();
}

// Render Function
void Play::render_Play(sf::RenderWindow &window)
{
    window.draw(*player);
    window.draw(*enemy);
    window.draw(*ball);
}
