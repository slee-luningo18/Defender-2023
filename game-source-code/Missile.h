/**
 * @file Missile.h
 * @brief Defines the Missile class for controlling missile game objects.
 */

#ifndef MISSILE_H
#define MISSILE_H

#include "Utils.h"
#include "GameObject.h"

/**
 * @class Missile
 * @brief Represents a missile game object with movement capabilities.
 *
 * This class extends the GameObject class and provides functionality for
 * controlling the movement of a missile within the game.
 */
class Missile : public GameObject
{
public:
    /**
     * @brief Constructor for the Missile class.
     * @param x The initial x-coordinate of the missile.
     * @param y The initial y-coordinate of the missile.
     * @param xTarget The x-coordinate of the missile's target.
     * @param yTarget The y-coordinate of the missile's target.
     */
    Missile(double, double, double, double);

    /**
     * @brief Moves the missile to its target position.
     */
    virtual void Move();

private:
    /**
     * @brief Moves the missile to the left.
     */
    void moveLeft();

    /**
     * @brief Moves the missile to the right.
     */
    void moveRight();

    /**
     * @brief Moves the missile downwards.
     */
    void moveDown();

    /**
     * @brief Moves the missile upwards.
     */
    void moveUp();

    /**
     * @brief Moves the missile to the left and upwards.
     */
    void moveLeftUp();

    /**
     * @brief Moves the missile to the left and downwards.
     */
    void moveLeftDown();

    /**
     * @brief Moves the missile to the right and upwards.
     */
    void moveRightUp();

    /**
     * @brief Moves the missile to the right and downwards.
     */
    void moveRightDown();

    double _xTarget;     /**< The x-coordinate of the missile's target. */
    double _yTarget;     /**< The y-coordinate of the missile's target. */
    double _gradient;    /**< The gradient of the missile's path. */
    double _yIntercept;  /**< The y-intercept of the missile's path. */
};

#endif // MISSILE_H
