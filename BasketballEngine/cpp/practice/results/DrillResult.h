//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_DRILLRESULT_H
#define BASKETBALLENGINE_DRILLRESULT_H

class Player;

class DrillResult {
    Player* player;
    int attempts;
    int successfulAttempts;

    double performance;
    double fatigue;
};


#endif //BASKETBALLENGINE_DRILLRESULT_H