//
// Created by william on 11/22/2026.
//

#ifndef BASKETBALLENGINE_OFFENSIVESCHEME_H
#define BASKETBALLENGINE_OFFENSIVESCHEME_H

#include "enums/OffensiveFocus.h"
#include "enums/Tempo.h"
#include "enums/BallMovement.h"
#include "enums/ReboundingStrategy.h"

class OffensiveScheme {
    Tempo tempo = Tempo::BALANCED;
    OffensiveFocus focus = OffensiveFocus::BALANCED;
    BallMovement ballMovement = BallMovement::MODERATE;
    ReboundingStrategy reboundingStrategy = ReboundingStrategy::BALANCED;

public:
    [[nodiscard]] Tempo getTempo() const;
    [[nodiscard]] OffensiveFocus getFocus() const;
    [[nodiscard]] BallMovement getBallMovement() const;
    [[nodiscard]] ReboundingStrategy getReboundingStrategy() const;

    void setTempo(Tempo tempo);
    void setFocus(OffensiveFocus focus);
    void setBallMovement(BallMovement ballMovement);
    void setReboundingStrategy(ReboundingStrategy reboundingStrategy);
};


#endif //BASKETBALLENGINE_OFFENSIVESCHEME_H