//
// Created by Tyler Truong  on 5/9/22.
//

#ifndef TEXTINPUT_PROJECT_RESULT_H
#define TEXTINPUT_PROJECT_RESULT_H

#include "../Interfaces/GUIComponentAdapter.h"
#include "../TextInput/Label.h"

class Result : public GUIComponentAdapter{
private:
    Label _wpm;
    Label _correct;
    Label _incorrect;
    States _state;
public:
    Result();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    void update(float wpm, float correct, float incorrect);

    void setPosition(sf::Vector2f pos);
    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);
};


#endif //TEXTINPUT_PROJECT_RESULT_H
