//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_PLAYER_H
#define BASKETBALLENGINE_PLAYER_H
#include <optional>
#include <string>

#include "PlayAssignment.h"
#include "Stats.h"
class OffensivePlay;
class Team;
using namespace std;

class Player {
    static inline int nextId = 0;
    const int id;

public:
    enum class Position {
        PG,
        SG,
        SF,
        PF,
        C
    };
private:
    Position position;
    optional<Coordinate> coordinate;
    int experience = 0;
    int potential = 0;
    int talent = 0;

    int age = 0;
    int health = 0;
    OffensivePlay* currentPlay = nullptr;
    optional<PlayAssignment*> assignment = nullptr;
    Team* team = nullptr;
    bool onCourt = true;
    // Route route
    // PathType movementGoal
    // Contract contract
    // Team team
    // Personality personality
    optional<Stats> stats;
public:
    explicit Player(const Position position) : id(nextId++), position(position) {
    }

    [[nodiscard]] const optional<Coordinate>& getCoordinate() const { return coordinate; }
    [[nodiscard]] OffensivePlay* getCurrentPlay() const;
    [[nodiscard]] PlayAssignment* getPlayAssignment() const;
    [[nodiscard]] Team* getTeam() const { return team; }

    void setCoordinate(const Coordinate& pos) { this->coordinate = pos; }
    [[nodiscard]] Position getPosition() const {  return position; }
    [[nodiscard]] string getPositionName() const;
    [[nodiscard]] int getId() const { return id; }
    [[nodiscard]] bool isOnCourt() const { return onCourt; }
    void setTeam(Team* t) { this->team = t; }
    bool operator==(const Player& other) const {
        return id == other.id;
    }
};


#endif //BASKETBALLENGINE_PLAYER_H