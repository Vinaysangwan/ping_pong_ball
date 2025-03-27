#pragma once

#include <random>

#include "../common.hpp"
#include "../times/Times.hpp"

class Randomize
{
private:
    // Private Functions
    void initRandomEngine();

public:
    // Public Functions

    // Constructors & Destructors
    Randomize();
    ~Randomize();

    // Main Randomize Functions
    void randomizeInt(int min, int max);
    void randomizeFloat(float min, float max);

    // Return Functions
    int getRandomInt();
    float getRandomFloat();

private:
    // Private Members

    // Times
    Times time;

    // Random Engine
    std::default_random_engine random_engine;

    std::uniform_int_distribution<int> random_int;
    std::uniform_real_distribution<float> random_float;
};