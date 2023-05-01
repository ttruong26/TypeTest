//
// Created by Tyler Truong  on 4/22/22.
//

#ifndef TEXTINPUT_PROJECT_WORDLIST_H
#define TEXTINPUT_PROJECT_WORDLIST_H

#include <SFML/Graphics.hpp>
#include "Interfaces/GUIComponentAdapter.h"
#include "TextInput/MultiText.h"
#include "TextInput/Cursor.h"
#include "TextInput/Box.h"

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include "TextInput/MultiText.h"
#include "Static_Classes/MouseEvent.h"

/* GuiComponent for the list of words and box around it */
class WordList : public GUIComponentAdapter{
public:
    WordList();
    WordList(sf::Vector2u windowSize);

    void setPosition(sf::Vector2f cords);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();

    void enableType();
    void disableType();
    void setTextFillColor(sf::Color color);
    void setTypedTextFillColor(sf::Color color);
    void setBoxSize(sf::Vector2f size);
    void setBoxPosition(sf::Vector2f pos);
    void setBoxFillColor(sf::Color color);

    void addWords();
    void clear();

    sf::Vector2f getOriginPosition();
    std::string& getRandomWord();
    sf::FloatRect getGlobalBounds() const;

    bool isTimerOn();
    void turnTimerOff();
private:
    Multitext _onScreenText;
    Multitext _typedText;
    Cursor _cursor;
    Box _wordBox;

    sf::Vector2f _boxSize;
    bool _canType;
    States _state;
    std::list<Letter>::iterator _first;
    sf::Color _typedColor;
};


#endif //TEXTINPUT_PROJECT_WORDLIST_H
