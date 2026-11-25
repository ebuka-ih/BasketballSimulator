//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_COACHLOGIC_H
#define BASKETBALLENGINE_COACHLOGIC_H
class Player;
class Analyst;


class CoachLogic {
    public:
    void createOffensiveScheme();
    void reevaluateOffensiveScheme();
    void reworkOffensiveScheme();
    void adjustOffensiveScheme();
    void evaluateOffensivePerformance();
    void selectOffensivePlay();
    void callOffensivePlay();
    void createOffensivePlay();

    void delegatePlay(Player& player);
    void requestPlayRecommendation(Analyst& analyst);
    void callTimeout();
    void makeSubstitutions();

    void createPracticePlan();
    void selectPracticeDrills();
    void adjustPracticePlan();
    void setPracticeIntensity();
    void setPracticeDuration();
    void selectPracticeFocus();
    void evaluatePracticePerformance();
    void prepareForOpponent();

    void testPlay();
};


#endif //BASKETBALLENGINE_COACHLOGIC_H