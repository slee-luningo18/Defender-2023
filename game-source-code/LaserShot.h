/**
 * @file LaserShot.h
 * @brief Defines the LaserShot class for representing a laser shot in the game.
 */

#ifndef LASERSHOT_H
#define LASERSHOT_H
#include "Utils.h"
#include "GameObject.h"

/**
 * @class LaserShot
 * @brief Represents a laser shot in the game.
 *
 * This class extends the GameObject class and provides functionality
 * for moving a laser shot in different directions.
 */
class LaserShot : public GameObject
{
public:
    /**
     * @brief Constructor for the LaserShot class.
     * @param x The initial x-coordinate of the laser shot.
     * @param y The initial y-coordinate of the laser shot.
     */
    LaserShot(double, double);

    /**
     * @brief Moves the laser shot in a specific direction.
     */
    virtual void Move();

private:
    /**
     * @brief Moves the laser shot to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the laser shot to the right.
     */
    void moveRight();
};

#endif // LASERSHOT_H
