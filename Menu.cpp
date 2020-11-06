// Created by Tailon Russell
// Date: 10/24/2020.
//

#include "Menu.h"
#include <iostream>

void Menu::displayMenuScreen() {
    showMenu = true;
    std::cout << welcome << std::endl;
}

void Menu::closeMenuScreen() {
    showMenu = false;
    for (int y = 0; y < 100; y++)
        std::cout << std::endl;
}

bool Menu::getMenuStatus() {
    return showMenu;
}

void Menu::setMenuStatus(bool value) {
    showMenu = value;
}
