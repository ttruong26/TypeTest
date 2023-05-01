//
// Created by Tyler Truong  on 4/6/22.
//

#include "ColorCode.h"

std::string ColorCode::word;
sf::Color ColorCode::color;

void ColorCode::checkText(std::list<Letter>::reverse_iterator iter) {

    auto textIter = iter;
    word = "";
    while(textIter->getString() != " " ) {
        word = textIter->getString() + word;
        --textIter;
    }
    std::cout << word;
//    if(checkString(word))
//        changeTextColor(textIter, iter);
}

void ColorCode::changeTextColor(std::list<Letter>::reverse_iterator begin, std::list<Letter>::reverse_iterator end) {
    for(;begin != end;++begin) {
        begin->setFillColor(color);
    }
}

//Takes in a letter to change its color.
bool ColorCode::checkString(const std::string &_s) {
    if(isEqual_CaseInsensitive(_s, "char"))
    {
        color = sf::Color::Green;
        return true;
    }
    else if(isEqual_CaseInsensitive(_s, "int"))
    {
        color = sf::Color::Green;
        return true;
    }
    else
        return false;
}

bool ColorCode::isEqual_CaseInsensitive(const std::string &a, const std::string &b) {
    return (a.size() == b.size()) &&
        //Lambda function that iterates through string a and b, checking if they have the same character
        std::equal(a.begin(), a.end(), b.begin(), [](char cA, char cB) {
            return toupper(cA) == toupper(cB);
    });
}

