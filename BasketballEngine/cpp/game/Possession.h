//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_POSSESSION_H
#define BASKETBALLENGINE_POSSESSION_H
class OffensivePlay;
using namespace std;
class Team;
class Player;

class Possession {
    Team* offense;
    OffensivePlay* currentPlay = nullptr;
    int shotClock;
    int timeStarted;
    int elapsedTime;
    bool active;

    public:
    explicit Possession(Team& offense);
    void tick();
    void end();
    void isActive() const;
    int getStartTime() const;
    int getShotClock() const;
    int getElapsedTime() const;

};


#endif //BASKETBALLENGINE_POSSESSION_H