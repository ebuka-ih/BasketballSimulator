//
// Created by william on 11/21/2026.
//

#include "GameGrid.h"
#include "Basket.h"
#include "../Game.h"
#include "../../player/Player.h"

int GameGrid::getRows() const {
    return rows;
}

int GameGrid::getColumns() const {
    return columns;
}
void GameGrid::setCoordinate(Player& player, const Coordinate &coordinate) {
    player.setCoordinate(coordinate);
    if (ranges::find(players, &player) == players.end()) {
        players.push_back(&player);
    }

}
void GameGrid::remove(Player &player) {

}


bool GameGrid::hasObject(const int x, const int y) const {
    if ((leftBasket.getPosition().x == x && leftBasket.getPosition().y == y) || (rightBasket.getPosition().x == x && rightBasket.getPosition().y == y)) {
        return true;
    }
    for (const Player* player : players) {
        if (player->getCoordinate().value().x == x && player->getCoordinate().value().y == y) {
            return true;
        }
    }
    return false;
}
vector<Player*> GameGrid::getPlayers() const {
    return players;
}
double GameGrid::getDistance(const Coordinate& pos1, const Coordinate& pos2) {
    const double dx = pos2.x - pos1.x;
    const double dy = pos2.y - pos1.y;
    return sqrt(dx * dx + dy * dy);
}

double GameGrid::distanceFromBall(const Coordinate& coordinate) const {
    return getDistance(coordinate, game->getBall().getPosition());
}
double GameGrid::distanceFromPlayer(const Coordinate& coordinate, const Player& player)  {
    return getDistance(coordinate, player.getCoordinate().value());
}
const Player* GameGrid::getClosestTeammate(const Player& player) const {
    const Player* closestPlayer = nullptr;
    double lowestDistance = numeric_limits<double>::max();
    for (const Player* p : players) {
        if (p == &player || p->getTeam() != player.getTeam()) {
            continue;
        }
        if (const double distance = getDistance(player.getCoordinate().value(), p->getCoordinate().value()); distance < lowestDistance) {
            lowestDistance = distance;
            closestPlayer = p;
        }
    }
    return closestPlayer;
}
const Player* GameGrid::getClosestOpponent(const Player& player) const {

    const Player* closestPlayer = nullptr;
    double lowestDistance = numeric_limits<double>::max();
    for (const Player* p : players) {
        if (p == &player || p->getTeam() == player.getTeam()) {
            continue;
        }
        if (const double distance = getDistance(player.getCoordinate().value(), p->getCoordinate().value()); distance < lowestDistance) {
            lowestDistance = distance;
            closestPlayer = p;
        }
    }
    return closestPlayer;
}

vector<Player*> GameGrid::getPlayersWithinDistance(const Coordinate &coordinate, int distance) const {
    vector<Player*> near;

    for (Player* p : players) {
        if (getDistance(coordinate, p->getCoordinate().value()) <= distance) {
            near.push_back(p);
        }
    }
    return near;
}
vector<Player*> GameGrid::getNearbyTeammates(const Player& player, int distance) const {
    vector<Player*> near;
    const Coordinate coordinate = player.getCoordinate().value();

    for (Player* p : players) {
        if (p->getTeam() != player.getTeam()) {
            continue;
        }
        if (getDistance(coordinate, p->getCoordinate().value()) <= distance) {
            near.push_back(p);
        }
    }
    return near;
}
vector<Player*> GameGrid::getNearbyOpponents(const Player& player, int distance) const {
    vector<Player*> near;
    const Coordinate coordinate = player.getCoordinate().value();

    for (Player* p : players) {
        if (p->getTeam() == player.getTeam()) {
            continue;
        }
        if (getDistance(coordinate, p->getCoordinate().value()) <= distance) {
            near.push_back(p);
        }
    }
    return near;
}
Basket GameGrid::getLeftBasket() const {
    return leftBasket;
}

Basket GameGrid::getRightBasket() const {
    return rightBasket;
}
GameGrid::GameGrid(const Game& game) : rows(51), columns(95), game(&game), leftBasket(Coordinate(1, 25)), rightBasket(Coordinate(93, 25)) {
}
