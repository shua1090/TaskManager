#include <chrono>
#include <string>

class TimeObj{
    unsigned long long time;
    // Milliseconds in a year: 31,556,952,000
    
    public:
    TimeObj(unsigned long long time){
        this->time = time;
    }
    std::string to_string();
    TimeObj operator+(TimeObj input);
    TimeObj operator-(TimeObj input);

    static TimeObj currentTimeObj(){
        return TimeObj(std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count());
    }
};