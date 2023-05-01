//
// Created by Tyler Truong  on 4/21/22.
//

#include "MenuBar.h"

MenuBar::MenuBar() {
    setBoxSize({200, 50});
    setPosition({0, 0});
}

void MenuBar::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    for(auto & _m : _menuBar) {
        window.draw(_m);
    }
}

void MenuBar::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    for(auto & _m : _menuBar) {
        _m.addEventHandler(window, event);
    }
}

void MenuBar::update() {

}

void MenuBar::setBoxSize(sf::Vector2f size) {
    xSize = size.x;
    ySize = size.y;
    for(auto &menu : _menuBar) {
        menu.setSize(size);
    }
}

void MenuBar::setPosition(sf::Vector2f cords) {
    xPos = cords.x;
    yPos = cords.y;
    for(auto &menu : _menuBar) {
        xPos += menu.getGlobalBounds().width;
        menu.setPosition({xPos, yPos});
    }
}

void MenuBar::addMenu(const std::string &s) {
    Menu m;
    m.setSize({xSize, ySize});
    m.setPosition({xPos, yPos});
    m.setTitle(s);
    xPos += xSize;

    _menuBar.push_back(m);
    _menuMap[s] = elements;
    ++elements;
}

void MenuBar::addMenuItem(const std::string &itemName, const std::string &menuName) {
    _menuBar[_menuMap[menuName]].addItem(itemName);
}
