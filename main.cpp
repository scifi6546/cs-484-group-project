#include <iostream>
#include <SDL.h>
#include "TowersOfHanoi.h"
#include "tiny_obj_loader.h"
#include "Graphics.h"

using std::cout;
using std::endl;

bool eventHandler(SDL_Event &e, TowersOfHanoi & backend, Graphics & frontend)
{
    while(SDL_PollEvent(&e) != 0)
    {
        switch (e.type)
        {
            case SDL_QUIT:
                return true;
            case SDL_KEYDOWN:
                if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
                {
                    frontend.setTower();
                    std::vector<unsigned int> markedTowers = frontend.getMarkedTowers();
                    if (markedTowers.size() == 2)
                    {
                        backend.moveRing(markedTowers[0], markedTowers[1]);
                        frontend.resetMarkedTowers();
                    }
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    frontend.selectLeft();
                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    frontend.selectRight();
                }

                frontend.display(backend.getBoard());

                if (e.key.keysym.scancode == SDL_SCANCODE_W)
                {
                    frontend.displayWinOrLose(backend.winner());
                }
                break;
        }
    }

    return false;
}

int main(int, char**) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        cout << "SDL could not initialize! Error: " << SDL_GetError() << endl;
    }
    else
    {
        TowersOfHanoi backend;
        Graphics graphics("Towers of Hanoi");
        graphics.display(backend.getBoard());

        SDL_Event e;
        while(!eventHandler(e, backend, graphics)) {}
    }

    SDL_Quit();

    return 0;
}
