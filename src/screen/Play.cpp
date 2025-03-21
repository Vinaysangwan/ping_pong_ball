#include "Play.hpp"

void Play::initVariables()
{
}

void Play::initPlayer()
{
    player = new Player();
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
    player->update_Player();
}

void Play::render_Play(sf::RenderWindow *window)
{
    player->render_Player(window);
}
