#include "GameObjectsContainer.h"

/**
 * @brief Set the list of game objects for the container.
 *
 * @param objectList The list of game objects to set.
 */
void GameObjectsContainer::setObjectList(GameObjectsList objectList)
{
    _objectsList = objectList;
}

/**
 * @brief Get the list of game objects in the container.
 *
 * @return The list of game objects.
 */
GameObjectsList GameObjectsContainer::getObjectList() const
{
    return _objectsList;
}

/**
 * @brief Remove dead (non-alive) game objects from the list.
 */
void GameObjectsContainer::removeDeadObjects()
{
    GameObjectsList tempList;
    for (GameObjectsListIter iter = begin(_objectsList); iter != end(_objectsList); iter++)
    {
        if ((*iter)->isAlive())
        {
            tempList.push_back((*iter));
        }
    }
    _objectsList.clear();
    _objectsList = tempList;
}

/**
 * @brief Remove all game objects from the container.
 */
void GameObjectsContainer::emptyList()
{
    _objectsList.clear();
}