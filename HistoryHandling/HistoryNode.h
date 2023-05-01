//
// Created by Tyler Truong  on 3/24/22.
//

#ifndef TEXTINPUT_PROJECT_HISTORYNODE_H
#define TEXTINPUT_PROJECT_HISTORYNODE_H

#include "../Interfaces/GUIComponent.h"
#include "Snapshot.h"

// Node for stack(history) object, holds snapshot info and a GUIComponent
struct HistoryNode {
public:
    GUIComponent *guiPtr;
    Snapshot _snapshot;
};

#endif //TEXTINPUT_PROJECT_HISTORYNODE_H
