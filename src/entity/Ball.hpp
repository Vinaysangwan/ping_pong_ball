#pragma once

#include <cmath>

#include "../common.hpp"
#include "../game_manager/GameManager.hpp"
#include "../randomize/Randomize.hpp"

class Ball : public sf::CircleShape
{
private:
    // Private Function

    // Init Functions
    void init_Variables();
    void initRandomize();
    void init_Ball();
    void initBallAngle();

    void moveBall(float delta_time);

public:
    // Public Function

    Ball();
    ~Ball();

    // Main Ball Functions
    void update_Ball(float delta_time);

    void getEntitySize(sf::Vector2f player_size, sf::Vector2f enemy_size);

    void getPlayerPosition(sf::Vector2f player_position);
    void getEnemyPosition(sf::Vector2f enemy_position);

private:
    // Private Member

    // Ball
    float ball_radius;

    sf::Color ball_color;

    float ball_speed;

    sf::Angle ball_angle;

    // Randomize
    Randomize *random_init_angle;
    Randomize *random_after_collide;

    // Player
    sf::Vector2f player_size;
    sf::Vector2f player_position;

    // Enemy
    sf::Vector2f enemy_size;
    sf::Vector2f enemy_position;
};