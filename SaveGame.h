//
// Created by Tailon on 11/6/2020.
//

#ifndef TOWERS_OF_HANOI_SAVEGAME_H
#define TOWERS_OF_HANOI_SAVEGAME_H
#include "TowersOfHanoi.h"
#include "Graphics.h"
#include <string>
#include <vector>
class SaveGame {
public:
    void saveTheGame(TowersOfHanoi &, Graphics &);

//    void printSavedItems(std::vector<std::string>);

    std::vector<int> getRingValues(Tower tower);
private:
    std::vector<std::string> _saveOrder = {"board", "selected Towers", "marked Towers"};

};
#endif //TOWERS_OF_HANOI_SAVEGAME_H
