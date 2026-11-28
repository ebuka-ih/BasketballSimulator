//
// Created by william on 11/27/2026.
//

#ifndef BASKETBALLENGINE_SHOTTRAJECTORY_H
#define BASKETBALLENGINE_SHOTTRAJECTORY_H
#include <cmath>
#include <iostream>
using namespace std;

struct ShotTrajectory {
    double initialVelocity;
    double launchAngle;
    double initialHeight;

    [[nodiscard]] double getHeight(const double distance) const {
        constexpr double PI = 3.14159265358979323846;
        constexpr double GRAVITY = 32.174;
        const double angle = launchAngle * PI / 180.0;
        return initialHeight
            + distance * tan(angle)
            - GRAVITY * pow(distance, 2)
              / (2 * pow(initialVelocity, 2) * pow(cos(angle), 2));
    }
    [[nodiscard]] double getSlope(const double distance) const {
        constexpr double PI = 3.14159265358979323846;
        constexpr double GRAVITY = 32.174;

        const double angle = launchAngle * PI / 180.0;

        return tan(angle)
            - GRAVITY * distance
              / (initialVelocity * initialVelocity * pow(cos(angle), 2));
    }
    [[nodiscard]] bool shotMade(const double hoopDistance) const {
        constexpr double HOOP_HEIGHT = 10.0;
        constexpr double RIM_RAD = 0.75;
        constexpr double BALL_RAD = 0.375;

        const double height = getHeight(hoopDistance);
        const double slope = getSlope(hoopDistance);

        constexpr double lowerBound = HOOP_HEIGHT - RIM_RAD + BALL_RAD;
        constexpr double upperBound = HOOP_HEIGHT + RIM_RAD - BALL_RAD;

        const bool heightValid = height >= lowerBound && height <= upperBound;
        const bool descending = slope < 0.0;
        std::cout << "\n--- SHOT DEBUG ---\n"
                  << "Hoop distance: " << hoopDistance << '\n'
                  << "Height at hoop: " << height << '\n'
                  << "Slope at hoop: " << slope << '\n'
                  << "Lower bound: " << lowerBound << '\n'
                  << "Upper bound: " << upperBound << '\n'
                  << "Height valid: " << std::boolalpha << heightValid << '\n'
                  << "Descending: " << descending << '\n'
                  << "Shot made: " << (heightValid && descending) << '\n';

        return height >= lowerBound && height <= upperBound && slope < 0.0;
    }
};
#endif //BASKETBALLENGINE_SHOTTRAJECTORY_H