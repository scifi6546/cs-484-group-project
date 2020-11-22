//
// Created by mark on 11/21/20.
//

#ifndef TOWERS_OF_HANOI_SELECTABLE_H
#define TOWERS_OF_HANOI_SELECTABLE_H


class Selectable
{
public:
    void select();

    void deselect();

    [[nodiscard]] bool isSelected() const;

private:
    bool _selected = false;
};


#endif //TOWERS_OF_HANOI_SELECTABLE_H
