//
// Created by Tailon on 11/6/2020.
//

#ifndef TOWERS_OF_HANOI_RING_H
#define TOWERS_OF_HANOI_RING_H
class Ring{
public:
    explicit Ring(int);

    int getValue() const;

    bool isSelected() const;

    void toggleSelected();
private:
    int _valueOfRing;
    bool _selected;
};
bool operator==(Ring, Ring);

#endif //TOWERS_OF_HANOI_RING_H
