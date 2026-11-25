//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_GAMEENGINE_H
#define BASKETBALLENGINE_GAMEENGINE_H
#include "../game/Game.h"
#include "../game/grid/Coordinate.h"
class Player;

class GameEngine {
    void processTick(Game& game);
    void processPossession(Game& game);
    void processShot(Game& game);
    void processRebound(Game& game);
    void processTurnover(Game& game);
    void processFoul(Game& game);
    void movePlayer(Game& game, Player& player, Coordinate destination);
    void updateBallHolder(Player& player);
public:
    void start(Game& game);
    void pause();
    void resume();
    void stop();
    void simulatePossession(Game& game);
    void simulateQuarter(Game& game);
    void simulate(Game& game);
};


#endif //BASKETBALLENGINE_GAMEENGINE_H