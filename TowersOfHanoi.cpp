//
// Created by Mark on 9/28/2020.
//

#include "TowersOfHanoi.h"
#include <vector>
#include <stack>
#include <iostream>
#include <string>

using std::vector;
using std::stack;
using std::cout;
using std::endl;
using std::string;

TowersOfHanoi::TowersOfHanoi() : _numberOfRings{8}, _numberOfTowers{3}
{
    *this = TowersOfHanoi(8, 3);
}

TowersOfHanoi::TowersOfHanoi(unsigned int numOfRings, unsigned int numOfTowers)
    : _numberOfRings{numOfRings}, _numberOfTowers{numOfTowers}
{
    _board = BoardType(_numberOfTowers);
    for (unsigned int ring = _numberOfRings; ring > 0; --ring) {
        _board[0].push(ring);
    }
}

void TowersOfHanoi::resetGame()
{
    *this = TowersOfHanoi(_numberOfRings, _numberOfTowers);
}

TowersOfHanoi::MoveRingResult TowersOfHanoi::moveRing(size_t fromTower, size_t toTower)
{
    if ( _board[fromTower].empty() )
    {
        return MoveRingResult::towerEmpty;
    }

    if (
            _board[toTower].empty()
            ||
            (_board[fromTower].top() <= _board[toTower].top())
       )
    {
        unsigned int ring = _board[fromTower].top();
        _board[fromTower].pop();
        _board[toTower].push(ring);
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
        if (_board[i].size() == _numberOfRings)
        {
            return true;
        }
    }

    return false;
}