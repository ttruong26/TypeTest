//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_MOUSEEVENT_CPP
#define TEXTINPUT_PROJECT_MOUSEEVENT_CPP

#include "MouseEvent.h"
#include <iostream>

template <class T>
sf::Clock MouseEvent<T>::clock;
template <class T>
int MouseEvent<T>::clicks;

template<class T>
bool MouseEvent<T>::mouseClicked(T &object, sf::RenderWindow &window) {
    if(hovered(object, window) && sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        if(clock.getElapsedTime().asSeconds() <= 0.5) {
            clicks++;
            clock.restart();
        }
        else {
            clicks = 1;
            clock.restart();
        }
        return true;
    }
    else
        return false;
}

template<class T>
bool MouseEvent<T>::mouseClicked(sf::RenderWindow &window, sf::Event event) {
     return (event.type == sf::Event::MouseButtonPressed);
}

template<class T>
bool MouseEvent<T>::mouseDoubleClicked() {
    return clicks == 2;
}

template<class T>
bool MouseEvent<T>::mouseTripleClicked() {
    return clicks == 3;
}

template<class T>
bool MouseEvent<T>::draggedOver(T &object, sf::RenderWindow &window, sf::Event event) {
    return false;
}

template<class T>
bool MouseEvent<T>::hovered(T &object, sf::RenderWindow &window) {
     sf::Mouse::getPosition(window);
    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    if(object.getGlobalBounds().contains(mousePos.x , mousePos.y)) {
        return true;
    }
    return false;
}

template<class T>
void MouseEvent<T>::countClicks(sf::Event event) {

}

#endif //TEXTINPUT_PROJECT_MOUSEEVENT_CPP
