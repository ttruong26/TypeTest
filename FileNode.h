//
// Created by Tyler Truong  on 4/26/22.
//

#ifndef TEXTINPUT_PROJECT_FILENODE_H
#define TEXTINPUT_PROJECT_FILENODE_H

#include "Interfaces/GUIComponentAdapter.h"
#include "FileItem.h"

class FileNode : GUIComponentAdapter{
private:
    FileItem _data;
    std::vector<FileNode*> _children;

    States s;
    ImageIcon _icon;
    bool _show;
    void toggleChildren();
public:
    typedef typename std::vector<FileNode*>::iterator _iterator;
    FileNode();
    FileNode(ImageIcon icon, std::string text, sf::Vector2f size, sf::Vector2f position);

    //this draws the node. This is a recursive function to draw all the children nodes as well
    // this will only draw the node's children when it is in the proper state
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;


    //This calls the addEventHandler for all the children. It calls the toggleChildren function
    // when the node's data (FileItem) is clicked on
    virtual void addEventHandler(sf::RenderWindow& window, sf::Event event);
    //does nothing now
    virtual void update();

    //does nothing now
    sf::FloatRect getGlobalBounds();
    //returns true if the node has no children, otherwise false
    bool isLeaf() const;
    //getters and setters
    FileItem &getData();
    void setData(const FileItem &data);
    std::vector<FileNode*>& getChildren();

    void setIcon(ImageIcon icon);

    //iterators
    std::vector<FileNode*>::iterator begin();
    std::vector<FileNode*>::iterator end();
};


#endif //TEXTINPUT_PROJECT_FILENODE_H
