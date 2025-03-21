#pragma once

#include "../screen/Home.hpp"
#include "../screen/Play.hpp"

class Game
{
private:
    // Private Functions

    // InitFunctions
    void init_Variables();
    void init_Window();
    void initGameMode();
    void initHome();
    void initPlay();

public:
    // Public Functions
    Game();  // Constructor
    ~Game(); // Destructor

    // Asseccor
    bool running() const;

    // Main Game Functions
    void poll_Event();
    void update();
    void render();

private:
    // Private Members

    // Window Members
    sf::RenderWindow *window;
    sf::VideoMode window_video_mode;
    std::string title;

    // Time
    sf::Clock *game_clock;
    float delta_time;

    // Game Mode
    enum GameMode
    {
        home_screen,
        play_screen,
    };

    GameMode e_game_mode;

    // Home Screen
    Home *home;

    // Play Screen
    Play *play;
};