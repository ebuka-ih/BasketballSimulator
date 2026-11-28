//
// Created by william on 11/21/2026.
//

#include "Ball.h"
Ball::Ball(Game& game) : game(&game){
}
void Ball::setHolder(Player *holder) {
    this->holder = holder;
}

const Coordinate& Ball::getPosition() const {
    return position;
}

/*
Player* getHolder() const;
void setHolder(Player* holder);
double getVelocityX() const;
double getVelocityY() const;
State getState() const;
void setState(State state);
*/
