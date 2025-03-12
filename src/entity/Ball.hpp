#pragma once

#include "../common.hpp"

class Ball
{
private:
    // Private Function

    // Init Functions
    void init_Variables();
    void init_Ball();

public:
    // Public Function

    Ball();
    ~Ball();

    // Main Ball Functions
    void update_Ball();
    void render_Ball(sf::RenderWindow *window);

private:
    // Private Member

    // Ball
    sf::CircleShape *ball;
    float ball_radius;

    sf::Color ball_color;

    float ball_speed;
};