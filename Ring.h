//
// Created by Tailon on 11/6/2020.
//

#ifndef TOWERS_OF_HANOI_RING_H
#define TOWERS_OF_HANOI_RING_H

#include "Selectable.h"

class Ring : public Selectable {
public:
    explicit Ring(int);

    int getValue() const;

private:
    int _valueOfRing;
};
bool operator==(Ring, Ring);

#endif //TOWERS_OF_HANOI_RING_H
