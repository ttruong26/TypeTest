//
// Created by Tyler Truong  on 4/11/22.
//

#include "InputBox.h"

InputBox::InputBox() {
    _box.setFillColor(sf::Color::Black);
    _box.setOutlineColor(sf::Color::White);
    _box.setOutlineThickness(2);
}

InputBox::InputBox(float x, float y) {
    setPosition({x, y});
}

void InputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_box);
    window.draw(_label);
}

void InputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<Box>::mouseClicked(_box, window)) {

    }
}

void InputBox::update() {

}

void InputBox::setPosition(sf::Vector2f coords) {
    xPos = coords.x;
    yPos = coords.y;
    _box.setPosition(coords);

    sf::FloatRect bounds(_label.getLocalBounds());
    sf::Vector2f box(_box.getSize());
    _label.setOrigin(((bounds.width - box.x) / 2 + bounds.left) - xPos, (((bounds.height - box.y) / 2 + bounds.top) -yPos));
}

void InputBox::setString(const std::string& s) {
    _labelName = s;
    _label.setString(s);
    _label.setFillColor(sf::Color::White);
    _label.setStyle(sf::Text::Regular);
}

sf::FloatRect InputBox::getGlobalBounds() const{
    return _box.getGlobalBounds();
}

void InputBox::setSize(sf::Vector2f size) {
    _box.setSize({size.x, size.y});
}

void InputBox::setFillColor(sf::Color color) {
    _box.setFillColor(color);
}

void InputBox::setOutlineColor(sf::Color color) {
    _box.setOutlineColor(color);
}

std::string& InputBox::getString() {
   return _labelName;
}
