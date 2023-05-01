//
// Created by Tyler Truong  on 4/26/22.
//

#include "FileNode.h"

void FileNode::toggleChildren() {
//    if(!_show)

}

FileNode::FileNode() {
    _show = false;
}

FileNode::FileNode(ImageIcon icon, std::string text, sf::Vector2f size, sf::Vector2f position) {
    _data.setString(text);
    _data.setSize(size);
    _data.setPosition(position);
    _data.setIcon(icon);
    _icon = icon;
}

void FileNode::draw(sf::RenderTarget &window, sf::RenderStates states) const {

}

void FileNode::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<FileItem>::mouseClicked(_data, window))
        toggleChildren();

//    if(s.checkCLicked())
}

void FileNode::update() {

}

sf::FloatRect FileNode::getGlobalBounds() {
    return _data.getGlobalBounds();
}

bool FileNode::isLeaf() const {
    return _children.empty();
}

FileItem &FileNode::getData() {
    return _data;
}

void FileNode::setData(const FileItem &data) {
    _data = data;
}

std::vector<FileNode*> &FileNode::getChildren() {
    return _children;
}

std::vector<FileNode *>::iterator FileNode::begin() {
    return _children.begin();
}

std::vector<FileNode *>::iterator FileNode::end() {
    return _children.end();
}

void setIcon(ImageIcon icon) {

}
