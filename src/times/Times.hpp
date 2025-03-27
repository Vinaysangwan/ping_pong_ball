#pragma once

#include "../common.hpp"

class Times
{
private:
    // Private Functions

public:
    // Public Functions

    // Constructors & Destructors
    Times();
    ~Times();

    // Main Times Functions
    void nextDeltaTime();

    // Return Functions
    float getDeltaTime() const;
    int getDtEpoch();

private:
    // Private Members

    // Clock
    sf::Clock clock;
    float delta_time;
};