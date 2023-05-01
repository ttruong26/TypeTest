//
// Created by Tyler Truong  on 5/6/22.
//

#ifndef TEXTINPUT_PROJECT_WPM_H
#define TEXTINPUT_PROJECT_WPM_H

#include "Interfaces/GUIComponentAdapter.h"
#include "TextInput/Label.h"
#include <iostream>

/* Will Calculate WPM on a 1second interval */
class Wpm : public GUIComponentAdapter{
private:
    sf::Time _oneSecond = sf::seconds(1);

    Label _wpm;
    float _wordCount = 0;

    const float AVG_WORD_LENGTH = 4.7;
public:
    Wpm();
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    void update(const float &wordCount);

    void setPosition(sf::Vector2f pos);
    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);

};


#endif //TEXTINPUT_PROJECT_WPM_H
