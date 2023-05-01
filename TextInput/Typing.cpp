//
// Created by Tyler Truong  on 3/22/22.
//

#include "Typing.h"

Typing::Typing() {

}

Typing::Typing(float xPos, float yPos) : Typing(){
    text = Multitext(xPos, yPos);
}

void Typing::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(event.type == sf::Event::TextEntered) {
        if(event.text.unicode == 8) {
            text.pop();
        }
        else if(event.text.unicode == 10) {
            text.enter();
        }
        else if(event.text.unicode == 9) {
            text.tab();
        }
//        else if(event.text.unicode == 32) {
//            if(charTyped) {
//                ColorCode::checkText(text.rbegin());
//                text.add(static_cast<char>(event.text.unicode));
//            }
//        }
        else if (event.text.unicode < 128 && event.text.unicode > 31) {
            text.add(static_cast<char>(event.text.unicode));
            charTyped = true;
        }
//        if(!text.empty())
//            ColorCode::checkText(text.rbegin());
    }

}

void Typing::update() {
}

void Typing::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(text);
}


sf::FloatRect Typing::getGlobalBounds() {
    return text.getGlobalBounds();
}

bool Typing::isEmpty() const {
    return text.empty();
}
