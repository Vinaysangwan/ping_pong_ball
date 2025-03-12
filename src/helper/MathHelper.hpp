#pragma once

#include <cmath>
#include "../common.hpp"

namespace MATH_HELPER
{
    float length(sf::Vector2f &vect)
    {
        return std::sqrt(vect.x * vect.x + vect.y * vect.y);
    }

    sf::Vector2f vectorNormalization(sf::Vector2f &vect)
    {
        float len = length(vect);
        return sf::Vector2f(vect.x / len, vect.y / len);
    }
}