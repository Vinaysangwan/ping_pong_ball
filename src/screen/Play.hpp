#pragma once

#include "../texts/Texts.hpp"

// Include Entities
#include "../entity/Player.hpp"
#include "../entity/Enemy.hpp"
#include "../entity/Ball.hpp"

class Play
{
private:
    // Private Functions

    // Init Functions
    void initVariables();
    void initEntity();
    void initTexts();

    void newGame();

    void game_mode_switch();

public:
    // Public Functions

    // Constructors & Destructors
    Play();
    ~Play();

    // Main Play Functions
    void update_Play(float delta_time);
    void render_Play(sf::RenderWindow &window);

private:
    // Private Members

    // Player
    Player *player;

    // Enemy
    Enemy *enemy;

    // Ball
    Ball *ball;

    // Texts
    std::string font_address;

    Texts *player_score_text;
    Texts *enemy_score_text;
};