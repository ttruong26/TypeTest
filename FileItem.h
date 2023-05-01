//
// Created by Tyler Truong  on 4/25/22.
//

#ifndef TEXTINPUT_PROJECT_FILEITEM_H
#define TEXTINPUT_PROJECT_FILEITEM_H

#include "Menus/Item.h"
#include "ImageHandling/Image.h"

class FileItem : public Item{
public:
    //Constructors
    FileItem();
    FileItem(ImageIcon icon, std::string text, sf::Vector2f size, sf::Vector2f position);
    //GUIComponent pure virtual functions, refer to the TextInput Project for Info
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    //Returns the bounds of the item
    sf::FloatRect getGlobalBounds() const;
    //returns the size of the item
    sf::Vector2f getSize() const;
    //returns the position of the item
    sf::Vector2f getPosition() const;
    //sets the position of the item
    void setPosition(sf::Vector2f pos);
    //uses an enum to change the icon to a folder or file
    void setIcon(ImageIcon icon);

private:
    //this is the folder or file icon
    sf::Sprite _icon;
    float padding = 5;
};



#endif //TEXTINPUT_PROJECT_FILEITEM_H
