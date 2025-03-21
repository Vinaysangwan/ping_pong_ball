#pragma once

#include "../texts/Texts.hpp"

class Home
{
private:
    // Private Functions
    void initTexts();

public:
    // Public Functions

    // Constructors & Destructors
    Home(sf::Vector2u window_size);
    ~Home();

    // Main Home Functions
    void update_Home();
    void render_Home(sf::RenderWindow *window);

private:
    // Private Members

    // Window Size
    sf::Vector2u window_size;

    // Texts
    Texts *home_text;
};