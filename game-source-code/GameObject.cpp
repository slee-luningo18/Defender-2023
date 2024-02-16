#include "GameObject.h"
#include "stdexcept"

GameObject::GameObject(double x,double y)
{
    // Define the bounds of the play screen.
    auto lowerBound = 0.0, upperHorizontalBound = 896.0, upperVerticalBound = 700.0;

    // Check if the initial position is within the play screen bounds.
    if(x < lowerBound || x > upperHorizontalBound || y < lowerBound || y > upperVerticalBound)
        throw std::logic_error("Game objects position is outside play screen bounds");

    // Initialize the object's attributes.
    _xPosition = x;
    _yPosition = y;
    _objectSpeed = 16;
    _objectState = ALIVE;
    _objectDirection = NONE;
    _heading = Heading::LEFTHEADING;
    _status = Status::NOSTATUS;
    _objective = Objective::NOOBJECTIVE;
}

/**
 * @brief Set the objective of the GameObject.
 *
 * @param objective The objective to set for the GameObject.
 */
void GameObject::setObjective(Objective objective)
{
    _objective = objective;
}

/**
 * @brief Get the objective of the GameObject.
 *
 * @return The current objective of the GameObject.
 */
Objective GameObject::getObjective()const
{
    return _objective;
}


/**
 * @brief Set the status of the GameObject.
 *
 * @param objectState The status to set for the GameObject.
 */
void GameObject::setStatus(Status objectstate)
{
    _status = objectstate;
}

/**
 * @brief Get the status of the GameObject.
 *
 * @return The current status of the GameObject.
 */
Status GameObject::getStatus()const
{
    return _status;
}

/**
 * @brief Check if the GameObject is alive.
 *
 * @return True if the GameObject is alive, false otherwise.
 */
bool GameObject::isAlive()const
{
    return _objectState == ALIVE;
}

/**
 * @brief Get the X position of the GameObject.
 *
 * @return The X position of the GameObject.
 */
double GameObject::getXpos()const
{
    return _xPosition;
}


/**
 * @brief Get the Y position of the GameObject.
 *
 * @return The Y position of the GameObject.
 */
double GameObject::getYpos()const
{
    return _yPosition;
}

/**
 * @brief Set the state of the GameObject.
 *
 * @param state The state to set for the GameObject.
 */
void GameObject::setState(ObjectState state)
{
    _objectState = state;
}


/**
 * @brief Get the state of the GameObject.
 *
 * @return The current state of the GameObject.
 */
ObjectState GameObject::getState()const
{
    return _objectState;
}

/**
 * @brief Set the direction of the GameObject.
 *
 * @param dir The direction to set for the GameObject.
 */
void GameObject::setDirection(Direction dir)
{
    _objectDirection = dir;
}

/**
 * @brief Get the direction of the GameObject.
 *
 * @return The current direction of the GameObject.
 */
Direction GameObject::getDirection()const
{
    return _objectDirection;
}

/**
 * @brief Get the heading of the GameObject.
 *
 * @return The current heading of the GameObject.
 */
void GameObject::setHeading(Heading heading)
{
    _heading = heading;
}
Heading GameObject::getHeading()const
{
    return _heading;
}
void GameObject::setPosition(double x,double y)
{
    _xPosition = x;
    _yPosition = y;
}
/**
 * @brief Move function for the GameObject.
 *
 * This virtual function will be implemented differently for derived objects.
 */
void GameObject::Move()
{
   // This virtual function will be implemented differently for derived objects.
}
