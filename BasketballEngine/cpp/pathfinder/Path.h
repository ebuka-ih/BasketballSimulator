//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PATH_H
#define BASKETBALLENGINE_PATH_H
#include <vector>

#include "../game/grid/Coordinate.h"
using namespace std;

class Path {
    vector<Coordinate> positions;
    int totalCost = 0;

    public:
    Path(vector<Coordinate> positions, int totalCost);
    const vector<Coordinate>& getPositions() const;
    const Coordinate& getStart() const;
    const Coordinate& getDestination() const;
    int getTotalCost() const;
    size_t getMovementCount() const;
    bool isEmpty() const;

};
#endif //BASKETBALLENGINE_PATH_H