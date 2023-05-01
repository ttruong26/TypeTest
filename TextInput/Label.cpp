//
// Created by Tyler Truong  on 3/23/22.
//

#include "Label.h"

Label::Label() {
    sf::Text::setFont(Fonts::getFont(Arial));
    sf::Text::setFillColor(sf::Color::White);
    sf::Text::setCharacterSize(35);
    sf::Text::setStyle(1);
}

Label::Label(float xPos, float yPos) : Label(){
    sf::Text::setPosition({xPos, yPos});
}