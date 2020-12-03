// Created by Tailon Russell
// Date: 10/24/2020.

#ifndef TOWERS_OF_HANOI_MENU_H
#define TOWERS_OF_HANOI_MENU_H
#include <SDL.h>
#include <vector>
#include <string>
class Menu {
public:
    void displayMenuScreen();

    void closeMenuScreen();

    bool getMenuStatus() const;

    void setMenuStatus(bool);
private:
    std::string welcome = "Welcome to Towers of Hanoi";
    bool showMenu = true;

};

#endif //TOWERS_OF_HANOI_MENU_H
