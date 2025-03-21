#include "Enemy.hpp"

void Enemy::init_Variables()
{
    // Set Enemy Size
    this->enemy_size.x = 30.0f;  // Width
    this->enemy_size.y = 120.0f; // Height

    // Set Enemy Color
    this->enemy_color = sf::Color(0x0CAFFF);

    // Enemy Speed
    this->enemy_speed = 300.0f;
}

void Enemy::init_Enemy()
{
    // Initialize the Enemy & Set Outline Thickness
    this->enemy = new sf::RectangleShape(this->enemy_size - sf::Vector2f{6.0f, 6.0f});
    this->enemy->setOutlineThickness(3.0f);

    // Set Enemy Origin & Position
    this->enemy->setOrigin(sf::Vector2f{this->enemy->getSize().x / 2.0f, this->enemy->getSize().y / 2.0f});
    this->enemy->setPosition(sf::Vector2f{795.0f - this->enemy_size.x / 2.0f, 300.0f});

    // Set Enemy Color
    this->enemy->setFillColor(this->enemy_color);
    this->enemy->setOutlineColor(sf::Color(0, 0, 0));
}

Enemy::Enemy()
{
    this->init_Variables();
    this->init_Enemy();
}

Enemy::~Enemy()
{
    delete this->enemy;
}

void Enemy::update_Enemy()
{
}

void Enemy::render_Enemy(sf::RenderWindow *window)
{
    window->draw(*this->enemy);
}
