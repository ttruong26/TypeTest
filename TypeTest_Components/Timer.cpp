//
// Created by Tyler Truong  on 5/5/22.
//

#include <iostream>
#include "Timer.h"

Timer::Timer() {
    _start = false;
    _timeLeft.setString("Time: ");
    _timeLeft.setCharacterSize(35);
    _timeLeft.setOutlineThickness(3);
}

void Timer::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_timeLeft);
}

void Timer::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    //Empty
}

void Timer::update() {
    if(_start) {
        if (_timer.asSeconds() > 0) {
            if (_clock.getElapsedTime().asSeconds() > _oneSecond.asSeconds()) {
                _timer -= _oneSecond;
                _clock.restart();
            }
        }
        _timeLeft.setString("Time: " + std::to_string(static_cast<int>(_timer.asSeconds())));
    }
}

void Timer::setOutlineColor(sf::Color color) {
    _timeLeft.setOutlineColor(color);
}

void Timer::setFillColor(sf::Color color) {
    _timeLeft.setFillColor(color);
}

void Timer::startTimer() {
    _start = true;
}

void Timer::resetTimer(float time) {
    _start = false;
    _timeLeft.setString("Time: " + std::to_string(static_cast<int>(time)));
    _timer = sf::seconds(time);
}

void Timer::setPosition(sf::Vector2f pos) {
    _timeLeft.setPosition(pos);
}

sf::FloatRect Timer::getGlobalBounds() const {
    return _timeLeft.getGlobalBounds();
}

float Timer::getTime() {
    return _timer.asSeconds();
}