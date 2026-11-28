cmake_minimum_required(VERSION 4.0)
project(BasketballEngine)

set(CMAKE_CXX_STANDARD 20)

add_library(BasketballEngine SHARED library.cpp
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
        cpp/logic/CoachLogic.h
        cpp/logic/CoachLogic.h
        cpp/logic/CoachLogic.cpp
        cpp/logic/AnalystLogic.cpp
        cpp/management/Analyst.cpp
        cpp/management/Contract.cpp
        cpp/management/FinancePlan.cpp
        cpp/management/GeneralManager.cpp
        cpp/game/Possession.h
        cpp/game/Possession.cpp
        cpp/models/OffensivePlay.cpp
        cpp/models/OffensivePlaybook.cpp
        cpp/models/OffensiveScheme.cpp
        cpp/player/PlayAssignment.cpp
        cpp/game/PlayerActions.h
        cpp/game/PlayerActions.cpp
        cpp/game/mechanics/shooting/ShotTrajectory.h)