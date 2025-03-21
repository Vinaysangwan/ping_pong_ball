#pragma once

#include "../game_manager/GameManager.hpp"
#include "../texts/Texts.hpp"

class Home
{
private:
    // Private Functions
    void initTexts();

public:
    // Public Functions

    // Constructors & Destructors
    Home();
    ~Home();

    // Main Home Functions
    void update_Home();
    void render_Home(sf::RenderWindow *window);

private:
    // Private Members

    // Texts
    Texts *home_text;
};