//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_BALL_H
#define BASKETBALLENGINE_BALL_H
#include "../../player/Player.h"
#include "../grid/Coordinate.h"

class Game;

class Ball {
public:
    enum class State {
        HELD,
        IN_FLIGHT,
        LOOSE,
        DEAD
    };
private:
    Coordinate position{47, 51};
    Game* game;
    double velocityX = 0.0;
    double velocityY = 0.0;
    State state = State::DEAD;
    Player* holder = nullptr;
public:
    explicit Ball(Game& game);
    [[nodiscard]] const Coordinate& getPosition() const;
    [[nodiscard]] Player* getHolder() const;
    void setHolder(Player* holder);
    [[nodiscard]] double getVelocityX() const;
    [[nodiscard]] double getVelocityY() const;
    [[nodiscard]] State getState() const;
    void setState(State state);
};


#endif //BASKETBALLENGINE_BALL_H