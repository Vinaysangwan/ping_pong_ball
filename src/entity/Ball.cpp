#include "Ball.hpp"

void Ball::init_Variables()
{
    // Set Ball Radius
    ball_radius = 10.0f;

    // Set Ball Color
    ball_color = sf::Color(255, 255, 255);

    // Set Ball Speed
    ball_speed = 300.0f;
}

void Ball::init_Ball()
{
    // Initialize the ball & Set Outline Thickness
    this->setRadius(ball_radius - 3.0f);
    this->setOutlineThickness(3.0f);

    // Set Ball Origin & Position
    this->setOrigin(sf::Vector2f{this->getRadius(), this->getRadius()});
    this->setPosition(sf::Vector2f{400.0f, 300.0f});

    // Apply Ball Color
    this->setFillColor(ball_color);
    this->setOutlineColor(sf::Color(0, 0, 0));
}

void Ball::moveBall()
{
}

bool Ball::detectCollision() const
{
    return false;
}

Ball::Ball()
{
    init_Variables();
    init_Ball();
}

Ball::~Ball()
{
}

void Ball::update_Ball()
{
}

void Ball::getEntitySize(sf::Vector2f player_size, sf::Vector2f enemy_size)
{
    this->player_size = player_size;
    this->enemy_size = enemy_size;
}

void Ball::getPlayerPosition(sf::Vector2f player_position)
{
    this->player_position = player_position;
}

void Ball::getEnemyPosition(sf::Vector2f enemy_position)
{
    this->enemy_position = enemy_position;
}
