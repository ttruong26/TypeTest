//
// Created by Tyler Truong  on 3/23/22.
//

#ifndef TEXTINPUT_PROJECT_SNAPSHOT_H
#define TEXTINPUT_PROJECT_SNAPSHOT_H

#include "../States.h"
#include <string>

// Snapshot object class to hold information about the current state of program
class Snapshot {
public:
    Snapshot();
    States _state;
    std::string _data;
};


#endif //TEXTINPUT_PROJECT_SNAPSHOT_H
