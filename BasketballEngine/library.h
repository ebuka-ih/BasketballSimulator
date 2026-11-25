#ifndef BASKETBALLENGINE_LIBRARY_H
#define BASKETBALLENGINE_LIBRARY_H
#include "BasketballEngine.h"

struct GameSnapshot;

extern "C" {
    __declspec(dllexport) void hello();

    inline __declspec(dllexport) BasketballEngine* createBasketballEngine() {
        return new BasketballEngine();
    }

    inline __declspec(dllexport) void destroyBasketballEngine(BasketballEngine* engine) {
        delete engine;
    }
    __declspec(dllexport) void getPlayerPositions(int gameID, Coordinate* positions);
    __declspec(dllexport) bool GetGameSnapshot(int gameId, GameSnapshot* snapshot);
}

#endif // BASKETBALLENGINE_LIBRARY_H