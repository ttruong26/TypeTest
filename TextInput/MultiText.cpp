//
// Created by Tyler Truong  on 3/22/22.
//

#include "MultiText.h"


Multitext::Multitext() {
    x = 10;
    y = 200;
}

Multitext::Multitext(float xPos, float yPos) {
    x = xPos;
    y = yPos;
}

Multitext::Multitext(sf::Vector2u winSize) : Multitext() {
}

void Multitext::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto &iter: multiText) {
        window.draw(iter);
    }
}

std::list<Letter>::iterator Multitext::begin() {
    return multiText.begin();
}

std::list<Letter>::iterator Multitext::end() {
    return multiText.end();
}

void Multitext::setCharSize(unsigned int size) {
    _size = size;
    if(!this->empty()) {
        for (auto &letter: this->multiText) {
            letter.setCharacterSize(size);
        }
    }
}

void Multitext::add(char l) {
    Letter letter;
    letter.setCharacterSize(_size);
    letter.setString(l);

    if(!multiText.empty() && !enterEntered) {
        x = multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width;
    }

    enterEntered = false;
    letter.setPosition({x, y});
    multiText.push_back(letter);
}

void Multitext::add(char l, sf::Color color) {
    Letter letter;
    letter.setCharacterSize(_size);
    letter.setFillColor(color);
    letter.setString(l);
    if(!multiText.empty() && !enterEntered) {
        x = multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width;
    }

    else if(enterEntered) {
    }

    enterEntered = false;
    letter.setPosition({x, y});
    multiText.push_back(letter);

}

void Multitext::add(char l, float xPos, float yPos) {
    Letter letter;
    letter.setCharacterSize(_size);
    letter.setString(l);

    if(!multiText.empty() && !enterEntered) {
        x = multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width;
    }

    enterEntered = false;
    letter.setPosition({xPos, yPos});
    x = xPos;
    y = yPos;
    multiText.push_back(letter);
}

void Multitext::add(char l, sf::Color color, float xPos, float yPos) {
    Letter letter;
    letter.setCharacterSize(_size);
    letter.setFillColor(color);
    letter.setString(l);

    if(!multiText.empty() && !enterEntered) {
        x = multiText.back().getGlobalBounds().left + multiText.back().getGlobalBounds().width;
    }

    enterEntered = false;
    letter.setPosition({xPos, yPos});
    x = xPos;
    y = yPos;
    multiText.push_back(letter);
}

void Multitext::setPosition(sf::Vector2f pos) {
    float tempX = pos.x;
    y = pos.y;
    for(auto &letter : this->multiText) {
        letter.setPosition({tempX, y});
        tempX += letter.getGlobalBounds().left + letter.getGlobalBounds().width;
    }
    x = tempX;
}

void Multitext::setBold() {
    for(auto &letter : multiText)
        letter.setStyle(sf::Text::Bold);
}

void Multitext::setColor(sf::Color color) {
    for(auto &letter : multiText)
        letter.setFillColor(color);
}

bool Multitext::empty() const{
    return multiText.empty();
}

void Multitext::pop() {
    if(multiText.empty())
        return;
    else
        multiText.pop_back();
}

void Multitext::enter() {
    y = multiText.back().getGlobalBounds().top + multiText.back().getGlobalBounds().height;
    x = 0;
    enterEntered = true;
}

void Multitext::tab() {
    for(int i = 0; i <= 4; i++)
        add(' ');
}

sf::FloatRect Multitext::getGlobalBounds() {
    sf::FloatRect r;
    if(!this->empty()) {
        r = this->begin()->getGlobalBounds();
        r.width = ((this->rbegin()->getGlobalBounds().left - this->begin()->getGlobalBounds().left) + this->rbegin()->getGlobalBounds().width);
    }

    return r;
}

sf::Vector2f Multitext::getOriginPosition() {
    return {x, y};
}

std::list<Letter>::reverse_iterator Multitext::rbegin() {
    return multiText.rbegin();
}

std::list<Letter>::reverse_iterator Multitext::rend() {
    return multiText.rend();
}

void Multitext::reposition() {
    y = (multiText.back().getGlobalBounds().top + multiText.back().getGlobalBounds().height + 10);
    x = 10;
    enterEntered = true;
}

void Multitext::clear() {
    multiText.clear();
    x = 10;
    y = 200;
}
