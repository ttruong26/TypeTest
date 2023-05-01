//
// Created by Tyler Truong  on 4/21/22.
//

#ifndef TEXTINPUT_PROJECT_MENUBAR_H
#define TEXTINPUT_PROJECT_MENUBAR_H

#include "../Interfaces/GUIComponentAdapter.h"
#include <vector>
#include <map>
#include "Menu.h"

class MenuBar : public GUIComponentAdapter{
public:
    MenuBar();
    MenuBar(int menuCount);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();

    void setBoxSize(sf::Vector2f size);
    void setPosition(sf::Vector2f cords);

    void addMenu(const std::string &s);
    void addMenuItem(const std::string &itemName, const std::string &menuName);
private:
    std::vector<Menu> _menuBar;
    std::map<std::string, std::size_t> _menuMap;
    std::size_t elements = 0;
    float xSize, ySize, xPos, yPos;
};


#endif //TEXTINPUT_PROJECT_MENUBAR_H
