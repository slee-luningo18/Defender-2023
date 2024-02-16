/**
 * @file Humanoid.h
 * @brief Defines the Humanoid class for representing in-game humanoid characters.
 *
 * The Humanoid class is a specialized type of GameObject, representing characters with specific behaviors.
 * This class contains methods for moving the humanoid in different directions and handles behavior changes.
 */

#ifndef HUMANOID_H
#define HUMANOID_H

#include "GameObject.h"
#include "RandomGenerator.h"
#include "Timer.h"

class Humanoid : public GameObject
{
public:
    /**
     * @brief Construct a new Humanoid object.
     *
     * @param x Initial X-coordinate position.
     * @param y Initial Y-coordinate position.
     */
    Humanoid(double, double);

    /**
     * @brief Move the humanoid based on its current state and behavior.
     */
    virtual void Move();

private:
    /**
     * @brief Move the humanoid to the left.
     */
    void moveLeft();

    /**
     * @brief Move the humanoid to the right.
     */
    void moveRight();

    /**
     * @brief Move the humanoid upwards.
     */
    void moveUp();

    /**
     * @brief Move the humanoid downwards.
     */
    void moveDown();

    /**
     * @brief Move the humanoid freely in any direction.
     */
    void moveInFree();

    RandomGenerator _selector; /**< Random number generator for behavior selection. */
    Timer _timer; /**< Timer for controlling behavior changes. */
    bool _flag; /**< A flag used for controlling behavior changes. */
};

#endif // HUMANOID_H
