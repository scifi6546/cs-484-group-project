//
// Created by renew on 11/6/2020.
//

#ifndef TOWERS_OF_HANOI_TOWER_H
#define TOWERS_OF_HANOI_TOWER_H
#include "Ring.h"
#include "Selectable.h"
#include <vector>
#include <stack>

class Tower : public Selectable {
public:
    Tower();

    explicit Tower(int);

    int getNumberOfRings();

    [[nodiscard]] int getNumberOfRings() const;

    void addRing(Ring);

    bool isEmpty();

    Ring atTop();

    void removeRing();

private:
    std::stack<Ring> _rings; //This will be have the length of _numberOfRings from TowersOfHanoi
};
#endif //TOWERS_OF_HANOI_TOWER_H
