#include "Texts.hpp"

void Texts::initFont(std::string font_address)
{
    font = new Fonts(font_address);
    this->setFont(*font);
}

void Texts::initString(std::string str)
{
    original_string = str;

    this->setString(original_string);
}

Texts::Texts(std::string str, std::string font_address)
    : sf::Text(*font)
{
    initFont(font_address);
    initString(str);
}

Texts::~Texts()
{
    delete font;
}

void Texts::stream_string(std::string str)
{
    this->setString(str);
}

void Texts::stream_string_num(std::string str, float num)
{
    std::stringstream sstream;
    sstream << str << num;
    this->setString(sstream.str());
}
