#pragma once

#include "../texts/Texts.hpp"

class Buttons
{
private:
    // Private Functions
    void initButton();
    void initButtonText();

public:
    // Public Functions

    // Constructors & Destructors
    Buttons(sf::Vector2f size, sf::Vector2f position, std::string text, std::string font_address,
            sf::Color idle_color, sf::Color hover_color, sf::Color active_color);
    ~Buttons();

    // Main Buttons Functions
    void renderButton(sf::RenderWindow &window);

private:
    // Private Members

    // Button
    sf::RectangleShape *button;
    sf::Vector2f button_size;
    sf::Vector2f button_position;

    // Text
    Texts *text;
    std::string button_text;
    std::string font_address;

    // Colors
    sf::Color idle_color;
    sf::Color hover_color;
    sf::Color active_color;
};