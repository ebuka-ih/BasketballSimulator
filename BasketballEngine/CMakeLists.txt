cmake_minimum_required(VERSION 4.0)
project(BasketballEngine)

set(CMAKE_CXX_STANDARD 20)

add_library(BasketballEngine SHARED library.cpp
        cpp/player/Stats.cpp
        cpp/arena/Arena.h
        cpp/arena/Arena.cpp
        cpp/fans/Fanbase.h
        cpp/fans/Fanbase.cpp
        cpp/team/Team.h
        cpp/team/Team.cpp
        cpp/game/Game.h
        cpp/game/Game.cpp
        cpp/management/Analyst.h
        cpp/logic/AnalystLogic.h
        cpp/engine/GameEngine.cpp
        cpp/stats/TeamStats.h
        cpp/stats/TeamStats.cpp
        cpp/game/GameClock.h
        cpp/game/GameClock.cpp
        cpp/player/Player.h
        cpp/player/Player.cpp
        cpp/utils/TimeUtil.h
        cpp/utils/TimeUtil.cpp
        cpp/registrar/GameRegistry.h
        cpp/registrar/GameRegistry.cpp
        cpp/game/grid/GameGrid.cpp
        BasketballEngine.h
        cpp/game/objects/Ball.cpp
        snapshots/GameSnapshot.h
        snapshots/GameSnapshot.h
        cpp/pathfinder/Pathfinder.cpp)