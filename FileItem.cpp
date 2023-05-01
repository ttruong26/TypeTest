//
// Created by Tyler Truong  on 4/25/22.
//

#include "FileItem.h"

FileItem::FileItem() : Item() {
}

FileItem::FileItem(ImageIcon icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    Item::setString(text);
    Item::setSize(size);
    Item::setPosition(position);
    setIcon(icon);
}

void FileItem::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    Item::draw(window, states);
    window.draw(_icon);
}

sf::FloatRect FileItem::getGlobalBounds() const {
    return Item::getGlobalBounds();
}

sf::Vector2f FileItem::getSize() const {
    return {xSize, ySize};
}

sf::Vector2f FileItem::getPosition() const {
    return {xPos, yPos};
}

void FileItem::setPosition(sf::Vector2f pos) {
    Item::setPosition(pos);
    _icon.setPosition({(_itemName.getGlobalBounds().left - _itemName.getGlobalBounds().width), yPos});
}

void FileItem::setIcon(ImageIcon icon) {
    _icon.setTexture(Image::getTexture(icon));
    switch(icon) {
        case File : _icon.setScale({0.09, 0.09});
            break;
        case Folder : _icon.setScale({0.045, 0.045});
            break;
    }
    _icon.setPosition({(_itemName.getGlobalBounds().left - _itemName.getGlobalBounds().width), yPos});

}
