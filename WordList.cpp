//
// Created by Tyler Truong  on 4/22/22.
//

#include "WordList.h"

WordList::WordList() {
    _onScreenText.setCharSize(45);
    _typedText.setCharSize(45);
    _canType = false;

    _onScreenText.setColor(sf::Color::White);
    _cursor.setFillColor(sf::Color(211, 211, 211));
}

WordList::WordList(sf::Vector2u winSize) : WordList(){

}

void WordList::setPosition(sf::Vector2f cords) {

}

void WordList::addWords() {
    std::string s;
    for (int i = 0; i < 175; i++) {
        s = getRandomWord();
        for (auto &c: s)
            _onScreenText.add(c);
        _onScreenText.add(' ');
        if((_onScreenText.rbegin()->getGlobalBounds().left + _onScreenText.rbegin()->getGlobalBounds().width) > _boxSize.x - 150)
            _onScreenText.reposition();

    }
    _first = _onScreenText.begin();
    _cursor.setPosition({(_first->getPosition().x - 2), (_first->getPosition().y)});
}

std::string& WordList::getRandomWord() {
    std::vector<std::string> words;
    std::ifstream file;
    file.open("words.txt");
    std::string line;
    char space_char = ' ';


    while (getline(file, line)) {
        std::stringstream sstream(line);
        std::string word;
        while (std::getline(sstream, word, space_char)){
            word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
            words.push_back(word);
        }
    }

    file.close();
    return words[rand() % words.size()];
}

void WordList::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_wordBox);
    window.draw(_onScreenText);
    window.draw(_cursor);
    window.draw(_typedText);
}

void WordList::addEventHandler(sf::RenderWindow &window, sf::Event event) {

    if(_canType) {
        _cursor.showCursor();
        if(event.type == sf::Event::TextEntered) {
            if(_typedText.empty())
                _state.enableTimer();

            std::string letter = _first->getString();

            if(event.text.unicode == letter[0]) {
                _typedText.add(letter[0], _typedColor, _first->getPosition().x, _first->getPosition().y);
                ++_first;
            }
            else if(event.text.unicode == 8 ) {
                _typedText.pop();
                --_first;
            }

            else {
                if(letter[0] == ' ') {
                    _typedText.add(static_cast<char>(event.text.unicode), sf::Color::Red, _first->getPosition().x, _first->getPosition().y);
                    ++_first;
                }
                else {
                    _typedText.add(letter[0], sf::Color::Red, _first->getPosition().x, _first->getPosition().y);
                    ++_first;
                }
            }

            _cursor.setPosition({_first->getPosition().x - 2, (_first->getPosition().y )});
        }
    }

    if(!MouseEvent<Multitext>::hovered(_onScreenText, window) && MouseEvent<WordList>::mouseClicked(window, event) && _canType) {
        _canType = !_canType;
        _cursor.hideCursor();
    }
}

void WordList::update() {
    _cursor.update();
}

sf::Vector2f WordList::getOriginPosition() {
    return _typedText.getOriginPosition();
}

sf::FloatRect WordList::getGlobalBounds() const{
    return _wordBox.getGlobalBounds();
}

void WordList::setTextFillColor(sf::Color color) {
    _onScreenText.setColor(color);
}

void WordList::setTypedTextFillColor(sf::Color color) {
    _typedColor = color;
}

void WordList::enableType() {
    _canType = true;
    _cursor.showCursor();
}

void WordList::disableType() {
    _canType = false;
    _cursor.hideCursor();
}

void WordList::setBoxSize(sf::Vector2f size) {
    _boxSize = size;
    _wordBox.setSize(size);
}

void WordList::setBoxPosition(sf::Vector2f pos) {
    _wordBox.setPosition(pos);
}

void WordList::setBoxFillColor(sf::Color color) {
    _wordBox.setFillColor(color);
}

bool WordList::isTimerOn() {
    return _state.checkTimer();
}

void WordList::turnTimerOff() {
    _state.disableTimer();
}

void WordList::clear() {
    _onScreenText.clear();
    _typedText.clear();
}

