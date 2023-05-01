//
// Created by Tyler Truong  on 3/23/22.
//

#include "Cursor.h"

Cursor::Cursor() {
    _cursor.setFont(Fonts::getFont(Arial));
    _cursor.setFillColor(sf::Color::Black);
    _cursor.setString("|");
    _cursor.setCharacterSize(38);
    _show = true;
}

Cursor::Cursor(float xPos, float yPos) : Cursor() {
    _cursor.setPosition(xPos, yPos);
}

void Cursor::setPosition(sf::Vector2f coords) {
    _cursor.setPosition(coords);
}

void Cursor::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(s.checkHidden()) {
        if(_show)
            window.draw(_cursor);
    }
}


void Cursor::update() {
    if(_clock.getElapsedTime() >= _delay) {
        _show = !_show;
        _clock.restart();
    }
}

States& Cursor::getState() {
    return s;
}

void Cursor::hideCursor() {
    s.disableHidden();
}

void Cursor::showCursor() {
    s.enableHidden();
}

void Cursor::setFillColor(sf::Color color) {
    _cursor.setFillColor(color);
}
