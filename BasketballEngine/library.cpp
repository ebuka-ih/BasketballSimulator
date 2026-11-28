#include "library.h"


#include <iostream>
#include <chrono>
#include <random>
#include <thread>

#include "cpp/game/Game.h"
#include "cpp/utils/TimeUtil.h"
#include "BasketballEngine.h"
#include "cpp/game/PlayerActions.h"
#include "snapshots/GameSnapshot.h"
using namespace std;
string convertQuarter(int seconds);

void hello() {
    GameRegistry& registry = BasketballEngine::getGameRegistry();
    auto home = Team(1);
    auto away = Team(2);
    auto p1 = Player(Player::Position::C);
    auto p2 = Player(Player::Position::PF);
    auto p3 = Player(Player::Position::SF);
    auto p4 = Player(Player::Position::PG);
    auto p5 = Player(Player::Position::SG);
    home.addPlayer(p1);
    home.addPlayer(p2);
    home.addPlayer(p3);
    home.addPlayer(p4);
    home.addPlayer(p5);
    auto p6 = Player(Player::Position::C);
    auto p7 = Player(Player::Position::PF);
    auto p8 = Player(Player::Position::SF);
    auto p9 = Player(Player::Position::PG);
    auto p10 = Player(Player::Position::SG);
    away.addPlayer(p6);
    away.addPlayer(p7);
    away.addPlayer(p8);
    away.addPlayer(p9);
    away.addPlayer(p10);

    const int g = registry.createGame(Game::GameType::REGULAR_SEASON, &home, &away);
    Game* game = registry.getGame(g);
    game->getBall().setHolder(&p1);
    GameGrid& grid = game->getGrid();
    grid.setCoordinate(p1, Coordinate(10, 10));
    grid.setCoordinate(p2, Coordinate(15, 10));
    grid.setCoordinate(p3, Coordinate(15, 15));
    grid.setCoordinate(p4, Coordinate(26, 10));
    grid.setCoordinate(p5, Coordinate(10, 0));
    grid.setCoordinate(p6, Coordinate(80, 10));
    grid.setCoordinate(p7, Coordinate(40, 10));
    grid.setCoordinate(p8, Coordinate(30, 15));
    grid.setCoordinate(p9, Coordinate(60, 10));
    grid.setCoordinate(p10, Coordinate(50, 0));

    //cout << "HOME ROSTER: " << endl;
    for (const auto& homePlayer : home.getPlayers()) {
        //cout << homePlayer->getId() << " Position: " << homePlayer->getPositionName() << endl;
    }
    //cout << "AWAY ROSTER: " << endl;
    for (const auto& awayPlayer : away.getPlayers()) {
        //cout << awayPlayer->getId() << " Position: " << awayPlayer->getPositionName() << endl;
    }
    GameClock& clock = game->getClock();
    clock.start();
    const auto interval = chrono::duration<double, milli>(10.0 / clock.getTps());
    auto next_tick = chrono::steady_clock::now();
    int elapsed = 0;
    game->play();
    while (!game->isFinished()) {
        next_tick += chrono::duration_cast<chrono::steady_clock::duration>(interval);
        elapsed++;
        game->tick();
        this_thread::sleep_until(next_tick);
       // PlayerActions::shoot(*game, p1);
    }
};
void getPlayerPositions(const int gameID, Coordinate *positions) {
    const GameRegistry& registry = BasketballEngine::getGameRegistry();
    const auto game = registry.getGame(gameID);
    if (!game || !positions) {
        return;
    }
    const auto& players = game->getGrid().getPlayers();
    for (int i = 0; i < 10; i++) {
        if (players[i]->isOnCourt()) {
            positions[i] = players[i]->getCoordinate().value();
        } else {
            positions[i] = Coordinate(-9999, -9999);
        }
    }
}
bool GetGameSnapshot(const int gameId, GameSnapshot* gameSnapshot) {
    cout << "CHECK [1]" << endl;
    if (gameSnapshot == nullptr) {
        cout << "SNAPSHOT IS NULL" << endl;
        return false;
    }

    const GameRegistry& registry = BasketballEngine::getGameRegistry();
    const auto game = registry.getGame(gameId);
    if (game == nullptr) {
        cout << "GAME DOES NOT EXIST OR IS NULL" << endl;
        return false;
    }
    cout << "CHECK [2]" << endl;
    const auto& clock = game->getClock();
    const string gameTime = TimeUtil::formatGameTime(clock.getTimeLeft(), 60);
    const string shotClockTime = TimeUtil::formatGameTime(clock.getShotClockTime(), 5);
    const string period = game->getPeriodString();
    const auto& home = game->getHome();
    const auto& away = game->getAway();
    TeamSnapshot homeSnapshot{};
    TeamSnapshot awaySnapshot{};

    int homeIndex = 0;
    int awayIndex = 0;
    cout << "CHECK [3]" << endl;
    for (const Player* player : game->getGrid().getPlayers()) {
        if (player == nullptr) {
            continue;
        }
        PlayerSnapshot playerSnapshot{};
        playerSnapshot.id = player->getId();
        playerSnapshot.position = player->getPosition();
        if (const auto& coordinate = player->getCoordinate()) {
            playerSnapshot.coordinate = *coordinate;
            playerSnapshot.hasCoordinate = true;
        } else {
            playerSnapshot.hasCoordinate = false;
        }
        if (!player->getTeam()) {
            continue;
        }
        if (player->getTeam()->getId() == home->getId()) {
            homeSnapshot.players[homeIndex++] = playerSnapshot;
        } else if (player->getTeam()->getId() == away->getId()) {
            awaySnapshot.players[awayIndex++] = playerSnapshot;
        }
    }
    cout << "CHECK [4]" << endl;
    gameSnapshot->id = gameId;
    snprintf(gameSnapshot->gameClock, sizeof(gameSnapshot->gameClock), "%s", gameTime.c_str());
    cout << "CHECK [5]" << endl;
    snprintf(gameSnapshot->shotClock, sizeof(gameSnapshot->shotClock), "%s", shotClockTime.c_str());
    cout << "CHECK [6]" << endl;
    snprintf(gameSnapshot->period, sizeof(gameSnapshot->period), "%s",  period.c_str());
    cout << "CHECK [7]" << endl;
    gameSnapshot->clockActive = game->getClock().isRunning();

    homeSnapshot.id = home->getId();
    homeSnapshot.score = game->getHomeScore();

    awaySnapshot.id = away->getId();
    awaySnapshot.score = game->getAwayScore();

    gameSnapshot->home = homeSnapshot;
    gameSnapshot->away = awaySnapshot;
    cout << "CHECK [8]" << endl;
    cout << "SNAPSHOT INFORMATION" << endl;
    cout << "ID: " << gameSnapshot->id << endl;
    cout << "CLOCK ACTIVE: " << gameSnapshot->clockActive << endl;
    cout << "GAME CLOCK: " << gameSnapshot->gameClock << endl;
    cout << "SHOT CLOCK: " << gameSnapshot->shotClock << endl;
    cout << "PERIOD: " << gameSnapshot->period << endl;
    cout << "TEAM INFORMATION: " << endl;
    cout << "HOME ID: " << gameSnapshot->home.id << endl;
    cout << "AWAY ID: " << gameSnapshot->away.id << endl;
    cout << "HOME PLAYERS: " << endl;
    for (const PlayerSnapshot snap : gameSnapshot->home.players) {
        cout  << "PLAYER: " << snap.id << " HAS POSITION: " << snap.hasCoordinate << endl;
    }
    cout << "\n" << "AWAY PLAYERS: " << endl;
    for (const PlayerSnapshot snap : gameSnapshot->away.players) {
        cout  << "PLAYER: " << snap.id << " HAS POSITION: " << snap.hasCoordinate << endl;
    }
    return true;
}