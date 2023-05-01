//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_TYPING_H
#define TEXTINPUT_PROJECT_TYPING_H

#include <SFML/Graphics.hpp>
#include "../FontHandling/Fonts.h"
#include "MultiText.h"
#include "../Static_Classes/ColorCode.h"

class Typing : public sf::Drawable{
private:
    Multitext text;
    bool charTyped = false;
public:
    Typing();
    Typing(float xPos, float yPos);

    bool isEmpty() const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);
    void update();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    sf::FloatRect getGlobalBounds();

};


#endif //TEXTINPUT_PROJECT_TYPING_H
