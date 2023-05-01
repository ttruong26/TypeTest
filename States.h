//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_STATES_H
#define TEXTINPUT_PROJECT_STATES_H

#include <map>

// Enum to declare the type of state an object can be in
enum ObjectState {
    HIDDEN,
    HIGHLIGHTED,
    DISABLED,
    CLICKED,
    TIMER_ON,

    LAST
};

// State object to check any given state that a GUIComponent object can be in.
// Works for any SFML drawable object(note: should convert drawable children to GUIComponent children
class States {
public:
    States();
    bool checkHidden() const;
    bool checkHighlighted();
    bool checkDisabled();
    bool checkCLicked();
    void enableHidden();
    void enableHighlighted();
    void enableDisabled();
    void enableClicked();
    void disableHidden();
    void disableHighlighted();
    void disableDisabled();
    void disableClicked();

    void enableTimer();
    void disableTimer();
    bool checkTimer();
private:
    std::map<ObjectState, bool> states;
};

#endif //TEXTINPUT_PROJECT_STATES_H
