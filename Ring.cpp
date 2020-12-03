//
// Created by Tailon on 11/6/2020.
//

#include "Ring.h"

Ring::Ring(int value): _valueOfRing(value) {}

int Ring::getValue() const {
    return _valueOfRing;
}

bool operator==(Ring lhs, Ring rhs){
    return lhs.getValue() == rhs.getValue();
}
