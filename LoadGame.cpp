//
// Created by Tailon on 11/7/2020.
//

#include "LoadGame.h"
#include <fstream>
#include <iostream>
#include <map>

void LoadGame::LoadSavedData() {
    std::ifstream input_file( "gameData.txt" );

    std::string tempVar;
    int index = -1;
    while ( std::getline(input_file, tempVar) )
    {
        if(tempVar != ",")
        {
            if (index != -1)
            {
                if (tempVar[0] != '\t') {
                    index = std::stoi(tempVar);
                    oldBoard[index] = {};
                }
                else
                    oldBoard[index].push_back(std::stoi(tempVar));
            }
            else
            {
                index = std::stoi(tempVar);
                oldBoard[index] = {};

            }
        }
        else {
            break;
        }
    }
    std::cout << "Get selected towers" << std::endl;
    while ( std::getline(input_file, tempVar) ){  //get selected towers
        if (tempVar != ",")
        {
            oldSelectedTower = std::stoi(tempVar);
            std::cout << "tempVar now: " << tempVar << std::endl;

        }
        else {
            std::cout << "You encountered a comma" << std::endl;
            break;
        }
    }
    std::cout << "Get marked towers" << std::endl;
    while ( std::getline(input_file, tempVar) ){ //get marked towers
        if (tempVar != ",")
        {
            oldMarkedTower = std::stoi(tempVar);
            std::cout << "tempVar now: " << tempVar << std::endl;

        }
        else {
            std::cout << "You encountered a comma" << std::endl;
            break;
        }
    }

    input_file.close();
}
