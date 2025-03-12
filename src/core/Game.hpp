#pragma once

#include "../common.hpp"
#include "../entity/Player.hpp"

class Game
{
private:
    // Private Functions

    // InitFunctions
    void init_Variables();
    void init_Window();
    void init_Player();

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

    // Player
    Player *player;
};