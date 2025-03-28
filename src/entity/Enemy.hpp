#pragma once

#include "../common.hpp"
#include "../game_manager/GameManager.hpp"

class Enemy : public sf::RectangleShape
{
private:
    // Parivate Functions

    // Init Functions
    void init_Variables();
    void init_Enemy();

    void moveEnemy(float delta_time);

public:
    // Public Functions

    Enemy();
    ~Enemy();

    // Main Enemy Functions
    void update_Enemy(float delta_time);

    void getBallPosition(sf::Vector2f ball_position);

private:
    // Private Memebers

    // Enemy
    sf::Vector2f enemy_size;
    sf::Color enemy_color;

    float enemy_speed;

    // Ball
    sf::Vector2f ball_position;

    sf::Time enemy_reaction_time;
    sf::Clock *enemy_time;
};