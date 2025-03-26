#include "Play.hpp"

void Play::initVariables()
{
}

void Play::initPlayer()
{
    player = new Player();
}

void Play::game_mode_switch()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
    {
        e_GameMode = home_screen;
    }
}

Play::Play()
{
    initVariables();
    initPlayer();
}

Play::~Play()
{
    delete player;
}

void Play::update_Play()
{
    game_mode_switch();

    player->update_Player();
}

void Play::render_Play(sf::RenderWindow &window)
{
    player->render_Player(window);
}
