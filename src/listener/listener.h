#pragma once

#include <string>
#include <atomic>
#include <iostream>

template <typename T>
class ThreadSafeQueue;

class Listener
{
private:
    ThreadSafeQueue<std::string> &queue;

public:
    void run();
    Listener(ThreadSafeQueue<std::string> &queue) : queue(queue) {};
    void stop();

    ~Listener(){
        std::cout <<"listener destructor called\n";
    }
};