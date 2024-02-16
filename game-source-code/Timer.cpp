#include "Timer.h"

/**
 * @brief Constructor for the Timer class.
 */
Timer::Timer()
{
    beginning = ending = 0.0;
}

/**
 * @brief Start the timer.
 */
void Timer::start()
{
    beginning = getProcessTime();
}

/**
 * @brief Read the elapsed time from the start of the timer.
 * @return Elapsed time in seconds.
 */
double Timer::readTime()
{
    ending = getProcessTime();
    return (ending - beginning);
}

/**
 * @brief Get the current process time.
 * @return The current process time in seconds.
 */
double Timer::getProcessTime()
{
    clock_t time = clock();
    return static_cast<double>(time) / CLOCKS_PER_SEC;
}

/**
 * @brief Delay the program for a specified duration in seconds.
 * @param time The duration to delay in seconds.
 */
void Timer::delay(double time)
{
    start();
    auto x = beginning;
    while (true)
    {
        x = readTime();
        if (x >= time)
            break;
    }
    return;
}