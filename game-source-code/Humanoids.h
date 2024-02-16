/**
 * @file Humanoids.h
 * @brief This file contains the declaration of the Humanoids class for managing humanoids in the game.
 */
#ifndef HUMANOIDS_H
#define HUMANOIDS_H

#include "Humanoid.h"
#include "GameObjectsContainer.h"
#include "RandomGenerator.h"

/**
 * @class Humanoids
 * @brief A class for managing humanoids in the game.
 *
 * This class provides functionality for creating, adding, and updating humanoids within the game.
 * It also manages the positions of humanoids and ensures they do not overlap.
 */
class Humanoids : public GameObjectsContainer {
public:
    /**
     * @brief Add a new humanoid at the specified position.
     *
     * Adds a new humanoid at the specified position with optional target coordinates.
     *
     * @param x The x-coordinate of the humanoid's position.
     * @param y The y-coordinate of the humanoid's position.
     * @param xx The x-coordinate of the target position (optional).
     * @param yy The y-coordinate of the target position (optional).
     */
    virtual void add(double x, double y, double xx = 0, double yy = 0);

    /**
     * @brief Add a humanoid to the collection.
     *
     * Adds an existing GameObjectPtr representing a humanoid to the collection.
     *
     * @param humanoid A pointer to the humanoid GameObject.
     */
    virtual void add(GameObjectPtr);

    /**
     * @brief Update the state of humanoids.
     *
     * This function updates the state and positions of all humanoids in the collection.
     */
    virtual void update();

    /**
     * @brief Create and distribute humanoids across the game area.
     *
     * This function generates random positions for humanoids, ensuring they are not placed too close
     * to each other or outside the game area.
     */
    void createHumanoids();

private:
    /**
     * @brief Check if a position is valid for placing a humanoid.
     *
     * This function checks if the specified position is valid for placing a new humanoid. It ensures
     * that the position is within the game area and does not overlap with other humanoids.
     *
     * @param position The position to check.
     * @return True if the position is valid, false otherwise.
     */
    bool validPosition(int);

    /**
     * @brief Check if there is enough clearance at a position.
     *
     * This function checks if there is enough clearance at the specified position to place a new humanoid.
     * It helps ensure that humanoids are not placed too close to each other.
     *
     * @param position The position to check for clearance.
     * @return True if there is enough clearance, false otherwise.
     */
    bool checkClearance(int);

    RandomGenerator _randomGenerator; ///< A random number generator for generating positions.
    vector<int> _positions; ///< Positions of the humanoids.
};

#endif // HUMANOIDS_H
