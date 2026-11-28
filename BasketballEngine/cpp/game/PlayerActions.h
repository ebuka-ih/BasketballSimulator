//
// Created by william on 11/27/2026.
//

#ifndef BASKETBALLENGINE_PLAYERACTIONS_H
#define BASKETBALLENGINE_PLAYERACTIONS_H
#include "mechanics/shooting/ShotContext.h"
#include "../logs/PossessionLog.h"
#include <cmath>

#include "Game.h"
#include "mechanics/shooting/ShotTrajectory.h"
class Player;

class PlayerActions {
    public:
    // Offensive
    static PossessionLog::ShotOutcome shoot(const Game& game, const Player &player);
    // PossessionLog::PassOutcome pass(Player& player, const PassContext& context);
    // void dribble(Player& player, const DribbleContext& context);
    // void setScreen(Player& player, const ScreenContext& context);

    // Defense
    void steal(Player& player, Player& target);
    void block(Player& player, Player& target);
    void contest(Player& player, Player& target);

    // Rebound
    void rebound(Player& player);
    static double calculateVelocity(const Player& player, const ShotContext& context);
    static double calculateLaunchAngle(const Player& player, const ShotContext& context, double distance, double velocity, double initialHeight, double targetHeight);
    static ShotTrajectory calculateTrajectory(const Player& player, const ShotContext& context) ;
};

#endif //BASKETBALLENGINE_PLAYERACTIONS_H