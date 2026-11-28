//
// Created by william on 9/10/2026.
//

#ifndef SIMULATIONENGINE_STATS_H
#define SIMULATIONENGINE_STATS_H
#include <iostream>
#include <ostream>
#include <stdexcept>


class Stats {
    int finishing;
    int midrange;
    int threePoint;
    int fourPoint;
    int ballHandling;
    int passing;

    int physicalDefense;
    int perimeterDefense;
    int stealing;
    int blocking;
    int rebounding;

    int speed;
    int stamina;

    int clutch;
    int consistency;
    int confidence;

    public:
    Stats() : finishing(50), midrange(50), threePoint(50), fourPoint(50),
              ballHandling(50), passing(50),
              physicalDefense(50), perimeterDefense(50), stealing(50),
              blocking(50), rebounding(50),
              speed(50), stamina(50),
              clutch(50), consistency(50), confidence(50) {}
    explicit Stats(const int (&stats)[16]) : finishing(stats[0]), midrange(stats[1]), threePoint(stats[2]), fourPoint(stats[3]), ballHandling(stats[4]), passing(stats[5]),
                                             physicalDefense(stats[6]), perimeterDefense(stats[7]), stealing(stats[8]), blocking(stats[9]), rebounding(stats[10]),
                                             speed(stats[11]), stamina(stats[12]), clutch(stats[13]), consistency(stats[14]), confidence(stats[15]) {}
    [[nodiscard("finishing ignored")]]int getFinishing() const { return finishing; }
    [[nodiscard("midrange ignored")]]int getMidrange() const { return midrange; }
    [[nodiscard("three point ignored")]]int getThreePoint() const { return threePoint; }
    [[nodiscard("four point ignored")]]int getFourPoint() const { return fourPoint; }
    [[nodiscard("ball handling ignored")]]int getBallHandling() const { return ballHandling; }
    [[nodiscard("passing ignored")]]int getPassing() const { return passing; }
    [[nodiscard("physical defense ignored")]]int getPhysicalDefense() const { return physicalDefense; }
    [[nodiscard("perimeter defense ignored")]]int getPerimeterDefense() const { return perimeterDefense; }
    [[nodiscard("stealing ignored")]]int getStealing() const { return stealing; }
    [[nodiscard("blocking ignored")]]int getBlocking() const { return blocking; }
    [[nodiscard("rebounding ignored")]]int getRebounding() const { return rebounding; }
    [[nodiscard("speed ignored")]]int getSpeed() const { return speed; }
    [[nodiscard("stamina ignored")]]int getStamina() const { return stamina; }
    [[nodiscard("clutch ignored")]]int getClutch() const { return clutch; }
    [[nodiscard("consistency ignored")]]int getConsistency() const { return consistency; }
    [[nodiscard("confidence ignored")]]int getConfidence() const { return confidence; }
    [[nodiscard]] int getShootingStat(const ShotZone zone) const {
        switch (zone) {
            case ShotZone::CLOSE_RANGE:
                cout << "SHOOTING STAT (FINISHING): " << finishing << endl;
                return finishing;

            case ShotZone::MID_RANGE:
            case ShotZone::DEEP_TWO:
                cout << "SHOOTING STAT (MID RANGE): " << midrange << endl;
                return midrange;

            case ShotZone::THREE_POINT:
            case ShotZone::DEEP_THREE:
                cout << "SHOOTING STAT (THREE POINT): " << threePoint << endl;
                return threePoint;

            case ShotZone::FOUR_POINT:
            case ShotZone::DEEP_FOUR:
                cout << "SHOOTING STAT (FOUR POINT): " << fourPoint << endl;
                return fourPoint;
        }
        throw std::invalid_argument("Invalid shot zone");
    }
};


#endif //SIMULATIONENGINE_STATS_H