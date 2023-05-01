//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_TEXTINPUTBOX_H
#define TEXTINPUT_PROJECT_TEXTINPUTBOX_H


#include "../Interfaces/GUIComponent.h"
#include "Label.h"
#include "Typing.h"
#include "Box.h"
#include "../Static_Classes/MouseEvent.h"
#include "../HistoryHandling/History.h"
#include "Cursor.h"
#include "../Static_Classes/KeyboardShortcut.h"


class TextInputBox : public GUIComponent {
public:
    TextInputBox();
    TextInputBox(sf::Vector2f position);

    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const;
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event);
    virtual void update();
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot& snapshot);

    void setLabel(std::string label);
    void setLabelSize(unsigned int size);
    void setSize(sf::Vector2f pos);
    void setLabelMargin(std::vector<float> spacing);

private:
    Label _label;
    Box _box;
    Typing _typedText;
    Cursor _cursor;

    float _yPos;
    float _xPos;
    float fontSize;
    float textPos;
    bool canType = false;
};


#endif //TEXTINPUT_PROJECT_TEXTINPUTBOX_H
