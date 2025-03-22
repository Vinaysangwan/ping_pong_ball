#pragma once

#include "../common.hpp"

class Enemy
{
private:
    // Parivate Functions

    // Init Functions
    void init_Variables();
    void init_Enemy();

public:
    // Public Functions

    Enemy();
    ~Enemy();

    // Main Enemy Functions
    void update_Enemy();
    void render_Enemy(sf::RenderWindow &window);

private:
    // Private Memebers

    // Enemy
    sf::RectangleShape *enemy;
    sf::Vector2f enemy_size;
    sf::Color enemy_color;

    float enemy_speed;
};