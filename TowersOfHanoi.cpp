//
// Created by Mark on 9/28/2020.
//

#include "TowersOfHanoi.h"
#include <vector>
#include <stack>
#include <iostream>
#include <string>
#include <algorithm>

using std::vector;
using std::stack;
using std::cout;
using std::endl;
using std::string;

TowersOfHanoi::TowersOfHanoi(): TowersOfHanoi(8, 3)
{}

TowersOfHanoi::TowersOfHanoi(int numOfRings, int numOfTowers)
    : _numberOfRings(numOfRings), _numberOfTowers(numOfTowers), _board(numOfTowers)
{
    for (int index = 0; index < _board.size(); index++) {
        if (index == 0) {
            _board[0] = Tower(numOfRings);
        } else {
            _board[index] = Tower(0);

        }

    }
}

void TowersOfHanoi::resetGame()
{
    *this = TowersOfHanoi(_numberOfRings, _numberOfTowers);
}

TowersOfHanoi::MoveRingResult TowersOfHanoi::moveRing(size_t fromTower, size_t toTower)
{
    if ( _board[fromTower].isEmpty() )
    {
        return MoveRingResult::towerEmpty;
    }

    if (
            _board[toTower].isEmpty()
            ||
            (_board[fromTower].atTop().getValue() <= _board[toTower].atTop().getValue())
       )
    {
        auto ring = _board[fromTower].atTop();
        _board[fromTower].removeRing();
        _board[toTower].addRing(ring);
        return MoveRingResult::success;
    }
    else
    {
        return MoveRingResult::ringTooSmall;
    }
}

bool TowersOfHanoi::winner()
{
    for (unsigned int i = 1; i < _board.size(); ++i)
    {
        if (_board[i].getNumberOfRings() == _numberOfRings)
        {
            return true;
        }
    }

    return false;
}

//void TowersOfHanoi::printBoard()
//{
//    BoardType board = _board;
//    string spaces = "       ";
//
//    vector<unsigned int> heights;
//    for (const auto & tower : board)
//    {
//        heights.push_back(tower.getNumberOfRings());
//    }
//    unsigned int height = *std::max_element(heights.begin(), heights.end());
//    while(!std::all_of(board.begin(), board.end(), [](auto a) {return a.isEmpty();}))
//    {
//        for (auto & tower : board)
//        {
//            if (!tower.isEmpty() && tower.getNumberOfRings() == height)
//            {
//                cout << tower.atTop().getValue();
//                tower.removeRing();
//            }
//            else
//            {
//                cout << " ";
//            }
//            cout << spaces;
//        }
//        --height;
//        cout << endl;
//    }
//
//    for (int tower = 0; tower < board.size(); tower++)
//    {
//        cout << "-";
//        cout << spaces;
//    }
//    cout << endl;
//}

TowersOfHanoi::BoardType TowersOfHanoi::getBoard()
{
    return _board;
}
