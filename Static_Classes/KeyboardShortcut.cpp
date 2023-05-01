//
// Created by Tyler Truong  on 3/27/22.
//

#include "KeyboardShortcut.h"

bool KeyboardShortcut::isUndo() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) && sf::Keyboard::isKeyPressed(sf::Keyboard::Z);
}

bool KeyboardShortcut::isReset() {
    return sf::Keyboard::isKeyPressed(sf::Keyboard::LSystem) && sf::Keyboard::isKeyPressed(sf::Keyboard::R);
}
