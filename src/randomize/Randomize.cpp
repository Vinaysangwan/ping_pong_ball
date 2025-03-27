#include "Randomize.hpp"

void Randomize::initRandomEngine()
{
    random_engine.seed(time.getDtEpoch());
}

Randomize::Randomize()
{
    initRandomEngine();
}

Randomize::~Randomize()
{
}

void Randomize::randomizeInt(int min, int max)
{
    random_int = std::uniform_int_distribution<int>(min, max);
}

void Randomize::randomizeFloat(float min, float max)
{
    random_float = std::uniform_real_distribution<float>(min, max);
}

int Randomize::getRandomInt()
{
    return random_int(random_engine);
}

float Randomize::getRandomFloat()
{
    return random_float(random_engine);
}
