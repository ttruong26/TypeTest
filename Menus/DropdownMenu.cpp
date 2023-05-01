//
// Created by Tyler Truong  on 4/3/22.
//

#include "DropdownMenu.h"

DropdownMenu::DropdownMenu() {
    setString("");
    setSize({250, 50});
    setPosition({0, 0});

    _show = false;
    //_direction = DOWN;
    inputName = "";
}


void DropdownMenu::addItem(const std::string &s) {
    _items.addItem(s, yHeight, xSize, yItemSize);
    ySize += yItemSize;
}

void DropdownMenu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_items);
    window.draw(_inputBox);
}

void DropdownMenu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<InputBox>::mouseClicked(_inputBox, window) )
        _show = true;

    if(_show) {
        _items.showList();
        _items.addEventHandler(window, event);
        for(auto &item : _items.getList()) {
            if(MouseEvent<Item>::mouseClicked(item, window)) {
                HistoryNode h = {this, getSnapshot()};
                History::pushHistory(h);
                inputName = item.getString();
                _inputBox.setString(inputName);
                _inputBox.setPosition({xPos, yPos});
            }
        }
    }

    if(!MouseEvent<InputBox>::hovered(_inputBox, window) && MouseEvent<DropdownMenu>::mouseClicked(window, event) && _show) {
        _show = !_show;
        _items.hideList();
    }
}

void DropdownMenu::update() {

}

Snapshot DropdownMenu::getSnapshot() {
    Snapshot s;
    s._data = inputName;
    return s;
}

void DropdownMenu::applySnapshot(const Snapshot &snapshot) {
    inputName = snapshot._data;
    _inputBox.setString(snapshot._data);
}

void DropdownMenu::setPosition(sf::Vector2f coords) {
    _inputBox.setPosition(coords);

    _items.setPosition({coords.x, (coords.y + _inputBox.getGlobalBounds().height)});
    yHeight = (_inputBox.getGlobalBounds().height +  _inputBox.getGlobalBounds().top);

    xPos = coords.x;
    yPos = coords.y;
}

void DropdownMenu::setString(const std::string &s) {
    inputName = s;
    _inputBox.setString(s);
    setSize({xSize, ySize});
    setPosition({xPos, yPos});
}

void DropdownMenu::setSize(sf::Vector2f size) {
    xSize = size.x;
    ySize = size.y;
    yItemSize = size.y;
    _inputBox.setSize(size);
    _items.setSize(size);
    setPosition({xPos, yPos});
}

sf::Vector2f DropdownMenu::getSize() {
    return {xSize, ySize};
}

std::string& DropdownMenu::getString() {
    return _inputBox.getString();
}

void DropdownMenu::setInputFillColor(sf::Color color) {

}

void DropdownMenu::setInputOutlineColor(sf::Color color) {

}

void DropdownMenu::setItemsFillColor(sf::Color color) {

}
