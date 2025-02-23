#include "Game.h"

Game::Game()
{
    initWindow();
    intiConst();
    initPlayer();
    initEnemy();
    initBall();
}

Game::~Game()
{
    delete player_paddle;
    delete enemy_paddle;
    delete ping_pong_ball;
    delete m_window;
}

void Game::run()
{
    while (m_window->isOpen())
    {
        delta_time = clock.restart();

        pollEvents();
        update();
        render();
    }
}

void Game::initWindow()
{
    m_window_width = 900;
    m_window_height = 600;
    m_title = "Ping Pong Ball";
    m_vm = sf::VideoMode({m_window_width, m_window_height});
    m_window = new sf::RenderWindow(m_vm, sf::String(m_title));

    m_window->setFramerateLimit(60);
    m_window->setPosition(sf::Vector2i{250, 20});
}

void Game::intiConst()
{
    // Random
    rng = std::mt19937(rd());

    // Paddle
    m_paddle_width = 25;
    m_paddle_height = 100;
    m_paddle_speed = 400;

    // Ball
    m_ball_radius = 15;
    m_ball_speed = 400;
}

void Game::initPlayer()
{
    player_paddle = new sf::RectangleShape(sf::Vector2f{m_paddle_width - 6.0f, m_paddle_height - 6.0f});
    player_paddle->setOrigin(player_paddle->getGeometricCenter());
    player_paddle->setOutlineThickness(3.0f);

    // Position
    player_paddle->setPosition(sf::Vector2f{10.0f + m_paddle_width / 2.0f, m_window_height / 2.0f});

    // Speed
    m_player_speed = m_paddle_speed;

    // Colors
    player_paddle->setFillColor(sf::Color(255, 172, 28));
    player_paddle->setOutlineColor(sf::Color(0, 0, 0));
}

void Game::initEnemy()
{
    enemy_paddle = new sf::RectangleShape(sf::Vector2f{m_paddle_width - 6.0f, m_paddle_height - 6.0f});
    enemy_paddle->setOrigin(enemy_paddle->getGeometricCenter());
    enemy_paddle->setOutlineThickness(3.0f);

    // Position
    enemy_paddle->setPosition(sf::Vector2f{m_window_width - m_paddle_width / 2.0f - 10.0f, m_window_height / 2.0f});

    // Speed
    m_enemy_speed = m_paddle_speed;

    // Timer
    enemy_response_time = sf::seconds(0.1f);

    // Colors
    enemy_paddle->setFillColor(sf::Color(65, 105, 225));
    enemy_paddle->setOutlineColor(sf::Color(0, 0, 0));
}

void Game::initBall()
{
    ping_pong_ball = new sf::CircleShape(m_ball_radius - 6.0f);
    ping_pong_ball->setOrigin(ping_pong_ball->getGeometricCenter());
    ping_pong_ball->setOutlineThickness(3.0f);

    // Postion
    ping_pong_ball->setPosition(sf::Vector2f{m_window_width / 2.0f, m_window_height / 2.0f});

    // Angle
    do
    {
        ball_angle = sf::degrees(std::uniform_real_distribution<float>(0, 360)(rng));
    } while (std::abs(std::cos(ball_angle.asRadians())) <= 0.7);

    // Colors
    ping_pong_ball->setFillColor(sf::Color(255, 255, 255));
    ping_pong_ball->setOutlineColor(sf::Color(0, 0, 0));
}

void Game::pollEvents()
{
    while (const std::optional event = m_window->pollEvent())
    {
        if (event->is<sf::Event::Closed>())
        {
            m_window->close();
            break;
        }

        if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
        {
            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
            {
                m_window->close();
                break;
            }
        }
    }
}

void Game::update()
{
    updatePlayer();
    updateEnemy();
    updateBall();
}

void Game::updatePlayer()
{
    sf::Vector2f vrequest_player_position{0.0f, 0.0f};

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Up))
    {
        vrequest_player_position = (player_paddle->getPosition().y - m_paddle_height / 2.0f <= 3.0f) ? sf::Vector2f(0.0f, 0.0f) : sf::Vector2f(0.0f, -1.0f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Scancode::Down))
    {
        vrequest_player_position = (player_paddle->getPosition().y + m_paddle_height / 2.0f >= m_window_height - 3.0f) ? sf::Vector2f(0.0f, 0.0f) : sf::Vector2f(0.0f, 1.0f);
    }

    player_paddle->move(vrequest_player_position * m_player_speed * delta_time.asSeconds());
}

