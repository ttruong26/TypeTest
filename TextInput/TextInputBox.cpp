//
// Created by Tyler Truong  on 3/22/22.
//

#include "TextInputBox.h"

TextInputBox::TextInputBox() {
    _label = Label(0, 0);
    _box = Box(0, 50, 300, 40);
    _typedText = Typing(0, 50);
}

TextInputBox::TextInputBox(sf::Vector2f position) : TextInputBox() {
    setLabelSize(45);
    _xPos = position.x;
    _yPos = position.y;
    textPos = (_yPos + (2*fontSize));
    _label = Label(_xPos, _yPos);
    _box = Box(_xPos, (_yPos + (2*fontSize)), 800, (fontSize+5));
    _typedText = Typing(_xPos, textPos);
    _cursor = Cursor((_xPos), textPos);
}

void TextInputBox::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    HistoryNode h = {this, getSnapshot()};

    if(MouseEvent<Box>::mouseClicked(_box, window)) {
        _cursor.showCursor();
        canType = true;
    }
    if(canType) {
        _cursor.showCursor();
        _typedText.addEventHandler(window, event);

        _cursor.setPosition({(_typedText.getGlobalBounds().left + _typedText.getGlobalBounds().width), textPos});
    }



    if(!MouseEvent<Box>::hovered(_box, window) && MouseEvent<TextInputBox>::mouseClicked(window, event) && canType) {
        canType = !canType;
        _cursor.hideCursor();
    }

    //History::addEventHandler(window, event);

    //std::cout << MouseEvent<TextInputBox>::mouseClicked(window, event);
}

void TextInputBox::update() {
    _cursor.update();
    _typedText.update();

    //_cursor.setPosition(_typedText.getGlobalBounds().left + _typedText.getGlobalBounds().width, _yPos);

}

void TextInputBox::draw(sf::RenderTarget &window, sf::RenderStates states) const{
    window.draw(_label);
    window.draw(_box);
    window.draw(_typedText);
    window.draw(_cursor);
}

Snapshot TextInputBox::getSnapshot() {
    Snapshot s;
    return s;
}

void TextInputBox::applySnapshot(const Snapshot &snapshot) {

}

void TextInputBox::setLabel(std::string label) {
    _label.setString(label);
}

void TextInputBox::setLabelSize(unsigned int size) {
    _label.setCharacterSize(size);
    fontSize = size;
    std::cout << fontSize;
}

void TextInputBox::setLabelMargin(std::vector<float> spacing) {
}

void TextInputBox::setSize(sf::Vector2f pos) {

}
