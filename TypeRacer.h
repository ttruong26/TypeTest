//
// Created by Tyler Truong  on 5/3/22.
//

#ifndef TEXTINPUT_PROJECT_TYPERACER_H
#define TEXTINPUT_PROJECT_TYPERACER_H

#include "Interfaces/GUIComponentAdapter.h"
#include "WordList.h"
#include "Menus/DropdownMenu.h"
#include "Menus/MenuBar.h"
#include "TextInput/Box.h"
#include "TextInput/Label.h"
#include "Timer.h"
#include "Wpm.h"
#include "Static_Classes/KeyboardShortcut.h"

class TypeRacer : public GUIComponentAdapter{
private:
    WordList _wordList;
    DropdownMenu _colorSelector;
    DropdownMenu _timeSelector;
    MenuBar _menuBar;
    Box _background;
    Item _resetButton;
    Label _label;
    Wpm _wpm;
    Timer _timer;

    sf::Clock _clock;
    float _timeElapsed = 0.f;

    bool _started;
    void setDarkMode();
    void setLightMode();
    void setBlueMode();

    void checkColorSelector();
    void checkTimeSelector();
    void restart(); //Different from reset, reset uses restart;
public:
    TypeRacer();
    TypeRacer(sf::Vector2u _winSize);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();

    void reset();
};


#endif //TEXTINPUT_PROJECT_TYPERACER_H
