#pragma once

#include "../game_manager/GameManager.hpp"
#include "../components/Buttons.hpp"

class Home
{
private:
    // Private Functions

    // Init Functions
    void initVariables();
    void initTexts();
    void initButtons();

    void handle_button_events();

public:
    // Public Functions

    // Constructors & Destructors
    Home();
    ~Home();

    // Main Home Functions
    void update_Home();
    void render_Home(sf::RenderWindow &window);
    void setMousePos(sf::Vector2i mouse_position);

private:
    // Private Members

    // Mouse Position
    sf::Vector2f mouse_position;

    // Texts
    Texts *home_text;

    // Buttons
    sf::Vector2f button_size;
    sf::Color button_idle_color;
    sf::Color button_hover_color;
    sf::Color button_active_color;

    // Play Button
    Buttons *play_button;
    sf::Vector2f play_button_position;

    // Quit Button
    Buttons *quit_button;
    sf::Vector2f quit_button_position;
};