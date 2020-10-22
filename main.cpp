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
                switch (e.key.keysym.scancode)
                {
                    case SDL_SCANCODE_RETURN:
                        cout << "Enter key pressed" << endl;
                        break;
                    case SDL_SCANCODE_A:
                        frontend.selectLeft();
                        break;
                    case SDL_SCANCODE_D:
                        frontend.selectRight();
                        break;
                }
                frontend.display(backend.getBoard());
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
