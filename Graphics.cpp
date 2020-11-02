//
// Created by Mark on 10/11/2020.
//

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include "TowersOfHanoi.h"
#include "Graphics.h"


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
}

Graphics::~Graphics()
{
    SDL_DestroyWindow(_window);
    _window = nullptr;
}

void Graphics::display(TowersOfHanoi::BoardType board)
{
    string spaces = "       ";

    vector<unsigned int> heights;
    for (const auto & tower : board)
    {
        heights.push_back(tower.size());
    }
    unsigned int height = *std::max_element(heights.begin(), heights.end());
    while(!std::all_of(board.begin(), board.end(), [](auto a) {return a.empty();}))
    {
        for (auto & tower : board)
        {
            if (!tower.empty() && tower.size() == height)
            {
                cout << tower.top();
                tower.pop();
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
