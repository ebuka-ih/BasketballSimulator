#include "Game.h"

#include <algorithm>
#include <iostream>
#include <sstream>
using namespace std;
Game::Game(int id, GameType type, Team* home, Team* away) : id(id), grid(GameGrid(*this)), clock(*this), gameType(type), home(home),
                                                            away(away), homeStats(*home, id), awayStats(*away, id) {
}

void Game::play() {
    phase = GamePhase::IN_PROGRESS;
}

void Game::tick() {
    clock.tick();
    if (clock.isFinished()) {
        cout << "FINISHED" << endl;
        advanceGame();
        if (phase != GamePhase::HALFTIME) {
            clock.reset(quarterDuration);
        } else {
            clock.reset(halftimeDuration);
        }
    }
}
void Game::advanceGame() {
    cout << "ADVANCEMENT CALLED (" << getPhaseString() << ")" << endl;
    if (phase == GamePhase::HALFTIME) {
        phase = GamePhase::IN_PROGRESS;
        period = GamePeriod::THIRD_QUARTER;
        return;
    }
    if (phase == GamePhase::IN_PROGRESS) {
        switch (period) {
            case GamePeriod::FIRST_QUARTER:
                period = GamePeriod::SECOND_QUARTER;
                break;
            case GamePeriod::SECOND_QUARTER:
                phase = GamePhase::HALFTIME;
                break;
            case GamePeriod::THIRD_QUARTER:
                period = GamePeriod::FOURTH_QUARTER;
                break;
            case GamePeriod::FOURTH_QUARTER:
                if (homeScore == awayScore) {
                    period = GamePeriod::OVERTIME;
                    overtimePeriods++;
                } else {
                    phase = GamePhase::FINISHED;
                }
                break;
            case GamePeriod::OVERTIME:
                if (homeScore == awayScore) {
                    overtimePeriods++;
                } else {
                    phase = GamePhase::FINISHED;
                }
                break;
        }
    }
}
string Game::getPeriodString() const {
    if (phase == GamePhase::HALFTIME) {
        return "HALF";
    }
    switch (period) {
        case GamePeriod::FIRST_QUARTER:
            return "1Q";
        case GamePeriod::SECOND_QUARTER:
            return "2Q";
        case GamePeriod::THIRD_QUARTER:
            return "3Q";
        case GamePeriod::FOURTH_QUARTER:
            return "4Q";
        case GamePeriod::OVERTIME: {
            ostringstream output;
            output << "OT " << overtimePeriods;
            return output.str();
        }
    }
    return "";
}
string Game::getPhaseString() const {
    switch (phase) {
        case GamePhase::SCHEDULED:
            return "Scheduled";
        case GamePhase::CANCELLED:
            return "CANCELLED";
        case GamePhase::FINISHED:
            return "FINISHED";
        case GamePhase::HALFTIME:
            return "HALFTIME";
        case GamePhase::IN_PROGRESS:
            return "IN PROGRESS";
        case GamePhase::TIMEOUT:
            return "TIMEOUT";
    }
    return "";
}
Coordinate Game::getBasketCoordinate(const Player &player) const {
    const bool isHome = ranges::any_of(home->getPlayers(), [&](const unique_ptr<Player>& p) { return p->getId() == player.getId(); });
    if (const bool firstHalf = period == GamePeriod::FIRST_QUARTER || period == GamePeriod::SECOND_QUARTER; isHome == firstHalf) {
        return grid.getLeftBasket().getPosition();
    }
    return grid.getRightBasket().getPosition();
}


