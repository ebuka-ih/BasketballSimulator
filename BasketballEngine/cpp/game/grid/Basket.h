//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_BASKET_H
#define BASKETBALLENGINE_BASKET_H
#include "Coordinate.h"

class Basket {
    Coordinate position;

public:
    explicit Basket(const Coordinate position) : position(position) {}
    [[nodiscard]] Coordinate getPosition() const { return position; }
};
#endif //BASKETBALLENGINE_BASKET_H