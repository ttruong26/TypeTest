//
// Created by Tyler Truong  on 3/23/22.
//

#ifndef TEXTINPUT_PROJECT_BOX_H
#define TEXTINPUT_PROJECT_BOX_H

#include "SFML/Graphics.hpp"

class Box : public sf::RectangleShape{
public:
    Box();
    Box(float xPos, float yPos, float xSize, float ySize);
    //virtual void draw(sf::RenderTarget &window, sf:: RenderStates states) const;

private:
};


#endif //TEXTINPUT_PROJECT_BOX_H
