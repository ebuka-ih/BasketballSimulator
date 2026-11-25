//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_FAN_H
#define BASKETBALLENGINE_FAN_H


class FanSegment {
    public:
    enum class FanType {
        CASUAL,
        FAIR_WEATHER,
        BANDWAGON,
        FANTASY,
        SOCIAL,
        LOCAL,
        DIE_HARD
    };
    private:
    FanType fanType;
    long population;

    double averageLoyalty;
    double averageSatisfaction;
    double averageEngagement;

    double averageSpendingPower;
    double averageMerchandiseInterest;
    double averageTicketInterest;

    double averageGamesAttended;
    double averageSeasonsSupported;

};


#endif //BASKETBALLENGINE_FAN_H