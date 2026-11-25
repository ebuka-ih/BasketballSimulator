//
// Created by william on 11/24/2026.
//

#ifndef BASKETBALLENGINE_GAMEREGISTRY_H
#define BASKETBALLENGINE_GAMEREGISTRY_H
#include <memory>
#include <unordered_map>
#include "../game/Game.h"
using namespace std;

class GameRegistry {
    unordered_map<int, unique_ptr<Game>> games;
    int nextId = 0;

    public:
    GameRegistry() = default;
    [[nodiscard]] int createGame(Game::GameType type, Team* home = nullptr, Team* away = nullptr);
    [[nodiscard]] bool loadGame(int gameID);
    [[nodiscard]] bool saveGame(int gameID);
    [[nodiscard]] bool saveAll();
    [[nodiscard]] bool loadAll();
    [[nodiscard]] bool deleteGame(int gameID);
    [[nodiscard]] Game* getGame(int gameID);
    [[nodiscard]] const Game* getGame(int gameID) const;
    [[nodiscard]] bool hasGame(int gameID) const;
};


#endif //BASKETBALLENGINE_GAMEREGISTRY_H