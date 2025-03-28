#include "Ball.hpp"

void Ball::init_Variables()
{
    // Set Ball Radius
    ball_radius = 10.0f;

    // Set Ball Color
    ball_color = sf::Color(255, 255, 255);

    // Set Ball Speed
    this->ball_speed = entity_ball_speed;

    // Sound Address
    collision_sound_address = "assets/sounds/ball.wav";
}

// Initialzie Sounds
void Ball::init_Sounds()
{
    // Init Sound Buffers

    // Collision Sound
    collision_sound_buffer = new sf::SoundBuffer(collision_sound_address);
    collision_sound = new sf::Sound(*collision_sound_buffer);
}

// Initialize Randomize
void Ball::initRandomize()
{
    // Initial Random Angle for the ball
    random_init_angle = new Randomize();
}

void Ball::init_Ball()
{
    // Initialize the ball & Set Outline Thickness
    this->setRadius(ball_radius - 3.0f);
    this->setOutlineThickness(3.0f);

    // Set Ball Origin & Position
    this->setOrigin(sf::Vector2f{this->getRadius(), this->getRadius()});
    this->setPosition(sf::Vector2f{window_size} / 2.0f);

    // Apply Ball Color
    this->setFillColor(ball_color);
    this->setOutlineColor(sf::Color(0, 0, 0));
}

// Initialize Ball Angle
void Ball::initBallAngle()
{
    // Set Random Ball Angle between (45 - 135)

    float random_angle = 0.0f;

    do
    {
        random_init_angle->randomizeFloat(0, 360);
        random_angle = random_init_angle->getRandomFloat();
    } while (std::abs(std::cos(random_angle)) <= 0.707);

    ball_angle = sf::degrees(random_angle);
}

// Move Ball
void Ball::moveBall(float delta_time)
{
    // Init Random When Collision addition
    random_after_collide = new Randomize();
    random_after_collide->randomizeFloat(0, 25);

    // Move Ball
    this->move(sf::Vector2f{this->ball_speed * delta_time, ball_angle});

    // To detect Collision with top and bottom screen of the window
    if (this->getPosition().y - ball_radius <= 0.0f)
    {
        collision_sound->play();
        ball_angle *= -1;
        this->setPosition(sf::Vector2f{this->getPosition().x, ball_radius + 0.1f});
    }
    else if (this->getPosition().y + ball_radius >= window_size.y)
    {
        collision_sound->play();
        ball_angle *= -1;
        this->setPosition(sf::Vector2f{this->getPosition().x, window_size.y - ball_radius - 0.1f});
    }

    // When Collide with left & Right screen
    if (this->getPosition().x - ball_radius <= 0.0f)
    {
        enemy_score++;
        initBallAngle();
        this->setPosition(sf::Vector2f{window_size} / 2.0f);
    }
    else if (this->getPosition().x + ball_radius >= window_size.x)
    {
        player_score++;
        initBallAngle();
        this->setPosition(sf::Vector2f{window_size} / 2.0f);
    }

    // Collision with the Player
    if (this->getPosition().y + ball_radius >= player_position.y - player_size.y &&
        this->getPosition().y - ball_radius <= player_position.y + player_size.y &&
        this->getPosition().x - ball_radius <= player_position.x + player_size.x &&
        this->getPosition().x - ball_radius >= player_position.x)
    {
        if (this->getPosition().y > player_position.y)
        {
            ball_angle = sf::degrees(180) - ball_angle + sf::degrees(random_after_collide->getRandomFloat());
        }
        else
        {
            ball_angle = sf::degrees(180) - ball_angle - sf::degrees(random_after_collide->getRandomFloat());
        }
        collision_sound->play();

        this->setPosition(sf::Vector2f{player_position.x + player_size.x + ball_radius + 0.1f, this->getPosition().y});
    }

    // Collision with the Enemy
    if (this->getPosition().y + ball_radius >= enemy_position.y - enemy_size.y &&
        this->getPosition().y - ball_radius <= enemy_position.y + enemy_size.y &&
        this->getPosition().x - ball_radius >= enemy_position.x - enemy_size.x &&
        this->getPosition().x - ball_radius <= enemy_position.x)
    {
        if (this->getPosition().y > enemy_position.y)
        {
            ball_angle = sf::degrees(180) - ball_angle + sf::degrees(random_after_collide->getRandomFloat());
        }
        else
        {
            ball_angle = sf::degrees(180) - ball_angle - sf::degrees(random_after_collide->getRandomFloat());
        }
        collision_sound->play();

        this->setPosition(sf::Vector2f{enemy_position.x - enemy_size.x - ball_radius - 0.1f, this->getPosition().y});
    }
}

// Constructor
Ball::Ball()
{
    init_Variables();
    init_Sounds();
    initRandomize();
    initBallAngle();
    init_Ball();
}

// Destructor
Ball::~Ball()
{
    delete collision_sound;
    delete collision_sound_buffer;
    delete random_init_angle;
}

// Update Ball
void Ball::update_Ball(float delta_time)
{

    moveBall(delta_time);
}

// Get Entity Size(Player Size, Enemy Size)
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
