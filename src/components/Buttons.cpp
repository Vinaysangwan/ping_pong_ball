#include "Buttons.hpp"

void Buttons::initButton()
{
    // Init Button
    button = new sf::RectangleShape(button_size);

    // Set Button Origin and Position
    button->setOrigin(button_size / 2.0f);
    button->setPosition(button_position);

    // Set Button Fill Color
    button->setFillColor(idle_color);
}

void Buttons::initButtonText()
{
    // Init Text
    text = new Texts(button_text, font_address);
    text->setCharacterSize(30);

    // Set Text Origin & Position
    text->setOrigin(text->getGlobalBounds().size / 2.0f);
    text->setPosition(sf::Vector2f{button_position.x, button_position.y - 5.0f});
}

Buttons::Buttons(sf::Vector2f size, sf::Vector2f position, std::string text, std::string font_address, sf::Color idle_color, sf::Color hover_color, sf::Color active_color)
{
    // Init Buttons Variables
    button_size = size;
    button_position = position;

    // Init Text Variables
    button_text = text;
    this->font_address = font_address;

    // Init Colors
    this->idle_color = idle_color;
    this->hover_color = hover_color;
    this->active_color = active_color;

    initButton();
    initButtonText();
}

Buttons::~Buttons()
{
    delete text;
    delete button;
}

void Buttons::renderButton(sf::RenderWindow &window)
{
    window.draw(*button);
    window.draw(*text);
}

bool Buttons::is_button_hover(sf::Vector2f mouse_position) const
{
    if (mouse_position.x >= button_position.x - button_size.x / 2.0f && mouse_position.x <= button_position.x + button_size.x / 2.0f &&
        mouse_position.y >= button_position.y - button_size.y / 2.0f && mouse_position.y <= button_position.y + button_size.y / 2.0f)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Buttons::is_button_active(sf::Vector2f mouse_position) const
{
    if (is_button_hover(mouse_position))
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
        {
            button->setFillColor(active_color);
            return true;
        }
        button->setFillColor(hover_color);
        return false;
    }
    else
    {
        button->setFillColor(idle_color);
        return false;
    }
}
