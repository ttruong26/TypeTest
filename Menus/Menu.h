//
// Created by Tyler Truong  on 4/20/22.
//

#ifndef TEXTINPUT_PROJECT_MENU_H
#define TEXTINPUT_PROJECT_MENU_H

#include "../Interfaces/GUIComponentAdapter.h"
#include "SFML/Graphics.hpp"
#include "ItemList.h"
#include "Item.h"
#include "../Static_Classes/MouseEvent.h"
#include "Direction.h"

class Menu : public GUIComponent{
public:
    Menu();
    Menu(sf::Vector2f coords);
    void setPosition(sf::Vector2f coords);
    void addItem(const std::string &basicString);
    void setTitle(const std::string &s);
    void setSize(sf::Vector2f size);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    sf::FloatRect getGlobalBounds() const;
private:
    Item _item;
    ItemList _itemList = ItemList(DOWN);
    States s;

    bool _show = false;
    float yHeight, xSize, ySize, xPos, yPos;
};


#endif //TEXTINPUT_PROJECT_MENU_H
