//
// Created by william on 11/27/2026.
//

#ifndef BASKETBALLENGINE_SHOTCONTEXT_H
#define BASKETBALLENGINE_SHOTCONTEXT_H
#include <cmath>
#include <iterator>

#include "../models/enums/ShotZone.h"
#include "../../grid/Coordinate.h"

struct ShotContext {

    Coordinate releasePosition;
    Coordinate targetPosition;

    double fatigue;
    double pressure;

    static double calculateIdealVelocity(const double distance) {
        return 20.0 + distance * 0.45;
    }
    [[nodiscard]] double getDistance() const {
        return std::hypot(targetPosition.x - releasePosition.x, targetPosition.y - releasePosition.y);
    }
    [[nodiscard]] ShotZone getShotZone() const {
        const double distance = getDistance();

        if (distance <= 5.0) return ShotZone::CLOSE_RANGE;
        if (distance <= 15.0) return ShotZone::MID_RANGE;
        if (distance <= 24.0) return ShotZone::DEEP_TWO;
        if (distance < 30.0) return ShotZone::THREE_POINT;
        if (distance < 35.0) return ShotZone::DEEP_THREE;
        if (distance <= 40.0) return ShotZone::FOUR_POINT;

        return ShotZone::DEEP_FOUR;
    }
};

#endif //BASKETBALLENGINE_SHOTCONTEXT_H