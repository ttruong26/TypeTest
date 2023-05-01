//
// Created by Tyler Truong  on 4/30/22.
//

#ifndef TEXTINPUT_PROJECT_POPUPLIST_H
#define TEXTINPUT_PROJECT_POPUPLIST_H

#include "../Interfaces/GUIComponentAdapter.h"
#include "InputBox.h"
#include "ItemList.h"
#include "Direction.h"

/* Not Used */
class PopUpList : public GUIComponentAdapter{
public:
    PopUpList();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    virtual Snapshot getSnapshot();
    virtual void setSnapshot(Snapshot& snapshot);

    void addItem(const std::string &s);
    void setPosition(sf::Vector2f pos);
    void setString(const std::string &s);
    void setSize(sf::Vector2f size);
private:
    ItemList _items = ItemList(UP);
    InputBox _inputBox;
    bool _show;
    std::string inputName;

    float yHeight, xPos, yPos, xSize, ySize;

};


#endif //TEXTINPUT_PROJECT_POPUPLIST_H
