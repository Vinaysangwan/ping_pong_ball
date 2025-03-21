#include "Play.hpp"

void Play::initVariables()
{
}

void Play::initPlayer()
{
    this->player = new Player();
}

Play::Play()
{
    this->initVariables();
    this->initPlayer();
}

Play::~Play()
{
}

void Play::update_Play()
{
}

void Play::render_Play(sf::RenderWindow *window)
{
    this->player->render_Player(window);
}
