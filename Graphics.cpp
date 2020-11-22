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

Graphics::Graphics(const std::string& windowName)
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
    textures.insert({"marker", loadTexture("../media/marker.png")});
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
    SDL_SetRenderDrawColor(_renderer, 0x66, 0x66, 0x66, 0xFF);
    SDL_RenderClear(_renderer);

    printInstructions();
    cout << endl;

    displayBoard();

    string spaces = "       ";

    long fromTower = -1;
    auto boardCopy = board; //The big while loop down below trashes the board, save it and restore it after
    vector<unsigned int> heights;
    for (const auto & tower : board)
    {
        heights.push_back(tower.getNumberOfRings());
    }
    unsigned int height = *std::max_element(heights.begin(), heights.end());
    while(!std::all_of(board.begin(), board.end(), [](auto a) {return a.isEmpty();}))
    {
        int towerPos = 0;
        for (auto tower = 0u; tower < board.size(); ++tower)
        {
            if (!board[tower].isEmpty() && board[tower].getNumberOfRings() == height)
            {
                if (!board[tower].atTop().isSelected())
                {
                    displayRing((8 - height + 20), towerPos, board[tower].atTop());
                }
                else
                {
                    fromTower = tower;
                }

                cout << board[tower].atTop().getValue();
                board[tower].removeRing();
            }
            else
            {
                cout << " ";

            }
            cout << spaces;
            towerPos++;
        }
        --height;
        cout << endl;
    }
    board = boardCopy;

    for (int tower = 0; tower < board.size(); tower++)
    {
        cout << "-";
        cout << spaces;
    }
    cout << endl;

    for (unsigned int tower = 0; tower < board.size(); ++tower) {
        if (board[tower].isSelected())
        {
            cout << "^";
            displayMarker(static_cast<int>(tower));
            if (fromTower >= 0)
            {
                displayRing(12, static_cast<int>(tower), board[fromTower].atTop());
            }
        }
        else
        {
            cout << " " << spaces;
        }
    }
    cout << endl;

    SDL_RenderPresent(_renderer);
}

void Graphics::displayRing(unsigned int y, int towerPos, Ring ring) const
{
    SDL_Color ringColor = {0x74, 0x43, 0x00, 0xFF};
    int maxRingWidth = SCREEN_WIDTH / 4;
    int ringWidth = maxRingWidth / 8 * ring.getValue();
    int halfRingWidth = ringWidth / 2;
    int ringHeight = SCREEN_HEIGHT / 32;

    SDL_Rect ringRect = {SCREEN_WIDTH / 16 * (3 + towerPos * 5) - halfRingWidth, static_cast<int>(SCREEN_HEIGHT / 32 * y), ringWidth, ringHeight };
    SDL_SetRenderDrawColor(_renderer, ringColor.r, ringColor.g, ringColor.b, ringColor.a );
    SDL_RenderFillRect(_renderer, &ringRect );
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

void Graphics::displayBoard()
{
    SDL_Color boardColor = {0x00, 0x00, 0x00, 0xFF};

    //Base of the board
    SDL_Rect base = { 0, SCREEN_HEIGHT / 8 * 7, SCREEN_WIDTH, SCREEN_HEIGHT / 16 };
    SDL_SetRenderDrawColor( _renderer, boardColor.r, boardColor.g, boardColor.b, boardColor.a );
    SDL_RenderFillRect( _renderer, &base );

    //Columns
    auto towerWidth = SCREEN_WIDTH / 64;
    auto towerHeight = SCREEN_HEIGHT / 8 * 3;
    auto halfTowerWidth = towerWidth / 2;

    for (int towerPos = 3; towerPos <= 13; towerPos +=  5)
    {
        SDL_Rect tower = {SCREEN_WIDTH / 16 * towerPos - halfTowerWidth, SCREEN_HEIGHT / 32 * 18, towerWidth, towerHeight };
        SDL_SetRenderDrawColor( _renderer, boardColor.r, boardColor.g, boardColor.b, boardColor.a );
        SDL_RenderFillRect( _renderer, &tower );
    }
}

void Graphics::displayMarker(int towerPos)
{
    int markerWidth = SCREEN_HEIGHT / 20;
    int markerHeight = markerWidth;
    int halfMarkerWidth = markerWidth / 2;

    SDL_Rect marker = {SCREEN_WIDTH / 16 * (3 + towerPos * 5) - halfMarkerWidth, SCREEN_HEIGHT / 16 * 15 + 5, markerWidth, markerHeight };
    SDL_RenderCopy(_renderer, textures.at("marker"), nullptr, &marker);
}
