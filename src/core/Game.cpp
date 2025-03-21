#include "Game.hpp"

void Game::init_Variables()
{
    // Init Window Width & Height
    window_width = 800;  // Width
    window_height = 600; // Height

    // Init Window Video Mode
    this->window_video_mode.size.x = window_width;
    this->window_video_mode.size.y = window_height;

    // Window Title
    this->title = "Ping Pong";

    // Game Clock
    this->game_clock = new sf::Clock();
}

// Init Window
void Game::init_Window()
{
    this->window = new sf::RenderWindow(this->window_video_mode, this->title, sf::Style::Close | sf::Style::Titlebar);

    // Set Window Frame Limit
    this->window->setFramerateLimit(60);

    // Set Window Position
    this->window->setPosition(sf::Vector2i{this->window->getPosition().x, this->window->getPosition().y - 50});
}

// Init the Game Mode
void Game::initGameMode()
{
    this->e_game_mode = home_screen;
}

// Init Home
void Game::initHome()
{
    this->home = new Home(sf::Vector2u{window_width, window_height});
}

// Init Play
void Game::initPlay()
{
    this->play = new Play();
}

// Constructor
Game::Game()
{
    this->init_Variables();
    this->init_Window();

    // Init Screen Functions
    this->initHome();
    this->initPlay();
}

// Destructor
Game::~Game()
{
    delete this->home;
    delete this->play;
    delete this->game_clock;
    delete this->window;
}

bool Game::running() const
{
    if (this->window->isOpen())
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Game Poll Event
void Game::poll_Event()
{
    while (std::optional event = this->window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            this->window->close();
            break;
        }

        if (const auto *key_pressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (key_pressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                this->window->close();
                break;
            }

            if (key_pressed->scancode == sf::Keyboard::Scancode::N)
            {
                this->e_game_mode = (this->e_game_mode == home_screen) ? play_screen : home_screen;
                break;
            }
        }
    }
}

// Game Update
void Game::update()
{
    // Set Delta Time
    this->delta_time = this->game_clock->restart().asSeconds();

    this->poll_Event();

    switch (this->e_game_mode)
    {
    case home_screen:
        this->home->update_Home();
        break;

    case play_screen:
        this->play->update_Play();
        break;
    }
}

// Game Render
void Game::render()
{
    this->window->clear(sf::Color(86, 86, 86));

    // Draw Objects
    switch (e_game_mode)
    {
    case home_screen:
        this->home->render_Home(this->window);
        break;

    case play_screen:
        this->play->render_Play(this->window);
        break;
    }

    this->window->display();
}