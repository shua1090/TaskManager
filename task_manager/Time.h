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

    std::string to_string() const;
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

    TimeObj(TimeObj const &obj);
};

TimeObj operator "" _m(unsigned long long int time);
TimeObj operator "" _s(unsigned long long int time);
TimeObj operator "" _h(unsigned long long int time);
TimeObj operator "" _d(unsigned long long int time);

#endif //TASK_MANAGER_TIME_H
