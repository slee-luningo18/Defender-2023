#include "SpaceShip.h"

/**
 * @brief Constructor for the SpaceShip class.
 * @param x The initial X-coordinate of the spaceship.
 * @param y The initial Y-coordinate of the spaceship.
 */
SpaceShip::SpaceShip(double x, double y): GameObject(x, y)
{
    _heading = Heading::LEFTHEADING;
    setDirection(Direction::LEFT);
    _objectSpeed = _objectSpeed * 0.5;
}

/**
 * @brief Rescue a humanoid and associate it with the spaceship.
 * @param abductee A pointer to the humanoid object to be rescued.
 */
void SpaceShip::rescueHumanoid(GameObjectPtr abductee)
{
    _rescuee.add(abductee);
}

/**
 * @brief Get the rescued humanoid associated with the spaceship.
 * @return The rescued humanoid.
 */
Humanoids SpaceShip::getRescuee()
{
    return _rescuee;
}

bool SpaceShip::canRescuee()
{
    if(_rescuee.getObjectList().empty())
        return true;
    if(_rescuee.getObjectList().back()->getStatus() != Status::FREE)
        return true;
    else
        return false;
}
/**
 * @brief Move the spaceship down.
 */
void SpaceShip::moveDown()
{
    if (_yPosition < 652)
        _yPosition += _objectSpeed;
}

/**
 * @brief Move the spaceship up.
 */
void SpaceShip::moveUp()
{
    if (_yPosition > 96)
        _yPosition -= _objectSpeed;
}

/**
 * @brief Move the spaceship to the left.
 */
void SpaceShip::moveLeft()
{
    if (_xPosition > 0)
        _xPosition -= _objectSpeed;
}

/**
 * @brief Move the spaceship to the right.
 */
void SpaceShip::moveRight()
{
    if (_xPosition < 832)
        _xPosition += _objectSpeed;
}

/**
 * @brief Move the spaceship based on its current direction.
 */
void SpaceShip::Move()
{
    switch (getDirection())
    {
    case LEFT:
        moveLeft();
        break;
    case RIGHT:
        moveRight();
        break;
    case UP:
        moveUp();
        break;
    case DOWN:
        moveDown();
        break;
    default:;
    }
}

/**
 * @brief Set the heading of the spaceship.
 * @param heading The heading to set for the spaceship.
 */
void SpaceShip::setHeading(Heading heading)
{
    _heading = heading;
}

/**
 * @brief Get the current heading of the spaceship.
 * @return The heading of the spaceship.
 */
Heading SpaceShip::getHeading() const
{
    return _heading;
}