//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_ARENA_H
#define BASKETBALLENGINE_ARENA_H
class Team;

class Arena {
    Team* owner;
    int id{};
    int capacity{};
    int atmosphere{};

    int upperCapacity{};
    int lowerCapacity{};
    int courtsideCapacity{};

    double baseTicketPrice{};
    double foodMin{};
    double foodMax{};
    double merchMin{};
    double merchMax{};
    public:
    explicit Arena(Team& team);

    [[nodiscard]] const Team* getOwner() const;
    [[nodiscard]] int getCapacity() const;
    [[nodiscard]] int getAtmosphere() const;
    [[nodiscard]] int getUpperCapacity() const;
    [[nodiscard]] int getLowerCapacity() const;
    [[nodiscard]] int getCourtsideCapacity() const;
    [[nodiscard]] double getBaseTicketPrice() const;
    [[nodiscard]] double getFoodMin() const;
    [[nodiscard]] double getFoodMax() const;
    [[nodiscard]] double getMerchMin() const;
    [[nodiscard]] double getMerchMax() const;

};


#endif //BASKETBALLENGINE_ARENA_H