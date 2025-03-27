#include "Enemy.hpp"

void Enemy::init_Variables()
{
    // Set Enemy Size
    enemy_size.x = 30.0f;  // Width
    enemy_size.y = 120.0f; // Height

    // Set Enemy Color
    enemy_color = sf::Color(0x0CAFFF);

    // Enemy Speed
    enemy_speed = 300.0f;
}

void Enemy::init_Enemy()
{
    // Initialize the Enemy & Set Outline Thickness
    this->setSize(this->enemy_size - sf::Vector2f{6.0f, 6.0f});
    this->setOutlineThickness(3.0f);

    // Set Enemy Origin & Position
    this->setOrigin(this->getSize() / 2.0f);
    this->setPosition(sf::Vector2f{795.0f - enemy_size.x / 2.0f, 300.0f});

    // Set Enemy Color
    this->setFillColor(this->enemy_color);
    this->setOutlineColor(sf::Color(0, 0, 0));
}

Enemy::Enemy()
{
    init_Variables();
    init_Enemy();
}

Enemy::~Enemy()
{
}

void Enemy::update_Enemy()
{
}

void Enemy::getBallRadius(sf::Vector2f ball_radius)
{
    this->ball_radius = ball_radius;
}

void Enemy::getBallPosition(sf::Vector2f ball_position)
{
    this->ball_position = ball_position;
}
