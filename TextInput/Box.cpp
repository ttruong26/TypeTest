//
// Created by Tyler Truong  on 3/23/22.
//

#include "Box.h"

Box::Box() {
    sf::RectangleShape::setOutlineColor(sf::Color::Black);
    sf::RectangleShape::setFillColor(sf::Color::White);
    sf::RectangleShape::setOutlineThickness(5);
}

Box::Box(float xPos, float yPos, float xSize, float ySize) : Box() {
    sf::RectangleShape::setSize({xSize, ySize});
    sf::RectangleShape::setPosition({xPos, yPos});
}

/*
void Box::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(rec);
}
 */
