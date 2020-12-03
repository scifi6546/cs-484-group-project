//
// Created by Tailon on 11/6/2020.
//

#include "SaveGame.h"
#include <fstream>
#include <iostream>
#include <map>

 std::vector<int> SaveGame::getRingValues(Tower tower) {
     std::vector<int> ringValuesOfTower;
     std::vector<Ring> ringsOfTower;
     while(!tower.getRings().empty()) {
         ringValuesOfTower.push_back(tower.getRings().top().getValue());
         ringsOfTower.push_back(tower.getRings().top());
         tower.removeRing();

     }
     for(auto rings: ringsOfTower) {
         tower.getRings().push(rings);
     }

     return ringValuesOfTower;
 }

 void SaveGame::saveTheGame(TowersOfHanoi &backend, Graphics &frontend) {
     std::map<int, std::vector<int>> gameDataBackend;
     int index = 0;
     for (const auto& tower: backend.getBoard()) {
         gameDataBackend[index] = getRingValues(tower);
         index++;
     }
     std::vector<std::vector<int>> gameDataFrontend = {frontend.getSelectedTowerIndices(), frontend.getMarkedTowerIndices()};
     // Passing all the variables inside the vector from the beginning of the vector to the end.
     std::ofstream stream("gameData.txt");

     for(auto& kv : gameDataBackend) {
         stream << std::to_string(kv.first) << "\n";
         for(auto item: kv.second)
             stream << "\t" << item << "\n";
     }

     for(const auto& item: gameDataFrontend) {
         stream << ",\n";
         for(auto element: item)
             stream << std::to_string(element) << "\n";
     }
     stream.close();

//     printSavedItems(_saveOrder);
 }
