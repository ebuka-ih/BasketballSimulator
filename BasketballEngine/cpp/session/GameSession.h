//
// Created by william on 11/25/2026.
//

#ifndef BASKETBALLENGINE_GAMESESSION_H
#define BASKETBALLENGINE_GAMESESSION_H


class GameSession {
    GameId currentGame;
    GameEngine* engine;

    public:
        void watchGame(int gameId);
};


#endif //BASKETBALLENGINE_GAMESESSION_H1