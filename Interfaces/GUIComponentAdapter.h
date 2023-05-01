//
// Created by Tyler Truong  on 4/11/22.
//

#ifndef TEXTINPUT_PROJECT_GUICOMPONENTADAPTER_H
#define TEXTINPUT_PROJECT_GUICOMPONENTADAPTER_H

#include "GUIComponent.h"

// Abstract GUIComponentAdapter Class that inherits functions from GUIComponent
// Forces GUIComponent children to implment draw, addEventHandler, and update, not snapshot funcs
// For GUIComponents that do not have a history feature
class GUIComponentAdapter : public GUIComponent {
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const = 0;

    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) =  0;
    virtual void update() = 0;

    // Implements empty snapshot funcs
    virtual Snapshot getSnapshot();
    virtual void applySnapshot(const Snapshot &snapshot);
};


#endif //TEXTINPUT_PROJECT_GUICOMPONENTADAPTER_H
