//
// Created by Tyler Truong  on 4/25/22.
//

#include "Image.h"

std::map<ImageIcon, sf::Texture> Image::_images;

void Image::loadImage(ImageIcon imgIcon) {
    if(!_images[imgIcon].loadFromFile(getImagePath(imgIcon))) {
        exit(28);
    }
}

std::string Image::getImagePath(ImageIcon imgIcon) {
    switch(imgIcon) {
        case File : return "ImageHandling/file.png";
        case Folder : return "ImageHandling/folder.png";
    }
}

sf::Texture& Image::getTexture(ImageIcon imgIcon)  {
    loadImage(imgIcon);
    return _images[imgIcon];
}
