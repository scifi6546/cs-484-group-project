//
// Created by Mark on 10/11/2020.
//

#ifndef TOWERS_OF_HANOI_GRAPHICS_H
#define TOWERS_OF_HANOI_GRAPHICS_H

#include <string>
#include <map>
#include "TowersOfHanoi.h"
#include "SDL.h"
#include "Menu.h"

class Graphics
{
public:
    const int SCREEN_WIDTH = 640;
    const int SCREEN_HEIGHT = 480;

    explicit Graphics(const std::string& windowName);

    ~Graphics();

    void display(TowersOfHanoi::BoardType board);

    void selectLeft();

    void selectRight();

    void setTower();

    void displayWinOrLose(bool winner);

    [[nodiscard]] std::vector<unsigned int> getMarkedTowers() const;

    void resetMarkedTowers();

    void displayMenu();

    void closeMenu();

    bool getMenuStatus();

    void setMenuStatus(bool);

    void printInstructions();

    SDL_Texture * loadTexture(const std::string &path);

    void displayBoard();

private:
    SDL_Window * _window = nullptr;
    SDL_Surface * _screenSurface = nullptr;
    std::map<std::string, SDL_Texture *> textures{};
    SDL_Renderer * _renderer = nullptr;
    Menu _menu;
    std::vector<int> _selectedTower;
    int _fromTower;
    int _toTower;

    void displayRing(unsigned int height, int towerPos, Ring ring) const;
};

#endif //TOWERS_OF_HANOI_GRAPHICS_H
