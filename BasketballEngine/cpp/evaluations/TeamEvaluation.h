//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_TEAMEVALUATION_H
#define BASKETBALLENGINE_TEAMEVALUATION_H
#include "../team/Team.h"

class TeamEvaluation {
    private:
    int season;
    Team team;

    double averagePoints;
    double averagePointsAllowed;
    double averagePointDifferential;

    double averageFieldGoalPercentage;
    double averageTwoPointPercentage;
    double averageThreePointPercentage;
    double averageFourPointPercentage;

    double averageBenchPoints;
    double averageSecondChancePoints;
    double averageSecondChanceAttempts;
    double chemistry;
    double clutchPerformance;


    double averageRebounds;
    double averageOffensiveRebounds;
    double averageDefensiveRebounds;

    double averageAssists;
    double averageTurnovers;

    double averageSteals;
    double averageBlocks;
    double averageDefensiveFouls;

    double offensiveRating;
    double defensiveRating;
    double efficiency;
    double consistencyRate;

    double offensiveScore;
    double defensiveScore;
    double overallScore;
};


#endif //BASKETBALLENGINE_TEAMEVALUATION_H