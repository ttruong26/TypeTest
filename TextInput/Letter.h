//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_LETTER_H
#define TEXTINPUT_PROJECT_LETTER_H

#include <SFML/Graphics.hpp>
#include <string>
#include "../FontHandling/Fonts.h"

class Letter : public sf::Text {
public:
    Letter();
    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition();
private:
    float xPos, yPos;
};

#endif //TEXTINPUT_PROJECT_LETTER_H
