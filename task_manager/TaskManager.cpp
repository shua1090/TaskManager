#include "TaskManager.hpp"

std::string TimeObj::to_string(){
            unsigned long long tempTime = time;
        int years = tempTime / 31556952000;
        tempTime %= 31556952000;
        int days = tempTime / 86400000;
        tempTime %= 86400000;
        int hours = tempTime / 3600000;
        tempTime %= 3600000;
        int minutes = tempTime / 60000;
        tempTime %= 60000;
        int seconds = tempTime / 1000;
        tempTime %= 1000;
        std::string time = "";
        time = time + std::to_string(years) + " years, " + 
            std::to_string(days) + " days, " + 
            std::to_string(hours) + " hours, and " + 
            std::to_string(minutes) + " minutes"; 
        return time;
}