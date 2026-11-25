//
// Created by william on 11/21/2026.
//

#ifndef BASKETBALLENGINE_PLAYERSTATS_H
#define BASKETBALLENGINE_PLAYERSTATS_H


class PlayerStats {
    int matchID;
    int FGAttempts;
    int FGMade;
    int twoPtAttempts;
    int twoPtMade;
    int threePtAttempts;
    int threePtMade;
    int fourPtAttempts;
    int fourPtMade;
    int turnovers;
    int steals;
public:
    explicit PlayerStats(int matchID);
    int getMatchID() const;
    int getFGAttempts() const;
    int getFGMade() const;
    int getTwoPtAttempts() const;
    int getTwoPtMade() const;
    int getThreePtAttempts() const;
    int getThreePtMade() const;
    int getFourPtAttempts() const;
    int getFourPtMade() const;
    int getTurnovers() const;
    int getSteals() const;

    void addTwoPtAttempt(bool made);
    void addThreePtAttempt(bool made);
    void addFourPtAttempt(bool made);
    void addTurnover();
    void addSteal();



};


#endif //BASKETBALLENGINE_PLAYERSTATS_H