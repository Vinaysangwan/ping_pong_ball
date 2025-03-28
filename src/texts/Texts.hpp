#pragma once

#include <sstream>

#include "../common.hpp"
#include "../fonts/Fonts.hpp"

class Texts : public sf::Text
{
private:
    // Private Functions
    void initFont(std::string font_address);
    void initString(std::string str);

public:
    // Public Functions

    // Constructors & Destructors
    Texts(std::string str, std::string font_address);
    ~Texts();

    // Main Texts Functions
    void stream_string(std::string str);
    void stream_string_float(std::string str, float num);
    void stream_string_int(std::string str, int num);
    void stream_int_string(int num, std::string str);

private:
    // Private Members

    // String
    std::string original_string;

    // Fonts
    Fonts *font;
};