void Game::updateEnemy()
{
    // Enemy Movement
    if ((m_enemy_speed < 0 && enemy_paddle->getPosition().y - m_paddle_height / 2.0f >= 3.0f) ||
        (m_enemy_speed > 0 && enemy_paddle->getPosition().y + m_paddle_height / 2.0f <= m_window_height - 3.0f))
    {
        enemy_paddle->move(sf::Vector2f{0.0f, m_enemy_speed * delta_time.asSeconds()});
    }

    // Enemy Response
    if (enemy_timer.getElapsedTime() > enemy_response_time)
    {
        enemy_timer.restart();
        // Enemy Movement With Respect to the Ball
        if (enemy_paddle->getPosition().y < ping_pong_ball->getPosition().y - m_ball_radius)
        {
            m_enemy_speed = m_paddle_speed;
        }
        else if (enemy_paddle->getPosition().y > ping_pong_ball->getPosition().y + m_ball_radius)
        {
            m_enemy_speed = -m_paddle_speed;
        }
        else
        {
            m_enemy_speed = 0.0f;
        }
    }
}

void Game::updateBall()
{
    sf::Angle dist = sf::degrees(std::uniform_real_distribution<float>(0, 25)(rng));

    // Ball Movements
    ping_pong_ball->move(sf::Vector2f{m_ball_speed * delta_time.asSeconds(), ball_angle});

    // Ball Collision With Screens
    if (ping_pong_ball->getPosition().y - m_ball_radius <= 3.0f) // Collision with top screen
    {
        ball_angle = -ball_angle;
        ping_pong_ball->setPosition(sf::Vector2f{ping_pong_ball->getPosition().x, m_ball_radius + 0.1f});
    }
    else if (ping_pong_ball->getPosition().y + m_ball_radius >= m_window_height - 3.0f) // Collision with bototm screen
    {
        ball_angle = -ball_angle;
        ping_pong_ball->setPosition(sf::Vector2f{ping_pong_ball->getPosition().x, m_window_height - m_ball_radius - 0.1f});
    }
    if (ping_pong_ball->getPosition().x - m_ball_radius <= 3.0f) // Collision with Left Screen
    {
        std::cout << "You Lose!" << std::endl;
    }
    else if (ping_pong_ball->getPosition().x + m_ball_radius >= m_window_width - 3.0f) // Collision with Right Screen
    {
        std::cout << "You Won!" << std::endl;
    }

    // Ball Collision with Paddles
    // Coillision with Player Paddle
    if (ping_pong_ball->getPosition().y + m_ball_radius >= player_paddle->getPosition().y - m_paddle_height / 2.0f &&
        ping_pong_ball->getPosition().y - m_ball_radius <= player_paddle->getPosition().y + m_paddle_height / 2.0f &&
        ping_pong_ball->getPosition().x - m_ball_radius <= player_paddle->getPosition().x + m_paddle_width / 2.0f + 2.0f)
    {
        if (ball_angle > sf::degrees(0))
        {
            ball_angle = sf::degrees(180) - ball_angle + dist;
        }
        else
        {
            ball_angle = sf::degrees(180) - ball_angle - dist;
        }

        ping_pong_ball->setPosition(sf::Vector2f{player_paddle->getPosition().x + m_paddle_width / 2.0f + m_ball_radius + 0.1f, ping_pong_ball->getPosition().y});
    }

    // Collision with Enemy Paddle
    else if (ping_pong_ball->getPosition().y + m_ball_radius >= enemy_paddle->getPosition().y - m_paddle_height / 2.0f &&
             ping_pong_ball->getPosition().y - m_ball_radius <= enemy_paddle->getPosition().y + m_paddle_height / 2.0f &&
             ping_pong_ball->getPosition().x + m_ball_radius >= enemy_paddle->getPosition().x - m_paddle_width / 2.0f - 2.0f)
    {
        if (ball_angle > sf::degrees(0))
        {
            ball_angle = sf::degrees(180) - ball_angle - dist;
        }
        else
        {
            ball_angle = sf::degrees(180) - ball_angle + dist;
        }

        ping_pong_ball->setPosition(sf::Vector2f{enemy_paddle->getPosition().x - m_paddle_width / 2.0f - m_ball_radius - 0.1f, ping_pong_ball->getPosition().y});
    }
}

void Game::render()
{
    m_window->clear(sf::Color(86, 86, 86));

    // Render Objects
    m_window->draw(*player_paddle);
    m_window->draw(*enemy_paddle);
    m_window->draw(*ping_pong_ball);

    m_window->display();
}
