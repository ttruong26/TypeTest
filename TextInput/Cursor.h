//
// Created by Tyler Truong  on 3/23/22.
//

#ifndef TEXTINPUT_PROJECT_CURSOR_H
#define TEXTINPUT_PROJECT_CURSOR_H

#include "SFML/Graphics.hpp"
#include "../FontHandling/Fonts.h"
#include "../States.h"

class Cursor : public sf::Text {
public:
    Cursor();
    Cursor(float xPos, float yPos);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void update();
    States& getState();
    void hideCursor();
    void showCursor();
    void setPosition(sf::Vector2f coords);
    void setFillColor(sf::Color color);
private:
    sf::Text _cursor;
    sf::Clock _clock;
    sf::Time _delay = sf::milliseconds(400);
    bool _show;
    States s;
};


#endif //TEXTINPUT_PROJECT_CURSOR_H
