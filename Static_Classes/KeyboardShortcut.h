//
// Created by Tyler Truong  on 3/27/22.
//

#ifndef TEXTINPUT_PROJECT_KEYBOARDSHORTCUT_H
#define TEXTINPUT_PROJECT_KEYBOARDSHORTCUT_H

#include "SFML/Graphics.hpp"
#include <iostream>

class KeyboardShortcut {
public:
    static bool isUndo();
    static bool isReset();

    static void command();
};


#endif //TEXTINPUT_PROJECT_KEYBOARDSHORTCUT_H
