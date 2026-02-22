#include "chrono.h"

void chrono::start()
{
    startTime = std::chrono::steady_clock::now();
    isRunning = true;
}

void chrono::stop()
{
    isRunning = false;
    stopTime = std::chrono::steady_clock::now();
}

const double chrono::getTime() const
{
    if (isRunning)
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - startTime).count();

    else
        return std::chrono::duration_cast<std::chrono::microseconds>(stopTime - startTime).count();
}