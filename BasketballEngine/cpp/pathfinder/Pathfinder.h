//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PATHFINDER_H
#define BASKETBALLENGINE_PATHFINDER_H
#include <vector>
#include <optional>

#include "Path.h"
#include "../game/grid/Coordinate.h"
#include "../player/Player.h"
class GameGrid;


using namespace std;

class Pathfinder {

    bool isWalkable(const GameGrid& grid, const Player* player, const Coordinate& node);
    double calculateMovementCost(const GameGrid &grid, const Player *player, const Coordinate& current, const Coordinate &origin, const Coordinate &destination);
    vector<Coordinate> getNeighbors(const GameGrid& grid, const Coordinate& node);
    double calculateHeuristic(const Coordinate& origin, const Coordinate& destination);
    public:
    optional<Path> createPath(const GameGrid& grid, const Coordinate& origin, const Coordinate& destination, const Player* player = nullptr);
};


#endif //BASKETBALLENGINE_PATHFINDER_H