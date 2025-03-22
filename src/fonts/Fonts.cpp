#include "Fonts.hpp"

void Fonts::initFonts(std::string address)
{
    if (!this->openFromFile(address))
    {
        std::cerr << "ERROR::FONTS::initFonts: couldn't open the font file." << std::endl;
    }

    this->setSmooth(false);
}

Fonts::Fonts(std::string address)
{
    initFonts(address);
}

Fonts::~Fonts()
{
}
