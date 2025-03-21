#include "Times.hpp"

Times::Times()
{
    nextDeltaTime();
}

Times::~Times()
{
}

void Times::nextDeltaTime()
{
    delta_time = clock.restart().asSeconds();
}

float Times::getDeltaTime() const
{
    return delta_time;
}
