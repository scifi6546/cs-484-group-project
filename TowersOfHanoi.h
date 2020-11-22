//
// Created by Mark on 9/28/2020.
//

#ifndef TOWERS_OF_HANOI_TOWERSOFHANOI_H
#define TOWERS_OF_HANOI_TOWERSOFHANOI_H

#include <vector>
#include "Tower.h"
#include "Ring.h"
#include <map>


// TowersOfHanoi
// A class that can be used to play Towers of Hanoi
// Tracks the state of the board, allows player movements,
// and can check if the player has won
class TowersOfHanoi
{
    public:
        //The data structure type of the board
        using BoardType = std::vector<Tower>;

        // MoveRingResult
        // All the possible return states of the moveRing function
        enum class MoveRingResult
        {
            success,
            ringTooSmall,
            towerEmpty
        };

        // Default ctor
        // Initializes the game board with 8 rings and 3 towers
        // Starts with the rings on the 0-th tower
        TowersOfHanoi();

        // 2-param ctor
        // Takes the desired number of rings and towers
        // Starts with the rings on the 0-th tower
        TowersOfHanoi(int numOfRings, int numOfTowers);

        // resetGame
        // resets the game to the starting conditions
        void resetGame();

        // moveRing
        // Moves a ring from one tower to another
        // Returns an error if the selected tower has no rings,
        // or if the ring being moved is bigger than the ring
        // it was being placed on top of.
        // In either case of error, no rings are moved.
        MoveRingResult moveRing(size_t fromTower, size_t toTower);

        // winner
        // Checks to see if the player has won the game
        // The player has won if all the rings are on a
        // tower other than the starting tower.
        bool winner();

        // getBoard
        // Returns a copy of the board
        BoardType getBoard();

        void restoreOldBoard(std::map<int, std::vector<int>>);



    private:
        int _numberOfRings;
        int _numberOfTowers;
        BoardType _board;
};


#endif //TOWERS_OF_HANOI_TOWERSOFHANOI_H
