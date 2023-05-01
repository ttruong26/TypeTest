//
// Created by Tyler Truong  on 5/3/22.
//

#include "TypeRacer.h"

TypeRacer::TypeRacer() {
    _started = false;
    _menuBar.addMenu("Settings");
    _menuBar.addMenu("Info");
    _menuBar.addMenu("Difficulty");
    _menuBar.addMenuItem("1", "Settings");
    _menuBar.addMenuItem("2", "Settings");
    _menuBar.addMenuItem("3", "Settings");
    _menuBar.addMenuItem("Easy", "Difficulty");
    _menuBar.addMenuItem("Intermediate", "Difficulty");
    _menuBar.addMenuItem("Hard", "Difficulty");
    _menuBar.setPosition({-200, 0});

    _colorSelector.setString("Dark Mode");
    _colorSelector.addItem("Dark Mode");
    _colorSelector.addItem("Light Mode");
    _colorSelector.addItem("Lava Red");
    _colorSelector.addItem("Aurora Blue");

    _timeSelector.setString("30sec");
    _timeSelector.addItem("30sec");
    _timeSelector.addItem("45sec");
    _timeSelector.addItem("60sec");

    _resetButton.setString("Reset");
    _resetButton.setStringFillColor(sf::Color(150, 0, 0));
}

TypeRacer::TypeRacer(sf::Vector2u _winSize) : TypeRacer(){
    auto xSize = static_cast<float>(_winSize.x);
    auto ySize = static_cast<float>(_winSize.y);
    _background.setSize({xSize, ySize});
    _background.setPosition({0, 0});
    _wordList.setBoxSize({xSize, 600});
    _wordList.setBoxPosition({_wordList.getOriginPosition().x - 20, _wordList.getOriginPosition().y});

    _label.setCharacterSize(70);
    _label.setOutlineThickness(4);
    _label.setString("TypeRacer");
    _label.setPosition({0, (_wordList.getGlobalBounds().top - _label.getGlobalBounds().height) - 10});


    _wpm.setPosition({0, (_wordList.getGlobalBounds().top + _wordList.getGlobalBounds().height) });
    _timer.setPosition({xSize - (_timer.getGlobalBounds().width * 2) , (_wordList.getGlobalBounds().top + _wordList.getGlobalBounds().height) });


    _colorSelector.setPosition({0, ySize - _colorSelector.getSize().y});
    _timeSelector.setPosition({xSize - _timeSelector.getSize().x, ySize - _colorSelector.getSize().y});
    _resetButton.setPosition({xSize - _resetButton.getSize().x, ySize - _resetButton.getSize().y});
    setDarkMode();
    _wordList.addWords();
}

void TypeRacer::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(_background);
    //window.draw(_wordBox);
    window.draw(_label);
    window.draw(_wordList);
    window.draw(_menuBar);
    window.draw(_colorSelector);
    window.draw(_timeSelector);
    window.draw(_wpm);
    window.draw(_timer);
    window.draw(_resetButton);
}

void TypeRacer::addEventHandler(sf::RenderWindow &window, sf::Event event) {
    if(MouseEvent<WordList>::mouseClicked(_wordList, window))
        _wordList.enableType();
    if(MouseEvent<Item>::mouseClicked(_resetButton, window))
        reset();


    _colorSelector.addEventHandler(window, event);
    _menuBar.addEventHandler(window, event);
    _wordList.addEventHandler(window, event);
    _timeSelector.addEventHandler(window, event);
    _resetButton.addEventHandler(window, event);
}

void TypeRacer::update() {
    _wordList.update();
    checkColorSelector();
    if(!_started)
        checkTimeSelector();

    if (_wordList.isTimerOn()) {
        _timer.startTimer();
        _started = true;
        //_wpm.update(_wordList.getCorrectCount());
    }

    if(_started) {
        _timeElapsed = _clock.getElapsedTime().asSeconds() / 60.f;

        //_wpm.update()
    }
//    if(_timer.getTime() == 0)


    _timer.update();

}

void TypeRacer::setDarkMode() {
    _background.setFillColor(sf::Color(90, 90, 90));
    _wordList.setBoxFillColor(sf::Color(50, 50, 50));
    _wordList.setTextFillColor(sf::Color(175, 175, 175));
    _wordList.setTypedTextFillColor(sf::Color::White);
    _label.setOutlineColor(sf::Color::Black);
    _label.setFillColor(sf::Color(175, 175, 175));
    _wpm.setOutlineColor(sf::Color::Black);
    _wpm.setFillColor(sf::Color(175, 175, 175));
    _timer.setOutlineColor(sf::Color::Black);
    _timer.setFillColor(sf::Color(175, 175, 175));
    _resetButton.setHighlighColor(sf::Color(200, 200, 200));
}

void TypeRacer::setLightMode() {
    _background.setFillColor(sf::Color(200, 200, 200));
    _wordList.setBoxFillColor(sf::Color(150, 150, 150));
    _wordList.setTextFillColor(sf::Color::Black);
    _wordList.setTypedTextFillColor(sf::Color::White);
    _label.setOutlineColor(sf::Color::White);
    _label.setFillColor(sf::Color::Black);
    _wpm.setOutlineColor(sf::Color::White);
    _wpm.setFillColor(sf::Color::Black);
    _timer.setFillColor(sf::Color::Black);
    _timer.setOutlineColor(sf::Color::White);
    _resetButton.setHighlighColor(sf::Color(100, 100, 100));
}

void TypeRacer::setBlueMode() {
    _background.setFillColor(sf::Color(0, 25, 130));
    _wordList.setBoxFillColor(sf::Color(0, 0, 75));
    _wordList.setTextFillColor(sf::Color(0, 175, 100));
    _wordList.setTypedTextFillColor(sf::Color(0, 255, 100));
    _label.setOutlineColor(sf::Color(0, 0, 25));
    _label.setFillColor(sf::Color(0, 255, 100));
    _wpm.setOutlineColor(sf::Color(0, 0, 25));
    _wpm.setFillColor(sf::Color(0, 255, 100));
    _timer.setOutlineColor(sf::Color(0, 0, 25));
    _timer.setFillColor(sf::Color(0, 255, 100));
    _resetButton.setHighlighColor(sf::Color(0, 220, 125));
}

void TypeRacer::checkColorSelector() {
//    switch (_colorSelector.getString()) {
//        case "Dark Mode" : setDarkMode();
//        break;
//        case "Light Mode": setLightMode();
//        break;
//    }
    if(_colorSelector.getString() == "Dark Mode")
        setDarkMode();

    else if(_colorSelector.getString() == "Light Mode")
        setLightMode();

    else if(_colorSelector.getString() == "Aurora Blue")
        setBlueMode();

}

void TypeRacer::checkTimeSelector() {
    if(_timeSelector.getString() == "30sec") {
        _timer.resetTimer(30);
    }

    else if(_timeSelector.getString() == "45sec") {
        _timer.resetTimer(45);
    }

    else if(_timeSelector.getString() == "60sec") {
        _timer.resetTimer(60);
    }

}

void TypeRacer::reset() {
    restart();
    checkTimeSelector();
}

void TypeRacer::restart() {
    _started = false;
    _wordList.disableType();
    _wordList.turnTimerOff();
    _wordList.clear();
    _wordList.addWords();
}

