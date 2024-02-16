/**
 * @file Missiles.h
 * @brief Defines the Missiles class for managing missiles in the game.
 */

#ifndef MISSILES_H
#define MISSILES_H

#include "GameObjectsContainer.h"
#include "Missile.h"

/**
 * @class Missiles
 * @brief Represents a container for managing missiles in the game.
 *
 * This class extends the GameObjectsContainer class and is responsible for managing
 * missiles within the game.
 */
class Missiles : public GameObjectsContainer
{
public:
    /**
     * @brief Adds a new missile to the container.
     * @param x The x-coordinate of the missile's position.
     * @param y The y-coordinate of the missile's position.
     * @param xx The x-component of the missile's velocity (default is 0).
     * @param yy The y-component of the missile's velocity (default is 0).
     */
    virtual void add(double x, double y, double xx = 0, double yy = 0);

    /**
     * @brief Updates the state of missiles in the container.
     */
    virtual void update();
};

#endif // MISSILES_H