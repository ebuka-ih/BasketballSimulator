//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_PRACTICEDRILL_H
#define BASKETBALLENGINE_PRACTICEDRILL_H
#include "enums/DrillType.h"
#include "enums/DrillCategory.h"
#include "enums/DrillIntensity.h"
#include "enums/DrillDifficulty.h"
#include <vector>
class Player;
using namespace std;

class PracticeDrill {
    DrillType type;
    DrillCategory category;
    DrillIntensity intensity;
    DrillDifficulty difficulty;
    int duration;
    int reps;
    vector<Player*> participants;
public:
    PracticeDrill(DrillType type, DrillCategory category, DrillIntensity intensity, DrillDifficulty difficulty, int duration);
    [[nodiscard]] DrillType getType() const;
    [[nodiscard]] DrillCategory getCategory() const;
    [[nodiscard]] DrillIntensity getIntensity() const;
    [[nodiscard]] DrillDifficulty getDifficulty() const;
    [[nodiscard]] int getDuration() const;
    [[nodiscard]] int getReps() const;
    [[nodiscard]] vector<Player*> getParticipants() const;
};


#endif //BASKETBALLENGINE_PRACTICEDRILL_H