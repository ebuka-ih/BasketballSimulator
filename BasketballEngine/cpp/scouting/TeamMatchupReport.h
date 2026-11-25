//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_TEAMMATCHUPREPORT_H
#define BASKETBALLENGINE_TEAMMATCHUPREPORT_H
#include <vector>

class TeamMatchupReport {
    public:
    enum class TeamPlayStyle {
        FAST_PACED,
        SLOW_PACED,
        PERIMETER_HEAVY,
        THREE_POINT_HEAVY,
        FOUR_POINT_HEAVY,
        MID_RANGE_HEAVY,
        INTERIOR_HEAVY,
        POST_HEAVY,
        OFF_BALL_MOVEMENT_HEAVY,
        BALL_MOVEMENT_HEAVY,
        ISOLATION_HEAVY
    };
    struct PlayStyleRating {
        TeamPlayStyle style;
        double score;
        double confidence;
    };
private:
    double offensiveRating;
    double averagePoints;
    double fieldGoalPercentage;
    double threePointPercentage;
    double fourPointPercentage;
    double turnoverRate;
    double assistRate;

    double defensiveRating;
    double averagePointsAllowed;
    double stealsPerGame;
    double blocksPerGame;
    double foulsPerGame;
    double defensiveReboundsPerGame;

    double opponentOffensiveRating;
    double opponentAveragePoints;
    double opponentFieldGoalPercentage;
    double threePointPercentage;
    double fourPointPercentage;
    double turnoverRate;
    double assistRate;

    double opponentDefensiveRating;
    double opponentAveragePointsAllowed;
    double opponentStealsPerGame;
    double opponentBlocksPerGame;
    double opponentFoulsPerGame;
    double opponentDefensiveReboundsPerGame;

    double opponentFieldGoalPercentage;
    double opponentTwoPointPercentage;
    double opponentThreePointPercentage;
    double opponentFourPointPercentage;
    double opponentTurnoverRate;
    double opponentOffensiveReboundsPerGame;
    double opponentBenchPoints;

    vector<TeamPlayStyle> playStyles;

};


#endif //BASKETBALLENGINE_TEAMMATCHUPREPORT_H