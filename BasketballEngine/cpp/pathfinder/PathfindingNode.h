//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PATHFINDINGNODE_H
#define BASKETBALLENGINE_PATHFINDINGNODE_H
class PathfindingNode {
    Coordinate pos;
    int parentIndex;

    int originCost;
    int currCost;


    public:
    int getTotalCost() const { return originCost + currCost; }

};
#endif //BASKETBALLENGINE_PATHFINDINGNODE_H