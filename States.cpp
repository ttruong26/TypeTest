//
// Created by Tyler Truong  on 3/23/22.
//

#include "States.h"

States::States() {
    states[HIDDEN] = false;
    states[HIGHLIGHTED] = false;
    states[DISABLED] = false;
    states[CLICKED] = false;
    states[TIMER_ON] = false;
}

bool States::checkHidden() const {
    return states.at(HIDDEN);
}

bool States::checkHighlighted() {
    return states[HIGHLIGHTED];
}

bool States::checkDisabled() {
    return states[DISABLED];
}

void States::enableHidden() {
    states[HIDDEN] = true;
}

void States::enableHighlighted() {
    states[HIGHLIGHTED] = true;
}

void States::enableDisabled() {
    states[DISABLED] = true;
}

void States::disableHidden() {
    states[HIDDEN] = false;
}

void States::disableHighlighted() {
    states[HIGHLIGHTED] = false;
}

void States::disableDisabled() {
    states[DISABLED] = false;
}

bool States::checkCLicked() {
    return states[CLICKED];
}

void States::enableClicked() {
    states[CLICKED] = true;
}

void States::disableClicked() {
    states[CLICKED] = false;
}

void States::enableTimer() {
    states[TIMER_ON] = true;
}

void States::disableTimer() {
    states[TIMER_ON] = false;
}

bool States::checkTimer() {
    return states[TIMER_ON];
}





