/**
 * @file GameObjectsContainer.h
 * @brief Contains the definition of the GameObjectsContainer class and related types.
 */

#ifndef GAMEOBJECTSCONTAINER_H
#define GAMEOBJECTSCONTAINER_H

#include "GameObject.h"
#include "Utils.h"
#include <vector>
#include <memory>

/**
 * @typedef GameObjectsList
 * @brief Alias for a list of game objects.
 */
typedef std::vector<GameObjectPtr> GameObjectsList;

/**
 * @typedef GameObjectsListIter
 * @brief Alias for an iterator over a list of game objects.
 */
typedef std::vector<GameObjectPtr>::iterator GameObjectsListIter;

/**
 * @class GameObjectsContainer
 * @brief An abstract base class for managing and updating a collection of game objects.
 */
class GameObjectsContainer
{
public:
    /**
     * @brief Add a new game object to the container.
     *
     * @param x The x-coordinate of the object's position.
     * @param y The y-coordinate of the object's position.
     * @param xx The x-coordinate of the object's direction.
     * @param yy The y-coordinate of the object's direction.
     */
    virtual void add(double x, double y, double xx = 0, double yy = 0) = 0;

    /**
     * @brief Update all game objects in the container.
     */
    virtual void update() = 0;

    /**
     * @brief Set the list of game objects for the container.
     *
     * @param objectsList The list of game objects to set.
     */
    void setObjectList(GameObjectsList);

    /**
     * @brief Remove all game objects from the container.
     */
    void emptyList();

    /**
     * @brief Get the list of game objects in the container.
     *
     * @return The list of game objects.
     */
    GameObjectsList getObjectList() const;

protected:
    /**
     * @brief Remove dead (non-alive) game objects from the list.
     */
    void removeDeadObjects();

    /**
     * @brief The list of game objects in the container.
     */
    GameObjectsList _objectsList;
};
#endif
