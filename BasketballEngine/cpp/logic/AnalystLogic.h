//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_ANALYSTLOGIC_H
#define BASKETBALLENGINE_ANALYSTLOGIC_H


class AnalystLogic {
    public:
    PlayerEvaluation evaluatePlayer();
    TeamEvaluation evaluateTeam();
    TeamEvaluation analyzeOpponent();

    void scoutPlayer();
    void evaluatePotential();

    void predictionPerformance();
    void predictInjury();

    DrillCategory recommendPracticeFocus();

    LineupEvaluation evaluateLineup();


};


#endif //BASKETBALLENGINE_ANALYSTLOGIC_H