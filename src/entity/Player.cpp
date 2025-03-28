#include "Player.hpp"

void Player::init_Variables()
{
    // Set Player Size
    player_size.x = 30;  // Width
    player_size.y = 120; // Height

    // Set Player Color
    player_color = sf::Color(255, 176, 0);

    // Set Player Speed
    player_speed = entity_speed;
}

void Player::init_Player()
{
    // Initialize the Player & Set Thickness
    this->setSize(player_size - sf::Vector2f(6.0f, 6.0f));
    this->setOutlineThickness(3.0f);

    // Set Player Origin & Position
    this->setOrigin(this->getSize() / 2.0f);
    this->setPosition(sf::Vector2f{this->getSize().x / 2.0f + 8.0f, 300.0f});

    // Set Player Color
    this->setFillColor(this->player_color);
    this->setOutlineColor(sf::Color(0, 0, 0));
}

void Player::player_Movement(float delta_time)
{
    // Moving Player UP(W) & Down(S)

    sf::Vector2f request_player_movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W) && this->getPosition().y - player_size.y / 2.0f > 5.0f)
    {
        request_player_movement += sf::Vector2f(0.0f, -1.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S) && this->getPosition().y + player_size.y / 2.0f < window_size.y - 5.0f)
    {
        request_player_movement += sf::Vector2f(0.0f, 1.0f);
    }

    this->move(request_player_movement * this->player_speed * delta_time);
}

Player::Player()
{
    this->init_Variables();
    this->init_Player();
}

Player::~Player()
{
}

void Player::update_Player(float delta_time)
{

    this->player_Movement(delta_time);
}