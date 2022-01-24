#include "Time.hpp"

#ifndef TASK_MANAGER
#define TASK_MANAGER

#include <vector>
#include <thread>
#include <functional>
#include <mutex>
#include <queue>

class Task{
    TimeObj timeToExecute = {0};
    TimeObj repeatTime = {0};
    std::function<void()> function;
public:
    Task()= default;
    Task( const Task& other){
        timeToExecute = other.timeToExecute;
        repeatTime = other.repeatTime;
        function = other.function;
    }

    template<typename F>
    void setTask(std::function<F> f){
        this->function = f;
    }
    void setTime(const TimeObj& time){
        this->timeToExecute = time;
    }
    void addToCurrentTime(const TimeObj& time){
        this->timeToExecute = TimeObj::currentTimeObj() + time;
    }
    void repeatEvery(const TimeObj& time){
        this->repeatTime = time;
    }

    [[nodiscard]] long long time() const{
        return this->timeToExecute.get_time();
    }

    long long getrepeattime(){
        return this->repeatTime.get_time();
    }

    void run(bool join = false){
        std::thread thread = std::thread(this->function);
        if (join){
            thread.join();
        } else {
            thread.detach();
        }
    }

};
namespace{
class Compare
{
public:
    inline bool compare(Task a, Task b){
        return a.time() > b.time();
    }
    bool operator() (Task A, Task B)
    {
        return compare(A, B);
    }
};
}

long long getTime(){
    return TimeObj::currentTimeObj().get_time();
}


class TaskManager {
    std::priority_queue<Task, std::vector<Task>, Compare > taskList;
    std::mutex mutex;
    std::function<long long()> timeFunction;
public:
    volatile bool flag;
    TaskManager()=default;

    void addTask(Task task){
        this->mutex.lock();
        this->taskList.push(task);
        this->mutex.unlock();
    }

    void taskLoop(){
        this->mutex.lock();
        Task t; t = this->taskList.top();
        this->mutex.unlock();
        long long curTime = TimeObj::currentTimeObj().get_time();
        flag=true;
        while(flag){
            if (curTime > t.time()){

                t.run();
                this->mutex.lock();
                if (t.getrepeattime() > 0){
                    Task tempT(t);
                    tempT.addToCurrentTime(tempT.getrepeattime());
                    this->taskList.push(tempT);
                }

                this->taskList.pop();
                if (!this->taskList.empty()) t = this->taskList.top();
                else{
                    while (true){
                        this->mutex.lock();
                        if(!this->taskList.empty()){
                            break;
                        }
                        this->mutex.unlock();
                    }
                }
                this->mutex.unlock();

            }

            curTime = TimeObj::currentTimeObj().get_time();
        }
    }
};

#endif //TASK_MANAGER
