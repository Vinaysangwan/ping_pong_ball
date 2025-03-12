#include "Game.hpp"

void Game::init_Variables()
{
    // Define Window Width & Height
    this->window_video_mode.size.x = 800; // Width
    this->window_video_mode.size.y = 600; // Height

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

// Init Player
void Game::init_Player()
{
    this->player = new Player();
}

// Constructor
Game::Game()
{
    this->init_Variables();
    this->init_Window();
    this->init_Player();
}

// Destructor
Game::~Game()
{
    delete this->window;
    delete this->player;
    delete this->game_clock;
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
        }
    }
}

// Game Update
void Game::update()
{
    // Set Delta Time
    this->delta_time = this->game_clock->restart().asSeconds();

    this->player->update_Player(this->delta_time);

    this->poll_Event();
}

// Game Render
void Game::render()
{
    this->window->clear(sf::Color(86, 86, 86));

    // Draw Objects
    this->player->render_Player(this->window);

    this->window->display();
}