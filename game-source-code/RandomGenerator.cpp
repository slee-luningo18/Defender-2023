#include "RandomGenerator.h"

/**
 * @brief Generate a random integer within the specified range.
 * @param minimum The minimum value of the range.
 * @param maximum The maximum value of the range.
 * @return A random integer between minimum and maximum (inclusive).
 */
int RandomGenerator::random_int(int minimum, int maximum)
{
    static std::default_random_engine randomEngine{};
    using Distribution = std::uniform_int_distribution<int>;
    static Distribution uniformIntDistribution{};
    return uniformIntDistribution(randomEngine, Distribution::param_type{minimum, maximum});
}
