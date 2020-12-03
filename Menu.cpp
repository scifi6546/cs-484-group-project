// Created by Tailon Russell
// Date: 10/24/2020.
//

#include "Menu.h"
#include <iostream>

void Menu::displayMenuScreen() {
    showMenu = true;
    std::cout << welcome << std::endl;
    std::cout << "Start New Game (N)" << std::endl;
    std::cout << "Save Game (S)" << std::endl;
    std::cout << "Load Previous Game (L)" << std::endl;
    std::cout << "Continue Game (SPACE)" << std::endl;
}

void Menu::closeMenuScreen() {
    showMenu = false;
    for (int y = 0; y < 100; y++)
        std::cout << std::endl;
}

bool Menu::getMenuStatus() const {
    return showMenu;
}

void Menu::setMenuStatus(bool value) {
    showMenu = value;
}
