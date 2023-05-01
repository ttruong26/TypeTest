//
// Created by Tyler Truong  on 3/23/22.
//

#ifndef TEXTINPUT_PROJECT_LABEL_H
#define TEXTINPUT_PROJECT_LABEL_H

#include "SFML/Graphics.hpp"
#include "../FontHandling/Fonts.h"

class Label : public sf::Text{
public:
    Label();
    Label(float xPos, float yPos);
};


#endif //TEXTINPUT_PROJECT_LABEL_H
