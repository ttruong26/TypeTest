//
// Created by Tyler Truong  on 4/5/22.
//

#ifndef TEXTINPUT_PROJECT_ITEMLIST_H
#define TEXTINPUT_PROJECT_ITEMLIST_H

#include "SFML/Graphics.hpp"
#include <vector>
#include "Item.h"
#include "../States.h"
#include "Direction.h"

// ItemList is a list of item objects, first item in the list is present.
class ItemList : public sf::Drawable {
public:
    ItemList();
    ItemList(Direction _direction);
    void draw(sf::RenderTarget &window, sf::RenderStates state) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    void addItem(std::string s);
    void addItem(std::string s, float &y, float xSize, float ySize);
    void setPosition(sf::Vector2f coords);
    void setSize(sf::Vector2f size);

    void showList();
    void hideList();

    std::vector<Item> getList();
    sf::Vector2f getSize();
private:
    std::vector<Item> _itemList;
    States s;

    float xPos, yPos, ySize, xSize;
    Direction _direction;
};


#endif //TEXTINPUT_PROJECT_ITEMLIST_H
