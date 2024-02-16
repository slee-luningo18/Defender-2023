/**
 * @file LaserShots.h
 * @brief Defines the LaserShots class for managing laser shots in the game.
 */

#ifndef LASERSHOTS_H
#define LASERSHOTS_H
#include "LaserShot.h"
#include "GameObjectsContainer.h"

/**
 * @class LaserShots
 * @brief Represents a collection of laser shots in the game.
 *
 * This class extends the GameObjectsContainer and provides functionality
 * for adding and updating laser shots within the game.
 */
class LaserShots : public GameObjectsContainer
{
public:
    /**
     * @brief Constructor for the LaserShots class.
     */
    LaserShots();

    /**
     * @brief Adds a laser shot to the container.
     * @param x The x-coordinate of the laser shot.
     * @param y The y-coordinate of the laser shot.
     * @param xx The x-coordinate of the target (optional).
     * @param yy The y-coordinate of the target (optional).
     */
    virtual void add(double x, double y, double xx = 0, double yy = 0);

    /**
     * @brief Updates the laser shots.
     */
    virtual void update();

    /**
     * @brief Sets the heading for the laser shots.
     * @param heading The heading direction.
     */
    void setHeading(Heading);

private:
    Heading _heading; /**< The heading direction for laser shots. */
};

#endif // LASERSHOTS_H
