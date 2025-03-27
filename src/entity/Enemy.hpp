#pragma once

#include "../common.hpp"

class Enemy : public sf::RectangleShape
{
private:
    // Parivate Functions

    // Init Functions
    void init_Variables();
    void init_Enemy();

    void moveEnemy();

public:
    // Public Functions

    Enemy();
    ~Enemy();

    // Main Enemy Functions
    void update_Enemy();

    void getBallRadius(float ball_radius);
    void getBallPosition(sf::Vector2f ball_position);

private:
    // Private Memebers

    // Enemy
    sf::Vector2f enemy_size;
    sf::Color enemy_color;

    float enemy_speed;

    // Ball
    float ball_radius;
    sf::Vector2f ball_position;
};