//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_MATCHGRID_H
#define BASKETBALLENGINE_MATCHGRID_H
#include <vector>

#include "Basket.h"
#include "../objects/Ball.h"
class Player;
using namespace std;
class Game;

class GameGrid {
    const int rows;
    const int columns;
    const Game* game;
    const Basket leftBasket;
    const Basket rightBasket;
    vector<Player*> players;
public:
    int getRows() const;
    int getColumns() const;
    bool hasObject(int x, int y) const;
    vector<Player*> getPlayers() const;

    void setCoordinate(Player& player, const Coordinate &coordinate);
    void remove(Player& player);
    static double getDistance(const Coordinate& pos1, const Coordinate& pos2);
    double distanceFromBall(const Coordinate& coordinate) const;
    double distanceFromPlayer(const Coordinate& coordinate, const Player& player);
    const Player* getClosestTeammate(const Player& player) const;
    const Player* getClosestOpponent(const Player& player) const;

    vector<Player*> getPlayersWithinDistance(const Coordinate &coordinate, int distance) const;
    vector<Player*> getNearbyTeammates(const Player& player, int distance) const;
    vector<Player*> getNearbyOpponents(const Player& player, int distance) const;

    Basket getLeftBasket() const;
    Basket getRightBasket() const;

    explicit GameGrid(const Game& game);
};


#endif //BASKETBALLENGINE_MATCHGRID_H