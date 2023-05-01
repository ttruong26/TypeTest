//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_EVENTHANDLER_H
#define TEXTINPUT_PROJECT_EVENTHANDLER_H


#include "SFML/Graphics.hpp"

//Abstract EventHandler Class
// For ease of use of GUIComponent Class
class EventHandler {
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;
};

#endif //TEXTINPUT_PROJECT_EVENTHANDLER_H
