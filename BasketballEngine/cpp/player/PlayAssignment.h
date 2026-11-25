//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PLAYASSIGNMENT_H
#define BASKETBALLENGINE_PLAYASSIGNMENT_H
#include "../models/enums/PlayRole.h"
#include "../game/grid/Coordinate.h"
#include "../models/OffensivePlay.h"
class OffensivePlay;
class Player;

class PlayAssignment {
    const Player* player;
    const OffensivePlay *play;
    PlayRole role;
    Coordinate desiredPosition;
    int desiredTeammateSpacing;
    int desiredOpponentSpacing;
public:
    [[nodiscard]] const Player* getPlayer() const;
    [[nodiscard]] const OffensivePlay* getPlay() const;
    [[nodiscard]] PlayRole getPlayRole() const;
    [[nodiscard]] Coordinate getDesiredPosition() const;
    [[nodiscard]] int getDesiredTeammateSpacing() const;

    [[nodiscard]] int getDesiredOpponentSpacing() const;
    PlayAssignment(const Player& player, const OffensivePlay& offensive, PlayRole role, Coordinate desiredPosition, int teamSpacing, int opponentSpacing);
};
#endif //BASKETBALLENGIN`E _PLAYASSIGNMENT_H