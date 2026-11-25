//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_TEAMSTATS_H
#define BASKETBALLENGINE_TEAMSTATS_H
#include <vector>
#include "PlayerStats.h"
#include "../team/Team.h"

using namespace std;

class TeamStats {
    Team* team;
    int matchID;
    int teamFGAttempts{};
    int teamFGMade{};
    int team2ptAttempts{};
    int team2ptMade{};
    int team3ptAttempts{};
    int team3ptMade{};
    int team4ptAttempts{};
    int team4ptMade{};
    int teamTurnovers{};
    int teamSteals{};
    vector<PlayerStats> playerStats;
public:
    explicit TeamStats(Team& team, int matchID);
    Team* getTeam() const;
    int getMatchID() const;
    int getTeamFGAttempts() const;
    int getTeamFGMade() const;
    int getTeam2ptAttempts() const;
    int getTeam2ptMade() const;
    int getTeam3ptAttempts() const;
    int getTeam3ptMade() const;
    int getTeam4ptAttempts() const;
    int getTeam4ptMade() const;
    int getTeamTurnovers() const;
    int getTeamSteals() const;
    vector<PlayerStats> getPlayerStats() const;
};


#endif //BASKETBALLENGINE_TEAMSTATS_H