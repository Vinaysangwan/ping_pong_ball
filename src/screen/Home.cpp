#include "Home.hpp"

void Home::initTexts()
{
    home_text = new Texts("Home", "assets/fonts/Roboto-Regular.ttf");
    home_text->setOrigin(sf::Vector2f{home_text->getGlobalBounds().size / 2.0f});
    home_text->setPosition(sf::Vector2f{window_size.x / 2.0f, 50.0f});
}

Home::Home(sf::Vector2u window_size)
{
    this->window_size = window_size;

    initTexts();
}

Home::~Home()
{
    delete home_text;
}

void Home::update_Home()
{
}

void Home::render_Home(sf::RenderWindow *window)
{
    // Draw
    window->draw(*home_text);
}
