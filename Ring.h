//
// Created by renew on 11/6/2020.
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
#endif //TOWERS_OF_HANOI_RING_H
