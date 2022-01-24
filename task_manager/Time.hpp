//
// Created by shynn on 1/22/2022.
//

#ifndef TASK_MANAGER_TIME_H
#define TASK_MANAGER_TIME_H

#include <chrono>
#include <string>
#include <stdexcept>
#include <ctime>
#include <iostream>


class TimeObj{

    long long time;

public:
    TimeObj()=default;

    TimeObj(long long time){
        this->time = time;
    }

    std::string to_string() const {
        unsigned long long tempTime = this->time;
        std::string timeStr;
        int days = (int)( tempTime / 86400000 );
        tempTime %= 86400000;
        if (days > 0){
            timeStr += std::to_string(days) + " days ";
        }
        int hours = (int)( tempTime / 3600000 );
        tempTime %= 3600000;
        if (hours > 0){
            timeStr += std::to_string(hours) + " hours ";
        }
        int minutes = (int)( tempTime / 60000 );
        tempTime %= 60000;
        if (minutes > 0){
            timeStr += std::to_string(minutes) + " minutes ";
        }
        int seconds = (int)( tempTime / 1000 );
        tempTime %= 1000;
        if (seconds > 0){
            timeStr += std::to_string(seconds) + " seconds ";
        }
        return timeStr;
    }

    TimeObj operator+(const TimeObj& other) const{
        return {this->time + other.time};
    }
    TimeObj operator-(const TimeObj& other) const{
        if (other.time > this->time){
            throw std::out_of_range("TimeObj::operator-(): other.time < this->time");
        }
        return {this->time - other.time};
    }

    long long get_time() const{
        return this->time;
    }

    bool operator<(const TimeObj& other) const{
        return this->time < other.time;
    }
    bool operator>(const TimeObj& other) const{
        return this->time > other.time;
    }
    bool operator<=(const TimeObj& other) const{
        return this->time <= other.time;
    }
    bool operator>=(const TimeObj& other) const{
        return this->time >= other.time;
    }

    static TimeObj currentTimeObj(){
        return {std::chrono::duration_cast<std::chrono::milliseconds>(
                std::chrono::system_clock::now().time_since_epoch()).count()};
    }

    TimeObj(TimeObj const &obj) {
        this->time = obj.time;
    }
};


TimeObj operator "" _m(unsigned long long int time) {
    return {static_cast<long long>(time*60 * 1000)};
}

TimeObj operator "" _s(unsigned long long int time) {
    return {static_cast<long long>(time*1000)};
}

TimeObj operator "" _h (unsigned long long int time) {
    return {static_cast<long long>(time*60*60*1000)};
}

TimeObj operator "" _d (unsigned long long int time) {
    return {static_cast<long long>(time*24*60*60*1000)};
}

#endif //TASK_MANAGER_TIME_H
