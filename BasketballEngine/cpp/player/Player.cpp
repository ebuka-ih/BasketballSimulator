//
// Created by william on 11/21/2026.
//

#include "Player.h"

string Player::getPositionName() const {
    switch (position) {
        case Position::PG: return "PG";
        case Position::SG: return "SG";
        case Position::SF: return "SF";
        case Position::PF: return "PF";
        case Position::C:  return "C";
    }
    return "Unknown";
}
