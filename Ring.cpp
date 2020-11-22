//
// Created by renew on 11/6/2020.
//

#include "Ring.h"

Ring::Ring(int value): _valueOfRing(value), _selected{false} {}

int Ring::getValue() const {
    return _valueOfRing;
}

bool Ring::isSelected() const
{
    return _selected;
}

void Ring::toggleSelected()
{
    _selected = !_selected;
}
