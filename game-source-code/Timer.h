/**
 * @file Timer.h
 * @brief Header file for the Timer class.
 */

#ifndef TIMER_H
#define TIMER_H
#include <ctime>

/**
 * @class Timer
 * @brief A simple timer utility class for measuring elapsed time.
 */
class Timer
{
public:
    /**
     * @brief Constructor for the Timer class.
     */
    Timer();

    /**
     * @brief Start the timer.
     */
    void start();

    /**
     * @brief Read the elapsed time from the start of the timer.
     * @return Elapsed time in seconds.
     */
    double readTime();

    /**
     * @brief Delay the program for a specified duration in seconds.
     * @param seconds The duration to delay in seconds.
     */
    void delay(double);

private:
    /**
     * @brief Get the current process time.
     * @return The current process time in seconds.
     */
    double getProcessTime();

    double beginning;  ///< The starting time of the timer.
    double ending;     ///< The ending time of the timer.
};

#endif