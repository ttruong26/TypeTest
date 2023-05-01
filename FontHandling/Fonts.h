//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_FONTS_H
#define TEXTINPUT_PROJECT_FONTS_H

#include "FontNames.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <cstdlib>

// Helper Font class to load font into SFML
class Fonts {
private:
    static std::map<FontNames, sf::Font> fonts;
    static void loadFont(FontNames fontName);
    static std::string getFontPath(FontNames fontName);
public:
    static sf::Font& getFont(FontNames fontNames);
};


#endif //TEXTINPUT_PROJECT_FONTS_H
