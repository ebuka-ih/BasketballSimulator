//
// Created by william on 11/27/2026.
//

#include "PlayerActions.h"
#include <iostream>

#include "Game.h"
#include "../player/Player.h"
using namespace std;
#include <random>

static std::mt19937 rng{std::random_device{}()};

double randomVariation(const double min, const double max) {
    std::uniform_real_distribution distribution(min, max);
    return distribution(rng);
}

PossessionLog::ShotOutcome PlayerActions::shoot(const Game& game, const Player &player) {
    const auto context = ShotContext {   player.getCoordinate().value(), game.getBasketCoordinate(player), 0, 0 };
    const double distance = context.getDistance();
    if (const ShotTrajectory trajectory = calculateTrajectory(player, context); trajectory.shotMade(distance)) {
        return PossessionLog::ShotOutcome::MADE;
    }
    return PossessionLog::ShotOutcome::MISSED;
}

double PlayerActions::calculateVelocity(const Player& player, const ShotContext& context) {

    const double idealVelocity =  ShotContext::calculateIdealVelocity(context.getDistance());
    const Stats stats = player.getStats();

    const double consistency = stats.getShootingStat(context.getShotZone()) / 100.0;
    const double variation = 1.5 * (1.0 - consistency);

    double velocity = idealVelocity + randomVariation(-variation, variation);
    velocity *= 1.0 - 0.0015 * context.fatigue;
    velocity *= 1.0 - 0.0005 * context.pressure;
    return velocity;
}
double PlayerActions::calculateLaunchAngle(const Player& player, const ShotContext& context, const double distance, const double velocity, const double initialHeight, const double targetHeight) {
    double low = 0.0;
    double high = 89.0;
    for (int i = 0; i < 20; i++) {
        constexpr double PI = 3.14159265358979323846;
        constexpr double GRAVITY = 32.174;
        const double angle = (low + high) / 2.0;
        const double radians = angle * PI / 180.0;

        const double height =
            initialHeight
            + distance * std::tan(radians)
            - (GRAVITY * distance * distance) /
              (2.0 * velocity * velocity *
               std::pow(std::cos(radians), 2));

        if (height < targetHeight) {
            low = angle;
        } else {
            high = angle;
        }
    }
    const Stats stats = player.getStats();
    static std::mt19937 generator(std::random_device{}());

    const double consistency = std::clamp(stats.getShootingStat(context.getShotZone()) / 100.0, 0.0, 1.0);
    constexpr double MAX_DEVIATION = 7.5;
    const double standardDeviation = (1.0 - consistency) * MAX_DEVIATION;
    normal_distribution distribution(0.0, standardDeviation);
    return (low + high) / 2.0 + distribution(generator);
}
ShotTrajectory PlayerActions::calculateTrajectory(const Player& player, const ShotContext& context) {
    constexpr double height = 6.0;
    const double velocity = calculateVelocity(player, context);
    const double angle = calculateLaunchAngle(player, context, context.getDistance(), velocity, height, 10.0);
    return { velocity, angle,height };
}

