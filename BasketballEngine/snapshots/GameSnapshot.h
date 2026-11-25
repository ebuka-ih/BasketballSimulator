//
// Created by william on 11/24/2026.
//

#ifndef BASKETBALLENGINE_GAMESNAPSHOT_H
#define BASKETBALLENGINE_GAMESNAPSHOT_H
#include <array>
using namespace std;

struct PlayerSnapshot {
    int id;
    Player::Position position;
    bool hasCoordinate;
    Coordinate coordinate;
    char name[64];
};

struct TeamSnapshot {
    int id;
    int score;
    char name[64];
    array<PlayerSnapshot, 5> players;
};
struct GameSnapshot {
    int id;
    char gameClock[16];
    char shotClock[16];
    char period[16];
    bool clockActive;

    TeamSnapshot home;
    TeamSnapshot away;
};

#endif //BASKETBALLENGINE_GAMESNAPSHOT_H