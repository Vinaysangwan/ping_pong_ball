#pragma once

#include <string.h>

#include "../common.hpp"

class Fonts : public sf::Font
{
private:
    // Private Functions
    void initFonts(std::string address);

public:
    // Public Functions

    // Constructors & Destructors
    Fonts(std::string address);
    ~Fonts();

    // Main Fonts Functions

private:
    // Private Members
};