//
// Created by Tyler Truong  on 4/5/22.
//

#include "ItemList.h"

ItemList::ItemList() {
    yPos = 150;
    ySize = 0;
    xSize = 0;
    /*
    for(int i = 0; i < 4; i++) {
        Item item("Hello", 50, y);
        y += 50;
        _itemList.push_back(item);
    }
     */
}

ItemList::ItemList(Direction direction) : ItemList(){
    _direction = direction;
}

void ItemList::draw(sf::RenderTarget &window, sf::RenderStates state) const {
    if(s.checkHidden())
        for(auto &item: _itemList) {
            window.draw(item);
        }
}

void ItemList::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(s.checkHidden()) {
        for(auto &item : _itemList) {
            item.addEventHandler(window, event);
        }
    }
}

void ItemList::addItem(std::string s) {

}

void ItemList::addItem(std::string s, float &y, float xSize, float ySize){
    Item item;
    item.setString(s);
    item.setSize({xSize, ySize});
    item.setPosition({xPos, y});

    if(_direction == DOWN)
        y += 50;
    else if (_direction == UP)
        y-=50;
    _itemList.push_back(item);
}

void ItemList::setPosition(sf::Vector2f coords) {
    xPos = coords.x;
    float y = coords.y;
    for(auto &item : _itemList) {
        item.setPosition({coords.x, y});
        if(_direction == DOWN)
            y += item.getGlobalBounds().height;
        else if(_direction == UP)
            y -= item.getGlobalBounds().height;
    }
}

void ItemList::showList() {
    s.enableHidden();
}

void ItemList::hideList() {
    s.disableHidden();
}

std::vector<Item> ItemList::getList() {
    return _itemList;
}

void ItemList::setSize(sf::Vector2f size) {
    for(auto &item : _itemList) {
        item.setSize(size);
    }
}

sf::Vector2f ItemList::getSize() {
    for(auto &item: _itemList) {
        xSize = item.getSize().x;
        ySize += item.getSize().y;
    }
    return {xSize, ySize};
}
