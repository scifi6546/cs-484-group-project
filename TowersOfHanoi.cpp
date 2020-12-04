//
// Created by Mark on 9/28/2020.
//

#include "TowersOfHanoi.h"
#include <vector>
#include <algorithm>

TowersOfHanoi::TowersOfHanoi(): TowersOfHanoi(8, 3)
{}

TowersOfHanoi::TowersOfHanoi(int numOfRings, int numOfTowers)
    : _numberOfRings(numOfRings),
      _numberOfTowers(numOfTowers),
      _selectedTower(0),
      _fromTower(-1),
      _board(numOfTowers)
{
    for (int index = 0; index < _board.size(); index++) {
        if (index == 0) {
            _board[0] = Tower(numOfRings);
        } else {
            _board[index] = Tower(0);
        }
    }

    _board[0].select();
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

void TowersOfHanoi::restoreOldBoard(std::map<int, std::vector<int>> savedData){
    BoardType loadingBoard(savedData.size());
    for(int i = 0; i < savedData.size(); i++) {
        loadingBoard[i] = Tower(savedData[i].size(), savedData[i]);
    }
    _board = loadingBoard;
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

void TowersOfHanoi::selectRing()
{
    if (_fromTower < 0 && !_board[_selectedTower].isEmpty())
    {
        _fromTower = _selectedTower;
        auto ring = _board[_selectedTower].atTop();
        _board[_selectedTower].removeRing();
        ring.select();
        _board[_selectedTower].addRing(ring);
        _fromTower = _selectedTower;
    }
    else if (_fromTower >= 0)
    {
        auto result = moveRing(_fromTower, _selectedTower);
        if (result == MoveRingResult::success)
        {
            auto ring = _board[_selectedTower].atTop();
            _board[_selectedTower].removeRing();
            ring.deselect();
            _board[_selectedTower].addRing(ring);
            _fromTower = -1;
        }
    }
}

void TowersOfHanoi::selectRight()
{
    _board[_selectedTower].deselect();
    if (_selectedTower + 1 >= _board.size())
    {
        _selectedTower = 0;
    }
    else
    {
        _selectedTower++;
    }

    _board[_selectedTower].select();
}

void TowersOfHanoi::selectLeft()
{
    _board[_selectedTower].deselect();
    if (_selectedTower - 1 < 0)
    {
        _selectedTower = _board.size() - 1;
    }
    else
    {
        _selectedTower--;
    }

    _board[_selectedTower].select();
}

long TowersOfHanoi::getSelectedTower()
{
    return _selectedTower;
}

long TowersOfHanoi::getMarkedTower()
{
    return _fromTower;
}
