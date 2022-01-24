
#include <iostream>
#include "TaskManager.hpp"

int toRun(){
    std::cout << "Hello World!" << std::endl;
    return 0;
}

int toRun2(){
    std::cout << "Hello World 2!" << std::endl;
    return 0;
}

int main(){
    Task task;
    task.setTask(std::function<int()>(toRun));
    task.addToCurrentTime(5_s);
    task.repeatEvery(5_s);

    Task task2;
    task2.setTask(std::function<int()>(toRun2));
    task2.addToCurrentTime(6_s);
    task2.repeatEvery(10_s);


    TaskManager manager;
    manager.addTask(task);
    manager.addTask(task2);
    manager.taskLoop();


    return 0;
}