//
// Created by william on 11/22/2026.
//

#include "Pathfinder.h"
#include<cmath>

#include "../game/grid/GameGrid.h"
#include "../player/PlayAssignment.h"

using namespace std;
bool Pathfinder::isWalkable(const GameGrid& grid, const Player* player, const Coordinate& node) {
    return false;
}

double Pathfinder::calculateMovementCost(const GameGrid& grid, const Player *player, const Coordinate& current, const Coordinate& destination, const Coordinate& evaluated) {
    const double heuristic = calculateHeuristic(evaluated, destination);
    const double cost = 1.0;
    if (grid.hasObject(evaluated.x, evaluated.y)) {
        return numeric_limits<double>::infinity();
    }
    int comparableDistance = sqrt((evaluated.x - current.x) * (evaluated.x - current.x) + (evaluated.y - current.y) * (evaluated.y - current.y));

    OffensivePlay* play = player->getCurrentPlay();
    const PlayAssignment* assignment = player->getPlayAssignment();
    int teamSpace = assignment->getDesiredTeammateSpacing();
    int opponentSpace = assignment->getDesiredOpponentSpacing();
    PlayRole role = assignment->getPlayRole();
    return heuristic + cost;
}
vector<Coordinate> Pathfinder::getNeighbors(const GameGrid& grid, const Coordinate& node) {
    vector<Coordinate> neighbors;
    neighbors.reserve(8);
    for (int dx = -1; dx <= 1; ++dx) {
        for (int dy = -1; dy <= 1; ++dy) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            neighbors.emplace_back(Coordinate(dx, dy));
        }
    }
    return neighbors;
}
double Pathfinder::calculateHeuristic(const Coordinate& origin, const Coordinate& destination) {
    const int dx = abs( destination.x - origin.x);
    const int dy = abs( destination.y - origin.y);
    const int dMax = max( dx, dy );
    const int dMin = min( dx, dy );
    return 10 * dMax + 4 * dMin;


}
optional<Path> Pathfinder::createPath(const GameGrid& grid, const Coordinate& origin, const Coordinate& destination, const Player* player = nullptr) {

}
