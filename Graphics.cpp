//
// Created by Mark on 10/11/2020.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "TowersOfHanoi.h"
#include "Graphics.h"
#include <SDL_image.h>


using std::string;
using std::vector;
using std::cout;
using std::endl;

Graphics::Graphics(const std::string& windowName) : _selectedTower{0, 1, 2}, _fromTower{-1}, _toTower{-1}
{
    _window = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (_window == nullptr)
    {
        cout << "Window not created! Error: " << SDL_GetError() << endl;
    }
    else
    {
        _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
        if (!_renderer)
        {
            cout << "Renderer not created! Error: " << SDL_GetError() << endl;
        }
        else
        {
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags))
            {
                cout << "Could not imitialize SDL_image: " << IMG_GetError() << endl;
            }
        }
    }

    textures.insert({"instructions", loadTexture("../media/instructions.png")});
}

Graphics::~Graphics()
{
    for (auto & [name, texture] : textures)
    {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    SDL_DestroyRenderer(_renderer);
    _renderer = nullptr;
    SDL_DestroyWindow(_window);
    _window = nullptr;
}

void Graphics::display(TowersOfHanoi::BoardType board)
{
    SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 0xFF);
    SDL_RenderClear(_renderer);

    printInstructions();
    cout << endl;

    string spaces = "       ";

    vector<unsigned int> heights;
    for (const auto & tower : board)
    {
        heights.push_back(tower.getNumberOfRings());
    }
    unsigned int height = *std::max_element(heights.begin(), heights.end());
    while(!std::all_of(board.begin(), board.end(), [](auto a) {return a.isEmpty();}))
    {
        for (auto & tower : board)
        {
            if (!tower.isEmpty() && tower.getNumberOfRings() == height)
            {
                cout << tower.atTop().getValue();
                tower.removeRing();
            }
            else
            {
                cout << " ";
            }
            cout << spaces;
        }
        --height;
        cout << endl;
    }

    for (int tower = 0; tower < board.size(); tower++)
    {
        cout << "-";
        cout << spaces;
    }
    cout << endl;

    for (unsigned int tower = 0; tower < _selectedTower.size(); ++tower) {
        if (_selectedTower.front() == tower)
        {
            cout << "^";
        }
        else
        {
            cout << " " << spaces;
        }
    }
    cout << endl;

    SDL_RenderPresent(_renderer);
}

void Graphics::selectLeft()
{
    std::rotate
    (
            _selectedTower.begin(),
            _selectedTower.end() - 1,
            _selectedTower.end()
    );
}

void Graphics::selectRight()
{
    std::rotate
    (
            _selectedTower.begin(),
            _selectedTower.begin() + 1,
            _selectedTower.end()
    );
}

void Graphics::setTower()
{
    if (_fromTower < 0)
    {
        _fromTower = _selectedTower.front();
    }
    else
    {
        _toTower = _selectedTower.front();
    }
}

std::vector<unsigned int> Graphics::getMarkedTowers() const
{
    std::vector<unsigned int> result;
    if(_fromTower >= 0)
    {
        result.push_back(_fromTower);
    }

    if (_toTower >= 0)
    {
        result.push_back(_toTower);
    }

    return result;
}

void Graphics::resetMarkedTowers()
{
    _fromTower = -1;
    _toTower = -1;
}

void Graphics::displayWinOrLose(bool winner)
{
    if (winner)
    {
        cout << "You won!" << endl;
    }
    else
    {
        cout << "You haven't won yet, keep going!" << endl;
    }
}

void Graphics::displayMenu() {
    _menu.displayMenuScreen();
}
void Graphics::closeMenu() {
    _menu.closeMenuScreen();
}

bool Graphics::getMenuStatus() {
    return _menu.getMenuStatus();
}

void Graphics::setMenuStatus(bool value) {
    _menu.setMenuStatus(value);
}

void Graphics::printInstructions()
{
    cout << "ENTER to pick up a ring" << endl;
    cout << "ENTER again to put it on a tower" << endl;
    cout << "A and D to move left and right" << endl;

    SDL_RenderCopy(_renderer, textures.at("instructions"), nullptr, nullptr);
}

SDL_Texture * Graphics::loadTexture(const std::string& path )
{
    SDL_Texture * texture = nullptr;

    SDL_Surface * loadedSurface = IMG_Load( path.c_str() );
    if( loadedSurface == nullptr )
    {
        cout << "Unable to load image " << path << ": " << IMG_GetError() << endl;
    }
    else
    {
        texture = SDL_CreateTextureFromSurface(_renderer, loadedSurface);
        if( texture == nullptr )
        {
            cout << "Unable to create texture from " << path << ": " << SDL_GetError() << endl;
        }

        SDL_FreeSurface( loadedSurface );
    }

    return texture;
}
