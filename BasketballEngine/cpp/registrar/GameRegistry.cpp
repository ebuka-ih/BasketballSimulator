
#include "GameRegistry.h"
int GameRegistry::createGame(Game::GameType type, Team* home, Team* away) {
    int id = nextId++;
    games.emplace(id, std::make_unique<Game>(id, type, home, away));
    return id;
}
bool GameRegistry::deleteGame(const int gameID) {
    return true;
}
Game* GameRegistry::getGame(const int gameID) {
    const auto g = games.find(gameID);

    if (g == games.end()) {
        return nullptr;
    }
    return g->second.get();
}
const Game* GameRegistry::getGame(const int gameID) const {
    auto g = games.find(gameID);

    if (g == games.end()) {
        return nullptr;
    }
    return g->second.get();
}
bool GameRegistry::hasGame(const int gameID) const {
    return games.contains(gameID);
}
