//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_FANBASE_H
#define BASKETBALLENGINE_FANBASE_H


class Team;

class Fanbase {
    Team* team;
public:
    explicit Fanbase(Team& team);
};


#endif //BASKETBALLENGINE_FANBASE_H