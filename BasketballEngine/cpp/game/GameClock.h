//
// Created by william on 11/23/2026.
//

#ifndef BASKETBALLENGINE_GAMECLOCK_H
#define BASKETBALLENGINE_GAMECLOCK_H
class Game;

class GameClock {
    Game* game;
    int timeLeft;
    int shotClockTime;
    bool running = false;
    bool shotClockRunning = true;
    const int tps = 1;
    public:
    void start();
    void pause();
    void tick();
    void reset(int time);

    explicit GameClock(Game& game);
    [[nodiscard]] bool isFinished() const;
    [[nodiscard]] int getTps() const { return tps; }
    [[nodiscard]] int getTimeLeft() const { return timeLeft; }
    [[nodiscard]] int getShotClockTime() const { return shotClockTime; }
    [[nodiscard]] bool isRunning() const { return running; }
};
#endif //BASKETBALLENGINE_GAMECLOCK_H