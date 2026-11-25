//
// Created by william on 11/23/2026.
//

#ifndef BASKETBALLENGINE_TIMEUTIL_H
#define BASKETBALLENGINE_TIMEUTIL_H
#include <string>

using namespace std;
class TimeUtil {
public:
    static string formatGameTime(int time, int secondsThreshold);
};


#endif //BASKETBALLENGINE_TIMEUTIL_H