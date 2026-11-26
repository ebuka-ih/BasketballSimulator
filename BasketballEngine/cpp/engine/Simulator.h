//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_SIMULATOR_H
#define BASKETBALLENGINE_SIMULATOR_H


class Simulator {
    void initializeSimulator();
    void simulateSeason(Season season);
    void simulateGame();
    void simulateRegularSeason();
    void simulatePlayoffs();

    void advanceDay();
    void advanceWeek();
    void advanceToNextGame();

    void simulateGameAtRegular();

    void pause();
    void resume();
    void stop();

    void setSimulationSpeed();
};


#endif //BASKETBALLENGINE_SIMULATOR_H