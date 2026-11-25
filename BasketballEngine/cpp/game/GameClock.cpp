//
// Created by william on 11/23/2026.
//
#include "GameClock.h"

#include <iostream>

#include "Game.h"

GameClock::GameClock(Game& game) : game(&game), timeLeft(game.getQuarterDuration() * 100), shotClockTime(2400) {
}

void GameClock::start() {
    running = true;
}
void GameClock::pause() {
    running = false;
}
void GameClock::tick() {
    if (running && timeLeft > 0) {
        timeLeft--;
    }
    if (shotClockRunning && shotClockTime > 0) {
        shotClockTime--;
    }
}
void GameClock::reset(const int time) {
    timeLeft = time * 100;
}
bool GameClock::isFinished() const {
    return timeLeft <= 0;
}