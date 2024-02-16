/**
 * @file RandomGenerator.h
 * @brief Header file for the RandomGenerator class.
 */

#ifndef RANDOMGENERATOR_H
#define RANDOMGENERATOR_H

#include <random>

/**
 * @class RandomGenerator
 * @brief A class for generating random integers.
 */
class RandomGenerator
{
public:
    /**
     * @brief Generate a random integer within the specified range.
     * @param min The minimum value of the range.
     * @param max The maximum value of the range.
     * @return A random integer between min and max (inclusive).
     */
    int random_int(int, int);
};

#endif // RANDOMGENERATOR_H
