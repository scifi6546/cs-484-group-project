#include <iostream>
#include <SDL.h>
#include "TowersOfHanoi.h"
#include "tiny_obj_loader.h"
#include "Graphics.h"
#include "SaveGame.h"
#include "LoadGame.h"

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
                if(e.key.keysym.scancode == SDL_SCANCODE_SPACE) {
                    frontend.setMenuStatus(!frontend.getMenuStatus());
                    if (!frontend.getMenuStatus()) {
                        frontend.closeMenu();
                        frontend.display(backend.getBoard());
                    }
                    if (frontend.getMenuStatus()) {
                        frontend.displayMenu();
                        frontend.printMenu();
                    }
                }
                if (e.key.keysym.scancode == SDL_SCANCODE_RETURN)
                {
                    if(!frontend.getMenuStatus()) {
                        frontend.setTower();
                        std::vector<int> markedTowersIndices = frontend.getMarkedTowerIndices(); //Might need to refactor this to include new Tower class
                        if (markedTowersIndices.size() == 2)
                        {
                            backend.moveRing(markedTowersIndices[0], markedTowersIndices[1]);
                            frontend.resetMarkedTowers();
                        }
                        frontend.display(backend.getBoard());
                    }

                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_A)
                {
                    frontend.selectLeft();
                    frontend.display(backend.getBoard());

                }
                else if (e.key.keysym.scancode == SDL_SCANCODE_D)
                {
                    frontend.selectRight();
                    frontend.display(backend.getBoard());
                }
                else if(frontend.getMenuStatus()) {
                    if (e.key.keysym.scancode == SDL_SCANCODE_N)
                    {
                        std::cout << "You selected N" << std::endl;
                        frontend.closeMenu();
                        backend.resetGame();
                        frontend.reset();
                        frontend.display(backend.getBoard());
                    }
                    else if (e.key.keysym.scancode == SDL_SCANCODE_L)
                    {
                        LoadGame restoreGame;
                        restoreGame.LoadSavedData();
                        backend.restoreOldBoard(restoreGame.oldBoard);
                        frontend.restoreMarkedTowers(restoreGame.oldMarkedTowers);
                        frontend.restoreSelectedTowers(restoreGame.oldSelectedTowers);
                        frontend.display(backend.getBoard());
                    }
                    else if (e.key.keysym.scancode == SDL_SCANCODE_S)
                    {
                        SaveGame saved;
                        saved.saveTheGame(backend, frontend);
                        frontend.display(backend.getBoard());
                    }
                }

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
        graphics.displayMenu();
        SDL_Event e;
        graphics.display(backend.getBoard());
        while(!eventHandler(e, backend, graphics)) {}
    }

    SDL_Quit();

    return 0;
}
