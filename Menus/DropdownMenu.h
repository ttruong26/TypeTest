//
// Created by Tyler Truong  on 4/3/22.
//

#ifndef TEXTINPUT_PROJECT_DROPDOWNMENU_H
#define TEXTINPUT_PROJECT_DROPDOWNMENU_H

#include "../Interfaces/GUIComponent.h"
#include "ItemList.h"
#include "InputBox.h"
#include "../Static_Classes/MouseEvent.h"
#include "../HistoryHandling/HistoryNode.h"
#include "../HistoryHandling/History.h"

// Dropdown menu class
class DropdownMenu : public GUIComponent{
public:
    DropdownMenu();

    void addItem(const std::string &s);
    void setInputFillColor(sf::Color color);
    void setInputOutlineColor(sf::Color color);

    void setItemsFillColor(sf::Color color);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    void setPosition(sf::Vector2f coords);
    void setString(const std::string &s);
    void setSize(sf::Vector2f size);
    sf::Vector2f getSize();
    std::string& getString();
private:
    ItemList _items = ItemList(DOWN);
    InputBox _inputBox;
    bool _show;
    std::string inputName;

    float yHeight, xPos, yPos, xSize, ySize, yItemSize;
    Direction _direction;
};


#endif //TEXTINPUT_PROJECT_DROPDOWNMENU_H
