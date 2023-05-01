//
// Created by Tyler Truong  on 4/3/22.
//

#ifndef TEXTINPUT_PROJECT_ITEM_H
#define TEXTINPUT_PROJECT_ITEM_H

#include "SFML/Graphics.hpp"
#include <string>
#include "../FontHandling/Fonts.h"
#include "../Static_Classes/MouseEvent.h"
#include "../Interfaces/GUIComponent.h"

// Represents a itembox, different than input box, used more like a button.
// Highlighs upon hover like a button, instead of clicking like the Inputbox
class Item : public sf::Drawable{
public:
    Item();
    Item(const std::string &s);
    Item(std::string s, float xPos, float yPos);
    void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    void addEventHandler(sf::RenderWindow &window, sf::Event event);

    virtual sf::FloatRect getGlobalBounds() const;
    void setPosition(sf::Vector2f cords);
    void setString(const std::string &s);
    void setSize(sf::Vector2f size);

    void setFillColor(sf::Color color);
    void setOutlineColor(sf::Color color);
    void setStringFillColor(sf::Color color);
    void setHighlighColor(sf::Color color);

    std::string getString() const;
    sf::Vector2f getSize();
    void highlight();
    void unHighlight();
protected:
    sf::Text _itemName; // Uses built in sfml text and rectangle objects
    sf::RectangleShape _box;
    float xSize, ySize, xPos, yPos;
    sf::Color _highlightColor, _boxColor;
};


#endif //TEXTINPUT_PROJECT_ITEM_H
