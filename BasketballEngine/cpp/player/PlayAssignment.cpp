//
// Created by william on 11/22/2026.
//
#include "PlayAssignment.h"

const Player* PlayAssignment::getPlayer() const {
    return player;
}
const OffensivePlay* PlayAssignment::getPlay() const {
    return play;
}
PlayRole PlayAssignment::getPlayRole() const {
    return role;
}
Coordinate PlayAssignment::getDesiredPosition() const {
    return desiredPosition;
}
int PlayAssignment::getDesiredTeammateSpacing() const {
    return desiredTeammateSpacing;
}

int PlayAssignment::getDesiredOpponentSpacing() const {
    return this->desiredTeammateSpacing;
}
PlayAssignment::PlayAssignment(const Player& player, const OffensivePlay& offensive, const PlayRole role, const Coordinate desiredPosition, const int teamSpacing, const int opponentSpacing)
    : player(&player), play(&offensive), role(role), desiredPosition(desiredPosition), desiredTeammateSpacing(teamSpacing), desiredOpponentSpacing(opponentSpacing) {
}