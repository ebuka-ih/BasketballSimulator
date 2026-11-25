//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_CONTRACT_H
#define BASKETBALLENGINE_CONTRACT_H
#include "../player/Player.h"
#include "../team/Team.h"


class Contract {
    public:
    enum class ContractType {
        ROOKIE,
        STANDARD,
        SUPERSTAR
    };
    enum class ContractOption {
        PLAYER_OPTION,
        TEAM_OPTION,
        NO_TRADE
    };
    private:
    int id;
    Player player;
    Team team;
    double totalMoney;
    int duration;
    int startYear;
    bool active;
};


#endif //BASKETBALLENGINE_CONTRACT_H