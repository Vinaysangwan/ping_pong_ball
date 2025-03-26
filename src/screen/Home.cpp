#include "Home.hpp"

void Home::initVariables()
{
    // Set Font Address
    font_address = "assets/fonts/Roboto-Regular.ttf";

    // Button size
    button_size = sf::Vector2f{150.0f, 50.0f};

    // Button Colors
    button_idle_color = sf::Color(0, 0, 255);
    button_hover_color = sf::Color(255, 0, 0);
    button_active_color = sf::Color(0, 255, 0);
}

void Home::initTexts()
{
    // Init Home Text
    home_text = new Texts("Home", font_address);
    home_text->setOrigin(home_text->getGlobalBounds().size / 2.0f);
    home_text->setPosition(sf::Vector2f{window_size.x / 2.0f, 50.0f});
}

void Home::initButtons()
{
    // Play Button
    play_button_position = sf::Vector2f{window_size.x / 2.0f, 150.0f};
    play_button = new Buttons(button_size, play_button_position, "Play", font_address,
                              button_idle_color, button_hover_color, button_active_color);

    // Quit Button
    quit_button_position = sf::Vector2f{window_size.x / 2.0f, 300.0f};
    quit_button = new Buttons(button_size, quit_button_position, "Quit", font_address,
                              button_idle_color, button_hover_color, button_active_color);
}

// Event if button is hover or active
void Home::handle_button_events()
{
    if (play_button->is_button_active(mouse_position))
    {
        e_GameMode = play_screen;
    }

    if (quit_button->is_button_active(mouse_position))
    {
        e_GameMode = quit;
    }
}

// Constructor
Home::Home()
{
    initVariables();
    initTexts();
    initButtons();
}

// Destructor
Home::~Home()
{
    delete home_text;
    delete play_button;
    delete quit_button;
}

// Update Function
void Home::update_Home()
{
    handle_button_events();
}

// Render Function
void Home::render_Home(sf::RenderWindow &window)
{
    // Draw
    window.draw(*home_text);
    play_button->renderButton(window);
    quit_button->renderButton(window);
}

// Set Mouse Position
void Home::setMousePos(sf::Vector2i mouse_position)
{
    this->mouse_position = (sf::Vector2f)mouse_position;
}
