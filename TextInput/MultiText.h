//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_MULTITEXT_H
#define TEXTINPUT_PROJECT_MULTITEXT_H

#include "Letter.h"
#include <list>

class Multitext : public sf::Drawable, public sf::Transformable {
public:
    Multitext();
    Multitext(float xPos, float yPos);
    Multitext(sf::Vector2u windowSize);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;

    void setPosition(sf::Vector2f pos);
    void setBold();
    void setColor(sf::Color color);
    void setCharSize(unsigned int size);

    bool empty() const;
    void add(char l);
    void add(char l, sf::Color color);
    void add(char l, float xPos, float yPos);
    void add(char l, sf::Color color, float xPos, float yPos);

    void pop();
    void enter();
    void tab();
    void reposition();
    void clear();

    sf::Vector2f getOriginPosition();
    sf::FloatRect getGlobalBounds();

    std::list<Letter>::iterator begin();
    std::list<Letter>::iterator end();
    std::list<Letter>::reverse_iterator rbegin();
    std::list<Letter>::reverse_iterator rend();

protected:
    std::list<Letter> multiText;
    float y;
    float x;
    unsigned int _size;
    bool enterEntered = false;
    sf::Vector2u _windowSize;
};




#endif //TEXTINPUT_PROJECT_MULTITEXT_H
