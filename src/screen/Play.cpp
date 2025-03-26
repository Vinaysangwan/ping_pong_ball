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
    enemy->update_Enemy();
    ball->update_Ball();
}

// Render Function
void Play::render_Play(sf::RenderWindow &window)
{
    player->render_Player(window);
    enemy->render_Enemy(window);
    ball->render_Ball(window);
}
