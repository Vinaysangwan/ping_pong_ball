#include "Play.hpp"

// ********************************************************************************************************
// ************************************************* Private Functions ************************************
// ********************************************************************************************************

// Initialize Variables
void Play::initVariables()
{
    font_address = "assets/fonts/Roboto-Regular.ttf";
}

void Play::initEntity()
{
    // Player
    player = new Player();

    // Enemy
    enemy = new Enemy();

    // Ball
    ball = new Ball();
}

// Initialize Texts
void Play::initTexts()
{
    // Player Score Text
    player_score_text = new Texts("YOU: 0", font_address);
    player_score_text->setCharacterSize(20.0f);
    player_score_text->setPosition(sf::Vector2f{window_size.x / 2.0f - player_score_text->getGlobalBounds().size.x - 50.0f, 20.0f});

    // Enemy Score Text
    enemy_score_text = new Texts("COMPUTER: 0", font_address);
    enemy_score_text->setCharacterSize(20.0f);
    enemy_score_text->setPosition(sf::Vector2f{window_size.x / 2.0f + 50.0f, 20.0f});
}

// New Game
void Play::newGame()
{
    initEntity();
    player_score = 0;
    enemy_score = 0;
    initTexts();
}

// Switch Game Mode
void Play::game_mode_switch()
{
    /*
        if,
            - Escape = Home Screen
    */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Escape))
    {
        newGame();
        e_GameMode = home_screen;
    }
}

// ********************************************************************************************************
// ************************************************* Public Functions *************************************
// ********************************************************************************************************

// Constructor
Play::Play()
{
    initVariables();
    initEntity();
    initTexts();

    enemy->getBallRadius(ball->getRadius());
    ball->getEntitySize(player->getSize() / 2.0f, enemy->getSize() / 2.0f);
}

// Destructor
Play::~Play()
{
    delete player;
    delete enemy;
    delete ball;
    delete player_score_text;
    delete enemy_score_text;
}

// Update Function
void Play::update_Play(float delta_time)
{
    game_mode_switch();

    player->update_Player(delta_time);

    enemy->getBallPosition(ball->getPosition());
    enemy->update_Enemy(delta_time);

    ball->getPlayerPosition(player->getPosition());
    ball->getEnemyPosition(enemy->getPosition());
    ball->update_Ball(delta_time);

    player_score_text->stream_string_int("YOU: ", player_score);
    enemy_score_text->stream_string_int("COMPUTER: ", enemy_score);
}

// Render Function
void Play::render_Play(sf::RenderWindow &window)
{
    window.draw(*player);
    window.draw(*enemy);
    window.draw(*ball);

    window.draw(*player_score_text);
    window.draw(*enemy_score_text);
}
