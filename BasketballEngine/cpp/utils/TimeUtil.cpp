//
// Created by william on 11/23/2026.
//

#include "TimeUtil.h"

#include <iomanip>
#include <iostream>
#include <sstream>


string TimeUtil::formatGameTime(const int time, const int secondsThreshold) {
    const int minutes = time / 6000;
    const int seconds = time / 100 % 60;
    const int tenths = (time % 100) / 10;
    ostringstream output;
    if (minutes > 0) {
        output <<  setfill('0')
        << setw(2) << minutes << ":"
        << setw(2) << seconds;
    } else {
        if (seconds <= secondsThreshold) {
            output << setw(2) << setfill('0') << seconds << "." << setw(1) << tenths;
        } else {
            output << setw(2) << setfill('0') << seconds;
        }
    }
    return output.str();
}
