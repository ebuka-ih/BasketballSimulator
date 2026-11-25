//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_PLAYEREVALUTATIONS_H
#define BASKETBALLENGINE_PLAYEREVALUTATIONS_H


class PlayerEvalutations {
private:
    int season;
    int gamesPlayed;
    int totalGames;

    double averagePoints;
    double averageFieldGoalAttempts;
    double averageFieldGoalPercentage;
    double averageFreeThrowAttempts;
    double averageTwoPointAttempts;
    double averageTwoPointersMade;
    double averageTwoPointPercentage;
    double averageThreePointAttempts;
    double averageThreePointersMade;
    double averageThreePointPercentage;
    double averageFourPointAttempts;
    double averageFourPointersMade;
    double averageFourPointPercentage;

    double averageRebounds;
    double averageOffensiveRebounds;
    double averageDefensiveRebounds;

    double averageAssists;
    double averageSteals;
    double averageBlocks;
    double averageDefensiveFouls;
    double averageTurnovers;

    double averageMinutesPlayed;
    double usageRate;
    double efficiency;
    double consistencyRate;

    double performanceScore;
    double performanceScoreWithout;
    double trueShootingPercentage;
    double effectiveFieldGoalPercentage;
    double offensiveScore;
    double defensiveScore;
};


#endif //BASKETBALLENGINE_PLAYEREVALUTATIONS_H