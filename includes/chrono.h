#pragma once
#include <chrono>

class chrono
{
private:
    std::chrono::steady_clock::time_point startTime;
    std::chrono::steady_clock::time_point stopTime;
    bool isRunning;

public:
    chrono() : isRunning(false) {};
    void start();
    void stop();
    const double getTime() const;
};