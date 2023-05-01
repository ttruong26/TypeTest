cmake_minimum_required(VERSION 3.21)
project(TextInput_Project)

set(CMAKE_CXX_STANDARD 14)

add_executable(TextInput_Project main.cpp TextInput/Typing.h TextInput/Typing.cpp TextInput/TextInputBox.h TextInput/TextInputBox.cpp Interfaces/SnapshotInterface.h TextInput/MultiText.h TextInput/MultiText.cpp
        Static_Classes/MouseEvent.h Static_Classes/MouseEvent.cpp TextInput/Letter.h TextInput/Letter.cpp FontHandling/Fonts.h FontHandling/Fonts.cpp FontHandling/FontNames.h Interfaces/EventHandler.h States.h States.cpp HistoryHandling/Snapshot.h HistoryHandling/Snapshot.cpp
        TextInput/Label.h TextInput/Label.cpp TextInput/Box.cpp TextInput/Box.h TextInput/Cursor.h TextInput/Cursor.cpp HistoryHandling/HistoryNode.h HistoryHandling/History.h HistoryHandling/History.cpp Static_Classes/KeyboardShortcut.h Static_Classes/KeyboardShortcut.cpp
        Menus/Item.h Menus/Item.cpp Menus/DropdownMenu.h Menus/DropdownMenu.cpp Menus/ItemList.h Menus/ItemList.cpp Static_Classes/ColorCode.h Static_Classes/ColorCode.cpp Menus/InputBox.h Menus/InputBox.cpp Interfaces/GUIComponent.h Interfaces/GUIComponentAdapter.cpp Menus/Menu.cpp Menus/Menu.h Menus/MenuBar.h Menus/MenuBar.cpp TypeTest_Components/WordList.cpp TypeTest_Components/WordList.h
        FileItem.cpp FileItem.h ImageHandling/ImageIcon.h ImageHandling/Image.h ImageHandling/Image.cpp FileNode.h FileNode.cpp
        Menus/PopUpList.cpp Menus/PopUpList.h Menus/Direction.h TypeTest_Components/TypeRacer.h TypeTest_Components/TypeRacer.cpp TypeTest_Components/Timer.cpp TypeTest_Components/Timer.h
        TypeTest_Components/Wpm.h TypeTest_Components/Wpm.cpp TypeTest_Components/Result.cpp TypeTest_Components/Result.h)


target_link_libraries(TextInput_Project sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)