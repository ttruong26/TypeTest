#include <iostream>
#include <SFML/Graphics.hpp>

#include "TextInput/TextInputBox.h"
#include "Menus/DropdownMenu.h"
#include "Menus/InputBox.h"
#include "Menus/Menu.h"
#include "Menus/MenuBar.h"
#include "FileItem.h"
#include "HistoryHandling/History.h"
#include "TypeRacer.h"



int main() {
    srand (time(NULL));
    sf::RenderWindow window(sf::VideoMode(2000, 1200, 32), "My window");
    sf::Vector2u winSize = window.getSize();
    TypeRacer typeRacer(winSize);


    FileItem i;
    i.setIcon(File);
    i.setPosition({0, 450});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            typeRacer.addEventHandler(window, event);
            i.addEventHandler(window, event);

            History::addEventHandler(window, event);
        }
        //t.update();
        typeRacer.update();
        window.clear(sf::Color::White);

        window.draw(i);
        window.draw(typeRacer);
        window.display();
    }




    return 0;

    //Word_Shadow w;
    //w.drawWindow();
}