//
// Created by william on 11/24/2026.
//

#ifndef BASKETBALLENGINE_BASKETBALLENGINE_H
#define BASKETBALLENGINE_BASKETBALLENGINE_H
#include "cpp/registrar/GameRegistry.h"


class BasketballEngine {
    inline static  GameRegistry gameRegistry;
public:
    static  GameRegistry& getGameRegistry() {
        return gameRegistry;
    }
};


#endif //BASKETBALLENGINE_BASKETBALLENGINE_H