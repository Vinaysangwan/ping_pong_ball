#include "Player.hpp"

void Player::init_Variables()
{
    // Set Player Size
    this->player_size.x = 30;  // Width
    this->player_size.y = 120; // Height

    // Set Player Color
    this->player_color = sf::Color(255, 176, 0);

    // Set Player Speed
    this->player_speed = 300.0f;
}

void Player::init_Player()
{
    // Initialize the Player & Set Thickness
    this->player = new sf::RectangleShape(this->player_size - sf::Vector2f(6.0f, 6.0f));
    this->player->setOutlineThickness(3.0f);

    // Set Player Origin & Position
    this->player->setOrigin(sf::Vector2f{player->getSize().x / 2.0f, player->getSize().y / 2.0f});
    this->player->setPosition(sf::Vector2f{player->getSize().x / 2.0f + 8.0f, 300.0f});

    // Set Player Color
    this->player->setFillColor(this->player_color);
    this->player->setOutlineColor(sf::Color(0, 0, 0));
}

void Player::player_Movement(float delta_time)
{
    // Moving Player UP(W) & Down(S)

    sf::Vector2f request_player_movement(0.0f, 0.0f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::W))
    {
        request_player_movement += sf::Vector2f(0.0f, -1.0f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::S))
    {
        request_player_movement += sf::Vector2f(0.0f, 1.0f);
    }

    this->player->move(request_player_movement * this->player_speed * delta_time);
}

Player::Player()
{
    this->init_Variables();
    this->init_Player();
}

Player::~Player()
{
    delete this->player;
}

void Player::update_Player(float delta_time)
{
    this->player_Movement(delta_time);
}

void Player::render_Player(sf::RenderWindow *window)
{
    window->draw(*this->player);
}
