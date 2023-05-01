//
// Created by Tyler Truong  on 3/22/22.
//

#ifndef TEXTINPUT_PROJECT_GUICOMPONENT_H
#define TEXTINPUT_PROJECT_GUICOMPONENT_H

#include "SFML/Graphics.hpp"
#include "EventHandler.h"
#include "../States.h"
#include "SnapshotInterface.h"

//Abstract GUIComponent Class
// Force all GUIComponents to implement abstract functions
class GUIComponent : public sf::Drawable, public sf::Transformable, public EventHandler, public States,
        public SnapshotInterface{
public:
    //From Drawable
    virtual void draw(sf::RenderTarget &window, sf::RenderStates states) const = 0;

    //From Event Handler
    virtual void addEventHandler(sf::RenderWindow &window, sf::Event event) = 0;
    virtual void update() = 0;

    //From Snapshot Interfaces
    virtual Snapshot getSnapshot() = 0;
    virtual void applySnapshot(const Snapshot &snapshot) = 0;
};



#endif //TEXTINPUT_PROJECT_GUICOMPONENT_H
