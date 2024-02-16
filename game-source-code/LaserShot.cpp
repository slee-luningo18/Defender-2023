#include "LaserShot.h"

// Constructor for the LaserShot class
LaserShot::LaserShot(double x,double y):GameObject(x,y)
{
}

// Moves the laser shot to the left
void LaserShot::moveLeft()
{
    if(_xPosition > 0)
        _xPosition -= _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

// Moves the laser shot to the right
void LaserShot::moveRight()
{
     if(_xPosition < 880)
        _xPosition += _objectSpeed;
     else
        setState(ObjectState::DEAD);
}

// Moves the laser shot based on its direction
void LaserShot::Move()
{
    switch(getDirection())
    {
    case Direction::LEFT:
        moveLeft();
        break;
    case Direction::RIGHT:
        moveRight();
        break;
    default:;
    }
}