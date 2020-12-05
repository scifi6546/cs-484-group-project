// Created by Tailon Russell
// Date: 10/24/2020.
//

#include "Menu.h"
#include <iostream>

void Menu::displayMenuScreen() {
    showMenu = true;
}

void Menu::closeMenuScreen() {
    showMenu = false;
}

bool Menu::getMenuStatus() const {
    return showMenu;
}

void Menu::setMenuStatus(bool value) {
    showMenu = value;
}
