//
// Created by Tyler Truong  on 5/5/22.
//

#ifndef TEXTINPUT_PROJECT_TIMER_H
#define TEXTINPUT_PROJECT_TIMER_H

#include "Interfaces/GUIComponentAdapter.h"
#include "TextInput/Label.h"

/*
 *
 */
class Timer : public GUIComponentAdapter {
private:
    sf::Time _timer = sf::seconds(30);
    sf::Time _oneSecond = sf::seconds(1);
    sf::Clock _clock;
    Label _timeLeft;

    //Could have possible used a state instead of bool
    //Make state static, so wordlist and typeRacer can both access the TimerOn state
    bool _start;
public:
    Timer();

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();

    void setPosition(sf::Vector2f pos);
    void setOutlineColor(sf::Color color);
    void setFillColor(sf::Color color);
    void startTimer();
    void resetTimer(float time);

    float getTime();
    sf::FloatRect getGlobalBounds() const;
};


#endif //TEXTINPUT_PROJECT_TIMER_H
