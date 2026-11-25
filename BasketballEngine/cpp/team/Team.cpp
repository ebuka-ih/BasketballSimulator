//
// Created by william on 11/21/2026.
//

#include "Team.h"
using namespace std;

Team::Team(const int id) : id(id), fanbase(Fanbase(*this)), arena(*this) {
}
void Team::addPlayer(Player& player) {
        player.setTeam(this);
        players.push_back(std::make_unique<Player>(std::move(player)));
}
void Team::removePlayer(int playerId) {
    players.erase(remove_if(players.begin(), players.end(), [playerId](const unique_ptr<Player>& player) {
        return player->getId() == playerId;
    }));
}
