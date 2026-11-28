//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_ANALYSTLOGIC_H
#define BASKETBALLENGINE_ANALYSTLOGIC_H
#include "../evaluations/TeamEvaluation.h"
#include "../evaluations/LineupEvaluation.h"
#include "../evaluations/PlayerEvalutation.h"
class AnalystLogic {
    public:
    PlayerEvalutation evaluatePlayer();
    TeamEvaluation evaluateTeam();
    TeamEvaluation analyzeOpponent();

    void scoutPlayer();
    void evaluatePotential();

    void predictionPerformance();
    void predictInjury();

    // DrillCategory recommendPracticeFocus();

    LineupEvaluation evaluateLineup();


};


#endif //BASKETBALLENGINE_ANALYSTLOGIC_H