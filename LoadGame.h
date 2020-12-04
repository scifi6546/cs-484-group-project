//
// Created by Tailon on 11/7/2020.
//

#ifndef TOWERS_OF_HANOI_LOADGAME_H
#define TOWERS_OF_HANOI_LOADGAME_H
#include "SaveGame.h"
#include <map>

class LoadGame {
public:
    void LoadSavedData();
    std::map<int, std::vector<int>> oldBoard;
    long oldSelectedTower;
    long oldMarkedTower;

};
#endif //TOWERS_OF_HANOI_LOADGAME_H
