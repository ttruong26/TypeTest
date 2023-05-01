//
// Created by Tyler Truong  on 3/24/22.
//

#include "History.h"

std::stack<HistoryNode> History::_stack;

void History::pushHistory(const HistoryNode &snapshot) {
    _stack.push(snapshot);
}

HistoryNode &History::topHistory() {
    return _stack.top();
}

void History::popHistory() {
    _stack.pop();
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(KeyboardShortcut::isUndo() ) {
        if(_stack.empty())
            return;
        std::cout << "Undid" << std::endl;
        _stack.top().guiPtr->applySnapshot(_stack.top()._snapshot);
        _stack.pop();
    }
}
