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
#define GL_GLEXT_PROTOTYPES
#include <SDL.h>
#include <SDL_opengl.h>

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

    [[nodiscard]] std::vector<int> getMarkedTowerIndices() const;

    std::vector<int> getSelectedTowerIndices();

    void restoreSelectedTowers(const std::vector<int>& oldSelectedTowers);

    void restoreMarkedTowers(std::vector<int>);

    void resetMarkedTowers();

    void resetSelectedTower();

    void reset();

    void displayMenu();

    void closeMenu();

    bool getMenuStatus();

    void setMenuStatus(bool);

    void printInstructions();

    void printMenu();

private:
    SDL_Window * _window = nullptr;
    std::map<std::string, SDL_Texture *> textures{};
    //SDL_Renderer * _renderer = nullptr;
    Menu _menu;
    std::vector<int> _selectedTowerIndices;
    int _fromTowerIndex;
    int _toTowerIndex;
    SDL_GLContext context;
};

#endif //TOWERS_OF_HANOI_GRAPHICS_H
