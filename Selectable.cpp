//
// Created by mark on 11/21/20.
//

#include "Selectable.h"

void Selectable::select()
{
    _selected = true;
}

void Selectable::deselect()
{
    _selected = false;
}

bool Selectable::isSelected() const
{
    return _selected;
}
