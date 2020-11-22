//
// Created by renew on 11/6/2020.
//

#include "Tower.h"
Tower::Tower(): Tower(8) {}

Tower::Tower(int numberOfRings) {
    for (int index = numberOfRings; index > 0; --index) {
        _rings.push(Ring(index));
    }
}

bool Tower::isEmpty() {
    return _rings.empty();
}

Ring Tower::atTop() {
    return _rings.top();
}

void Tower::removeRing() {
    _rings.pop();
}

void Tower::addRing(Ring newRing){
    _rings.push(newRing);
}

int Tower::getNumberOfRings() {
    return _rings.size();
}

int Tower::getNumberOfRings() const {
    return _rings.size();
}

bool Tower::isSelected() const
{
    return _selected;
}

void Tower::toggleSelected()
{
    _selected = !_selected;
}