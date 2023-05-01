//
// Created by Tyler Truong  on 3/22/22.
//

#include "Letter.h"

Letter::Letter() {
    sf::Text::setFont(Fonts::getFont(Arial));
    sf::Text::setFillColor(sf::Color::Black);
    sf::Text::setString("");
}

void Letter::setPosition(sf::Vector2f pos) {
    xPos = pos.x;
    yPos = pos.y;
    sf::Text::setPosition(pos);
}

sf::Vector2f Letter::getPosition() {
    return {xPos, yPos};
}
