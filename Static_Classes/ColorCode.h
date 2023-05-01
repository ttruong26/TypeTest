//
// Created by Tyler Truong  on 4/6/22.
//

#ifndef TEXTINPUT_PROJECT_COLORCODE_H
#define TEXTINPUT_PROJECT_COLORCODE_H

#include "../TextInput/Typing.h"
#include <string>
#include <iostream>

class ColorCode {
private:
    static std::string word;
    static sf::Color color;

    static bool isEqual_CaseInsensitive(const std::string& a, const std::string &b);
    static bool checkString(const std::string &_s);
    static void changeTextColor(std::list<Letter>::reverse_iterator begin, std::list<Letter>::reverse_iterator end);
public:
    static void checkText(std::list<Letter>::reverse_iterator iter);
};


#endif //TEXTINPUT_PROJECT_COLORCODE_H
