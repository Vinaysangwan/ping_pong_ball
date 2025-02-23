#pragma once

#include <SFML/Graphics.hpp>
#include <string.h>
#include <random>
#include <cmath>
#include <iostream>

class Game
{
public:
    Game();
    ~Game();
    void run();

private: // Member Functions
    // Initialize Functions
    void initWindow(); // Window
    void intiConst();  // Constants
    void initPlayer(); // Player
    void initEnemy();  // Enemy
    void initBall();   // Ball

    // Poll Events
    void pollEvents();

    // Update Functions
    void update();
    void updatePlayer(); // Player
    void updateEnemy();  // Enemy
    void updateBall();   // Ball

    // Render Functions
    void render();

private:
    // Window Related Members
    unsigned int m_window_width;
    unsigned int m_window_height;
    std::string m_title;
    sf::VideoMode m_vm;
    sf::RenderWindow *m_window;

    // Time
    sf::Clock clock;
    sf::Time delta_time;

    // Enemy Time
    sf::Clock enemy_timer;
    sf::Time enemy_response_time;

    // Random
    std::random_device rd;
    std::mt19937 rng;

    // Paddle
    float m_paddle_width;
    float m_paddle_height;
    float m_paddle_speed;

    // Player
    sf::RectangleShape *player_paddle;
    float m_player_speed;

    // Enemy
    sf::RectangleShape *enemy_paddle;
    float m_enemy_speed;

    // Ball
    sf::CircleShape *ping_pong_ball; // Ball
    float m_ball_radius;
    float m_ball_speed;
    sf::Angle ball_angle;
};