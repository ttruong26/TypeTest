//
// Created by Tyler Truong  on 4/3/22.
//

#include "Item.h"

Item::Item() {
    _itemName.setFont(Fonts::getFont(Arial));
    _itemName.setFillColor(sf::Color::White);
    _boxColor = sf::Color::Black;
    _highlightColor = sf::Color(50, 50, 50);
    _box.setFillColor(_boxColor);
    setString("Item");
    setSize({200, 50});
    setPosition({0, 0});
}

Item::Item(const std::string &s) : Item() {
    _itemName.setString(s);
}

Item::Item(std::string s, float xPos, float yPos) : Item(s) {
    _box.setPosition({xPos, yPos});
    _box.setSize({200, 50});

    sf::FloatRect bounds(_itemName.getLocalBounds());
    sf::Vector2f box(_box.getSize());
    _itemName.setOrigin((((bounds.width - box.x) / 2 + bounds.left) - xPos), (((bounds.height - box.y) / 2 + bounds.top) -yPos));

}

void Item::setString(const std::string &s) {
    _itemName.setString(s);
    setSize({xSize, ySize});
    setPosition({xPos, yPos});
}

void Item::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_box);
    window.draw(_itemName);
}

void Item::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<Item>::hovered(*this, window)) {
        highlight();
    }
    else
        unHighlight();
}

void Item::setPosition(sf::Vector2f cords) {
    xPos = cords.x;
    yPos = cords.y;
    _box.setPosition({cords.x, cords.y});
//    setSize({200, 50});

    sf::FloatRect bounds(_itemName.getLocalBounds());
    sf::Vector2f box(_box.getSize());
    _itemName.setOrigin((((bounds.width - box.x) / 2 + bounds.left) - xPos), (((bounds.height - box.y) / 2 + bounds.top) -yPos));
}

void Item::setSize(sf::Vector2f size) {
    xSize = size.x;
    ySize = size.y;
    _box.setSize({size.x, size.y});
    setPosition({xPos, yPos});
}

sf::FloatRect Item::getGlobalBounds() const{
    return _box.getGlobalBounds();
}

void Item::highlight() {
    _box.setFillColor(_highlightColor);
    _itemName.setStyle(sf::Text::Bold);
}

void Item::unHighlight() {
    _box.setFillColor(_boxColor);
    _itemName.setStyle(sf::Text::Regular);
}

std::string Item::getString() const {
    return _itemName.getString();
}

sf::Vector2f Item::getSize() {
    return {xSize, ySize};
}

void Item::setStringFillColor(sf::Color color) {
    _itemName.setFillColor(color);
}

void Item::setFillColor(sf::Color color) {
    _box.setFillColor(color);
    _boxColor = color;
}

void Item::setOutlineColor(sf::Color color) {
    _box.setOutlineColor(color);
}

void Item::setHighlighColor(sf::Color color) {
    _highlightColor = color;
}
