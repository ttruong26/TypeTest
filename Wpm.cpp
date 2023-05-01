//
// Created by Tyler Truong  on 5/6/22.
//

#include "Wpm.h"

Wpm::Wpm() {
    _wpm.setString("WPM: " + std::to_string(static_cast<int>(_wordCount)));
    _wpm.setCharacterSize(35);
    _wpm.setOutlineThickness(3);
}

void Wpm::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_wpm);
}

void Wpm::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //Empty so far
}

void Wpm::update() {
    //Empty
}

void Wpm::update(const float &wordCount) {
    _wordCount += wordCount;
    //std::cout << _wordCount << std::endl;


    /*
    if(_clock.getElapsedTime().asSeconds() > _oneSecond.asSeconds()) {
//        wpmCount = _wordCount * 60;
//        wpmCount = wpmCount / AVG_WORD_LENGTH;
        //_wpm.setString("WPM: " + std::to_string(static_cast<int>(wpmCount)));
        std::cout << _wordCount << std::endl;
        _wordCount = 0;
        _clock.restart();
    }
     */
}

void Wpm::setPosition(sf::Vector2f pos) {
    _wpm.setPosition(pos);
}

void Wpm::setOutlineColor(sf::Color color) {
    _wpm.setOutlineColor(color);
}

void Wpm::setFillColor(sf::Color color) {
    _wpm.setFillColor(color);
}
