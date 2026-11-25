//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_TEAM_H
#define BASKETBALLENGINE_TEAM_H
#include <memory>
#include <vector>
#include "../fans/Fanbase.h"
#include "../arena/Arena.h"
#include "../stats/TeamStats.h"
#include "../management/GeneralManager.h"
#include "../management/Analyst.h"
#include "../management/Coach.h"
#include "../player/Player.h"

using namespace std;


class Team {
    const int id;
    vector<unique_ptr<Player>> players;
    //const set<Contract> contracts;
    int wins = 0;
    int losses = 0;
    int regularSeasonWins = 0;
    int regularSeasonLosses = 0;
    double totalBalance = 0;
    Fanbase fanbase;
    unique_ptr<Coach> coach;
    unique_ptr<Analyst> analyst;
    // FinancePlan financePlan;
    unique_ptr<GeneralManager> generalManager;
    Arena arena;
    // Streak streak;
public:
    explicit Team(int id);
    void addPlayer(Player& player);
    void removePlayer(int playerId);
    [[nodiscard]] vector<unique_ptr<Player>>& getPlayers() { return players; }
    [[nodiscard]] const vector<unique_ptr<Player>>& getPlayers() const { return players; }

    [[nodiscard]] int getId() const { return id; }
    [[nodiscard]] int getWins() const { return wins; }
    [[nodiscard]] int getLosses() const { return losses; }
    [[nodiscard]] int getRegularSeasonWins() const { return regularSeasonWins; }
    [[nodiscard]] int getRegularSeasonLosses() const { return regularSeasonLosses; }
    [[nodiscard]] double getTotalBalance() const { return totalBalance; }
    [[nodiscard]] bool hasPlayer(int playerId) const;
    [[nodiscard]] bool reachedMax() const { return players.size() >= 15; }

};


#endif //BASKETBALLENGINE_TEAM_H