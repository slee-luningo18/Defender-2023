/**
 * @file SpaceShip.h
 * @brief Header file for the SpaceShip class.
 */

#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "Utils.h"
#include "GameObject.h"
#include "Humanoids.h"

/**
 * @class SpaceShip
 * @brief A class representing a spaceship in the game.
 */
class SpaceShip : public GameObject
{
public:
    /**
     * @brief Constructor for the SpaceShip class.
     * @param x The initial X-coordinate of the spaceship.
     * @param y The initial Y-coordinate of the spaceship.
     */
    SpaceShip(double, double);

    /**
     * @brief Set the heading of the spaceship.
     * @param heading The heading to set for the spaceship.
     */
    void setHeading(Heading);

    /**
     * @brief Get the current heading of the spaceship.
     * @return The heading of the spaceship.
     */
    Heading getHeading() const;

    /**
     * @brief Rescue a humanoid and associate it with the spaceship.
     * @param ptr A pointer to the humanoid object to be rescued.
     */
    void rescueHumanoid(GameObjectPtr);

    /**
     * @brief Get the rescued humanoid associated with the spaceship.
     * @return The rescued humanoid.
     */
    Humanoids getRescuee();

    bool canRescuee();

    /**
     * @brief Move the spaceship.
     */
    virtual void Move();

private:
    /**
     * @brief Move the spaceship to the left.
     */
    void moveLeft();

    /**
     * @brief Move the spaceship to the right.
     */
    void moveRight();

    /**
     * @brief Move the spaceship up.
     */
    void moveUp();

    /**
     * @brief Move the spaceship down.
     */
    void moveDown();

    Heading _heading; ///< The current heading of the spaceship.
    Humanoids _rescuee; ///< The rescued humanoid associated with the spaceship.
};

#endif // SPACESHIP_H
