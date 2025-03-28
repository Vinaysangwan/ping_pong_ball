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

void Texts::stream_string_float(std::string str, float num)
{
    std::stringstream sstream;
    sstream << str << num;
    this->setString(sstream.str());
}

void Texts::stream_string_int(std::string str, int num)
{
    std::stringstream sstream;
    sstream << str << num;
    this->setString(sstream.str());
}

void Texts::stream_int_string(int num, std::string str)
{
    std::stringstream sstream;
    sstream << num << str;
    this->setString(sstream.str());
}
