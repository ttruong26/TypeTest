//
// Created by Tyler Truong  on 3/24/22.
//

#ifndef TEXTINPUT_PROJECT_HISTORY_H
#define TEXTINPUT_PROJECT_HISTORY_H

#include "HistoryNode.h"
#include <stack>
#include "SFML/Graphics.hpp"
#include "../Static_Classes/KeyboardShortcut.h"

// History Stack Object
class History {
private:
    static std::stack<HistoryNode> _stack;
public:
    static void pushHistory(const HistoryNode& snapshot);
    static HistoryNode& topHistory();
    static void popHistory();

    //Handles Ctrl-z and pops the most recent snapshot into the history.
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};


#endif //TEXTINPUT_PROJECT_HISTORY_H
