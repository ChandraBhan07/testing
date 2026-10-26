#pragma once

#include <string>
#include <functional>

#include <iostream>

template <typename T>
class ThreadSafeQueue;

class Job;

class JobHistory;

class JobManager
{

    ThreadSafeQueue<Job> &incomingQueue;
    ThreadSafeQueue<Job> &outgoingQueue;
    JobHistory &jobHistory;

public:
    void run();

    JobManager(
        ThreadSafeQueue<Job> &incoming,
        ThreadSafeQueue<Job> &outgoing,
        JobHistory &history)
        : incomingQueue(incoming), outgoingQueue(outgoing), jobHistory(history) {};

    ~JobManager()
    {
        std::cout << "JobManager destructor called\n";
    }
};