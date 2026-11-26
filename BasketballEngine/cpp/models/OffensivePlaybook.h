//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_OFFENSIVEPLAYBOOK_H
#define BASKETBALLENGINE_OFFENSIVEPLAYBOOK_H
#include <vector>

#include "OffensivePlay.h"
using namespace std;

class OffensivePlaybook {
    vector<OffensivePlay> plays;
    void addPlay(OffensivePlay play);
    bool removePlay(int playID);
};


#endif //BASKETBALLENGINE_OFFENSIVEPLAYBOOK_H