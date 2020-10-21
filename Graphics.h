//
// Created by Mark on 10/11/2020.
//

#ifndef TOWERS_OF_HANOI_GRAPHICS_H
#define TOWERS_OF_HANOI_GRAPHICS_H

#include <string>
#include "TowersOfHanoi.h"
#include "SDL.h"

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

private:
    SDL_Window * _window = nullptr;
    std::vector<int> _selectedTower;
};

#endif //TOWERS_OF_HANOI_GRAPHICS_H
