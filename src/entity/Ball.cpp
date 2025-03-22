#include "Ball.hpp"

void Ball::init_Variables()
{
    // Set Ball Radius
    this->ball_radius = 10.0f;

    // Set Ball Color
    this->ball_color = sf::Color(255, 255, 255);

    // Set Ball Speed
    this->ball_speed = 300.0f;
}

void Ball::init_Ball()
{
    // Initialize the ball & Set Outline Thickness
    this->ball = new sf::CircleShape(this->ball_radius - 3.0f);
    this->ball->setOutlineThickness(3.0f);

    // Set Ball Origin & Position
    this->ball->setOrigin(sf::Vector2f{this->ball->getRadius(), this->ball->getRadius()});
    this->ball->setPosition(sf::Vector2f{400.0f, 300.0f});

    // Apply Ball Color
    this->ball->setFillColor(this->ball_color);
    this->ball->setOutlineColor(sf::Color(0, 0, 0));
}

Ball::Ball()
{
    this->init_Variables();
    this->init_Ball();
}

Ball::~Ball()
{
    delete this->ball;
}

void Ball::update_Ball()
{
}

void Ball::render_Ball(sf::RenderWindow &window)
{
    window.draw(*this->ball);
}
