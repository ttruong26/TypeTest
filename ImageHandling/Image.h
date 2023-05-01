//
// Created by Tyler Truong  on 4/25/22.
//

#ifndef TEXTINPUT_PROJECT_IMAGE_H
#define TEXTINPUT_PROJECT_IMAGE_H

#include <map>
#include <SFML/Graphics.hpp>
#include "ImageIcon.h"

//Helper Class Used to load image files
class Image {
private:
    static std::map<ImageIcon, sf::Texture> _images;
    static void loadImage(ImageIcon imgIcon);
    static std::string getImagePath(ImageIcon imgIcon);
public:
    static sf::Texture& getTexture(ImageIcon imgIcon);
};


#endif //TEXTINPUT_PROJECT_IMAGE_H
