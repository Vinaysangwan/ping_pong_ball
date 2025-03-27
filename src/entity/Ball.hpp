#pragma once

#include "../common.hpp"
#include "../game_manager/GameManager.hpp"

class Ball : public sf::CircleShape
{
private:
    // Private Function

    // Init Functions
    void init_Variables();
    void init_Ball();

    void moveBall();

    bool detectCollision() const;

public:
    // Public Function

    Ball();
    ~Ball();

    // Main Ball Functions
    void update_Ball();

    void getEntitySize(sf::Vector2f player_size, sf::Vector2f enemy_size);

    void getPlayerPosition(sf::Vector2f player_position);
    void getEnemyPosition(sf::Vector2f enemy_position);

private:
    // Private Member

    // Ball
    float ball_radius;

    sf::Color ball_color;

    float ball_speed;

    // Player
    sf::Vector2f player_size;
    sf::Vector2f player_position;

    // Enemy
    sf::Vector2f enemy_size;
    sf::Vector2f enemy_position;
};