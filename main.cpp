#include <iostream>
#include <SDL.h>
#include "TowersOfHanoi.h"
#include "tiny_obj_loader.h"
#include "Graphics.h"

using std::cout;
using std::endl;

bool eventHandler(SDL_Event &e)
{
    while(SDL_PollEvent(&e) != 0)
    {
        if (e.type == SDL_QUIT)
        {
            return true;
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
        Graphics graphics("Towers of Hanoi");

        SDL_Event e;
        while(!eventHandler(e)) {}
    }

    SDL_Quit();

    return 0;
}
