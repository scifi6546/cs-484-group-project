//
// Created by Tailon on 11/6/2020.
//

#include "Tower.h"
Tower::Tower(): Tower(8) {}

Tower::Tower(int numberOfRings) {
    for (int index = numberOfRings; index > 0; --index) {
        _rings.push(Ring(index));
    }
}

Tower::Tower(int numberOfRings, std::vector<int> values) {
    for (int index = numberOfRings-1; index >= 0; --index) {
        _rings.push(Ring(values[index]));
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

std::stack<Ring> Tower::getRings() {
    return _rings;
}
