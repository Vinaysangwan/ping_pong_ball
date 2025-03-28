#include "Game.hpp"

// ********************************************************************************************************
// ************************************************* Private Functions ************************************
// ********************************************************************************************************

// Init Variables
void Game::init_Variables()
{
    // Init Window Video Mode
    this->window_video_mode.size.x = window_size.x;
    this->window_video_mode.size.y = window_size.y;

    // Window Title
    this->title = "Ping Pong";

    // Set Initial Window Color
    window_color = sf::Color(0, 0, 0);
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

// Init FPS Text
void Game::initFPSText()
{
    this->fps_text = new Texts("FPS: 0.00000", font_address);
    this->fps_text->setPosition(sf::Vector2f{10.0f, 10.0f});
}

// Init Home
void Game::initHome()
{
    this->home = new Home();
}

// Init Play
void Game::initPlay()
{
    this->play = new Play();
}

// ********************************************************************************************************
// ************************************************* Public Functions *************************************
// ********************************************************************************************************

// Constructor
Game::Game()
{
    this->init_Variables();
    this->init_Window();

    // Init FPSText Function
    this->initFPSText();

    // Init Screen Functions
    this->initHome();
    this->initPlay();
}

// Destructor
Game::~Game()
{
    delete this->fps_text;
    delete this->home;
    delete this->play;
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

        if (e_GameMode == quit)
        {
            window->close();
            break;
        }
    }
}

// Game Update
void Game::update()
{
    // update Delta Time
    this->time.nextDeltaTime();

    mouse_position = sf::Mouse::getPosition(*window);

    // Update FPS Text
    this->fps_text->stream_string_float("FPS: ", 1.0f / this->time.getDeltaTime());

    this->poll_Event();

    switch (e_GameMode)
    {
    case home_screen:
        this->home->setMousePos(mouse_position);
        this->home->update_Home();
        break;

    case play_screen:
        this->play->update_Play(time.getDeltaTime());
        break;

    case quit:
        break;
    }
}

// Game Render
void Game::render()
{
    this->window->clear(window_color);

    // Draw Objects

    switch (e_GameMode)
    {
    case home_screen:
        window_color = sf::Color(sf::Color(0, 0, 0));
        this->home->render_Home(*this->window);
        break;

    case play_screen:
        window_color = sf::Color(sf::Color(86, 86, 86));
        this->play->render_Play(*this->window);
        break;

    case quit:
        break;
    }

    this->window->draw(*this->fps_text);

    this->window->display();
}