//
// Created by Tyler Truong  on 3/22/22.
//

#include "Fonts.h"

std::map<FontNames, sf::Font> Fonts::fonts;

void Fonts::loadFont(FontNames fontName) {
    //Error statement to handle font loading
    if(!fonts[fontName].loadFromFile(getFontPath(fontName))) {
        exit(28);
    }
}

std::string Fonts::getFontPath(FontNames fontName) {
    switch(fontName) {
        case Arial: return "FontHandling/Arial.ttf";
    }
}

sf::Font &Fonts::getFont(FontNames fontNames) {
    loadFont(fontNames);
    return fonts[fontNames];
}