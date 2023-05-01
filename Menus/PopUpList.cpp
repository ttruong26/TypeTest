//
// Created by Tyler Truong  on 4/30/22.
//

#include "PopUpList.h"

PopUpList::PopUpList() {
    _inputBox.setFillColor(sf::Color(90, 90, 90));
    _inputBox.setOutlineColor(sf::Color(90, 90, 90));
    setString("Color");
    setSize({300, 50});
    setPosition({0, 0});

    _show = false;

    inputName = "";
}

void PopUpList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_items);
    window.draw(_inputBox);
}

void PopUpList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<InputBox>::mouseClicked(_inputBox, window) )
        _show = true;

    if(_show) {
        _items.showList();
        _items.addEventHandler(window, event);
        for(auto &item : _items.getList()) {
            if(MouseEvent<Item>::mouseClicked(item, window)) {

                inputName = item.getString();
                _inputBox.setString(inputName);
                _inputBox.setPosition({xPos, yPos});
            }
        }
    }

    if(!MouseEvent<InputBox>::hovered(_inputBox, window) && MouseEvent<PopUpList>::mouseClicked(window, event) && _show) {
        _show = !_show;
        _items.hideList();
    }
}

void PopUpList::update() {

}

Snapshot PopUpList::getSnapshot() {
    Snapshot s;
}

void PopUpList::setSnapshot(Snapshot &snapshot) {

}

void PopUpList::addItem(const std::string &s) {
    _items.addItem(s, yHeight, xSize, ySize);
}

void PopUpList::setPosition(sf::Vector2f pos) {
    _inputBox.setPosition(pos);
    _items.setPosition({pos.x, (pos.y - _inputBox.getGlobalBounds().height)});
    yHeight = (_inputBox.getGlobalBounds().height -  _inputBox.getGlobalBounds().top);
    xPos = pos.x;
    yPos = pos.y;
}

void PopUpList::setString(const std::string &s) {
    _inputBox.setString(s);
    setSize({xSize, ySize});
    setPosition({xPos, yPos});
}

void PopUpList::setSize(sf::Vector2f size) {
    xSize = size.x;
    ySize = size.y;

    _items.setSize(size);
    setPosition({xPos, yPos});
}
