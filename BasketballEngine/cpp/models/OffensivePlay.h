//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PLAY_H
#define BASKETBALLENGINE_PLAY_H
#include <optional>
#include <vector>

#include "enums/ShotZone.h"
#include "enums/Tempo.h"
class Player;
class Team;
using namespace std;

class OffensivePlay {
public:
    enum class PlayType {
        PICK_AND_ROLL,
        ISOLATION,
        POST_UP,
        OFF_BALL_SCREEN,
        GIVE_AND_GO,
        MOTION_OFFENSE
    };
    enum class PlayState {
        CALLED,
        IN_PROGRESS,
        COMPLETED,
        FAILED
    };
    enum class Formation {
        FIVE_OUT,
        FOUR_OUT_ONE_IN,
        THREE_OUT_TWO_IN,
        HORNS,
        BOX,
        NONE
    };
    struct ShotPreference {
        ShotZone zone;
        int priority;
    };
private:
    Team* offense = nullptr;
    PlayType playType;

    optional<Tempo> tempo;
    optional<Formation> formation;
    vector<Player*> scoringOptions;
    vector<Player*> screeners;
    vector<ShotPreference> shotPreferences;
    OffensivePlay(Team& team, PlayType playType);
public:
    Tempo getTempo();
    void setTempo(Tempo tempo);
    Formation getFormation();
    void setFormation(Formation formation);
    vector<Player*> getScoringOptions();
    vector<Player*> getScreeners();
    vector<ShotPreference> getShotPreferences();
};


#endif //BASKETBALLENGINE_PLAY_H