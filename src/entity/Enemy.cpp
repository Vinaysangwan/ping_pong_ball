#include "Enemy.hpp"

// ********************************************************************************************************
// ************************************************* Private Functions ************************************
// ********************************************************************************************************

// Initialize Variables
void Enemy::init_Variables()
{
    // Set Enemy Size
    enemy_size = entity_enemy_size;

    // Set Enemy Color
    enemy_color = sf::Color(0x0CAFFF);

    // Enemy Speed
    enemy_speed = entity_speed;

    // Enemy Reaction Time
    enemy_reaction_time = sf::seconds(0.1f);

    // Enemy Time
    enemy_time = new sf::Clock();
}

// Initialize Enemy
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

// Enemy Movement
void Enemy::moveEnemy(float delta_time)
{
    // Enemy Only move when between the top and bottom window
    if (((enemy_speed < 0.0f) && (this->getPosition().y - enemy_size.y / 2.0f > 5.0f)) ||
        ((enemy_speed > 0.0f) && (this->getPosition().y + enemy_size.y / 2.0f < window_size.y - 5.0f)))
    {
        this->move(sf::Vector2f{0.0f, enemy_speed * delta_time});
    }

    if (enemy_time->getElapsedTime() > enemy_reaction_time)
    {
        enemy_time->restart();
        if (ball_position.y + entity_ball_radius <= this->getPosition().y)
        {
            enemy_speed = -entity_speed;
        }
        else if (ball_position.y - entity_ball_radius >= this->getPosition().y)
        {
            enemy_speed = entity_speed;
        }
        else
        {
            enemy_speed = 0.0f;
        }
    }
}

// ********************************************************************************************************
// ************************************************* Public Functions *************************************
// ********************************************************************************************************

// Constructor
Enemy::Enemy()
{
    init_Variables();
    init_Enemy();
}

// Destructor
Enemy::~Enemy()
{
    delete enemy_time;
}

// Update Function
void Enemy::update_Enemy(float delta_time)
{

    moveEnemy(delta_time);
}

// Function To get Ball Position
void Enemy::getBallPosition(sf::Vector2f ball_position)
{
    this->ball_position = ball_position;
}
