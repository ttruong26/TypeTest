//
// Created by Tyler Truong  on 4/20/22.
//

#include "Menu.h"

Menu::Menu() {
    setTitle("Menu");
    setSize({200, 50});
    setPosition({0, 0});
}

Menu::Menu(sf::Vector2f coords) {
    setPosition(coords);
}

void Menu::setPosition(sf::Vector2f coords) {
    _item.setPosition({coords.x, coords.y});
    _itemList.setPosition({coords.x, coords.y + _item.getGlobalBounds().height});
    yHeight = (_item.getGlobalBounds().top + _item.getGlobalBounds().height);
    xPos = coords.x;
    yPos = coords.y;
}

void Menu::setTitle(const std::string &s) {
    _item.setString(s);
    setSize({xSize, ySize});
    setPosition({xPos, yPos});
}

void Menu::setSize(sf::Vector2f size) {
    xSize = size.x;
    ySize = size.y;
    _item.setSize(size);
    _itemList.setSize(size);
    setPosition({xPos, yPos});
}

void Menu::addItem(const std::string &basicString) {
    _itemList.addItem(basicString, yHeight, (xSize + 100), ySize);
}

void Menu::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_item);
    window.draw(_itemList);
}

void Menu::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    _item.addEventHandler(window, event);
    if(MouseEvent<Item>::mouseClicked(_item, window) ) {
        _show = true;
    }


    if(_show) {
        _itemList.showList();
        _itemList.addEventHandler(window, event);
        for(auto &item : _itemList.getList()) {
            if(MouseEvent<Item>::mouseClicked(item, window)) {
                _show = !_show;
                _itemList.hideList();
            }
        }
        s.enableClicked();
    }

    if(!MouseEvent<Item>::hovered(_item, window) && MouseEvent<Menu>::mouseClicked(window, event) && _show) {
        _show = !_show;
        _itemList.hideList();
    }

    if(!_show) {
        s.disableClicked();
        _item.unHighlight();
    }

    if(s.checkCLicked() && _show) {
        _item.highlight();
    }
}

sf::FloatRect Menu::getGlobalBounds() const{
    sf::FloatRect r;
    r = _item.getGlobalBounds();
    return r;
}

void Menu::update() {

}

Snapshot Menu::getSnapshot() {
    return Snapshot();
}

void Menu::applySnapshot(const Snapshot &snapshot) {

}
