//
// Created by Tyler Truong  on 4/11/22.
//

#ifndef TEXTINPUT_PROJECT_INPUTBOX_H
#define TEXTINPUT_PROJECT_INPUTBOX_H

#include "../Interfaces/GUIComponentAdapter.h"
#include "../TextInput/Box.h"
#include "../TextInput/Label.h"
#include "ItemList.h"
#include "../Static_Classes/MouseEvent.h"

/*
  InputBox class for Dropdown menu
  works similar to item and textinput box, click into to activate. Instead of typing text to fill info,
  gets info from selecting item from dropdown menu
*/
// No hover feautre like item
class InputBox : public GUIComponentAdapter {
public:
    InputBox();
    InputBox(float x, float y);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();

    void setString(const std::string& s);
    void setPosition(sf::Vector2f coords);
    void setSize(sf::Vector2f size);

    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);

    std::string& getString();
    sf::FloatRect getGlobalBounds() const;
private:
    Box _box; // Box object implements click feature
    Label _label; // Label used for text inside box
    std::string _labelName;
    float xPos, yPos;

};


#endif //TEXTINPUT_PROJECT_INPUTBOX_H
