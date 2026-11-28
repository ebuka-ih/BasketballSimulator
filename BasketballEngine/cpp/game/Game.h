//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_GAME_H
#define BASKETBALLENGINE_GAME_H
#include "../team/Team.h"
#include "../stats/TeamStats.h"
#include "GameClock.h"
#include "grid/GameGrid.h"
#include "objects/Ball.h"

class Arena;
class Player;

class Game {
public:
    enum class GameType {
        REGULAR_SEASON,
        PLAYOFFS
    };
    enum class PossessionState {
        LIVE,
        INBOUNDING,
        TIMEOUT,
        DEAD
    };
    enum class GamePhase {
        SCHEDULED,
        IN_PROGRESS,
        TIMEOUT,
        HALFTIME,
        FINISHED,
        CANCELLED
    };
    enum class GamePeriod {
        FIRST_QUARTER,
        SECOND_QUARTER,
        THIRD_QUARTER,
        FOURTH_QUARTER,
        OVERTIME
    };
private:
    int id;

    int quarter = 1;
    int quarterDuration = 15;
    int halftimeDuration = 900;
    int overtimePeriods = 0;
    int homeScore = 0;
    int awayScore = 0;

    GameGrid grid;
    GameClock clock;
    GameType gameType = GameType::REGULAR_SEASON;
    PossessionState possessionState = PossessionState::DEAD;
    GamePeriod period = GamePeriod::FIRST_QUARTER;
    GamePhase phase = GamePhase::SCHEDULED;

    Team* home;
    Team* away;
    Team* winner = nullptr;
    Team* loser = nullptr;

    Arena* arena{};
    Ball ball = Ball(*this);
    Player* inbounder = nullptr;


    TeamStats homeStats;
    TeamStats awayStats;

public:
    explicit Game(int id, GameType  = GameType::REGULAR_SEASON, Team* home = nullptr, Team* away = nullptr);

    void setHome(Team& home);
    void setAway(Team& away);

    [[nodiscard]] int getId() const { return id; }
    [[nodiscard]] Team* getWinner() const { return winner; }
    [[nodiscard]] Team* getLoser() const { return loser; }
    [[nodiscard]] Team* getHome() const { return home; }
    [[nodiscard]] Team* getAway() const { return away; }
    [[nodiscard]] Arena* getArena() const { return arena; }
    [[nodiscard]] Ball getBall() const { return ball; }
    [[nodiscard]] GameGrid& getGrid() { return grid; }
    [[nodiscard]] const GameGrid& getGrid() const { return grid; }
    [[nodiscard]] GameClock& getClock() { return clock; }
    [[nodiscard]] const GameClock& getClock() const { return clock; }
    [[nodiscard]] GameType getGameType() const { return gameType; }
    [[nodiscard]] PossessionState getPossessionState() const { return possessionState; }
    [[nodiscard]] Coordinate getBasketCoordinate(const Player& player) const;
    [[nodiscard]] GamePeriod getPeriod() const { return period; }
    [[nodiscard]] GamePhase getPhase() const { return phase; }
    [[nodiscard]] int getQuarter() const { return quarter; }
    [[nodiscard]] string getPeriodString() const;

    [[nodiscard]] string getPhaseString() const;

    [[nodiscard]] int getHomeScore() const { return homeScore; }
    [[nodiscard]] int getAwayScore() const { return awayScore; }
    [[nodiscard]] int getQuarterDuration() const { return quarterDuration; }
    [[nodiscard]] int getHalftimeDuration() const { return halftimeDuration; }
    [[nodiscard]] bool isFinished() const { return phase == GamePhase::FINISHED; }
    void play();
    void tick();
    void advanceGame();
};


#endif //BASKETBALLENGINE_GAME_H