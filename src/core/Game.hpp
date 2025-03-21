#pragma once

#include "../game_manager/GameManager.hpp"
#include "../screen/Home.hpp"
#include "../screen/Play.hpp"

class Game
{
private:
    // Private Functions

    // InitFunctions
    void init_Variables();
    void init_Window();
    void initFPSText();
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

    // Window Size
    unsigned int window_width;
    unsigned int window_height;

    // Window Members
    sf::RenderWindow *window;
    sf::VideoMode window_video_mode;
    std::string title;

    // Times
    Times time;

    // FPS Text
    Texts *fps_text;

    // Home Screen
    Home *home;

    // Play Screen
    Play *play;
};