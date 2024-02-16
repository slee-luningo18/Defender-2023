#include "Missile.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

// Constructor for the Missile class
Missile::Missile(double x, double y, double xTarget, double yTarget) : GameObject(x, y)
{
    _xTarget = xTarget;
    _yTarget = yTarget;
    _gradient = 0;
    _yIntercept = 0;
    _objectSpeed = _objectSpeed * 0.5;
    double angle = atan2(_yTarget - _yPosition, _xTarget - _xPosition);
    double angle_degrees = angle * 180 / M_PI;

    if (angle_degrees < 0)
        angle_degrees += 360;

    int direction_index = static_cast<int>((angle_degrees + 22.5) / 45) % 8;
    Direction direction = static_cast<Direction>(direction_index);

    if (direction_index == 1 || direction_index == 3 || direction_index == 5 || direction_index == 7)
    {
        _gradient = (_yTarget - _yPosition) / (_xTarget - _xPosition);
        _yIntercept = _yTarget - _gradient * _xTarget;
    }
    setDirection(direction);
}

// Moves the missile to the left
void Missile::moveLeft()
{
    if (_xPosition > 0)
        _xPosition -= _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

// Moves the missile to the right
void Missile::moveRight()
{
    if (_xPosition < 880)
        _xPosition += _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

// Moves the missile downwards
void Missile::moveDown()
{
    if (_yPosition < 668)
        _yPosition += _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

// Moves the missile upwards
void Missile::moveUp()
{
    if (_yPosition > 124)
        _yPosition -= _objectSpeed;
    else
        setState(ObjectState::DEAD);
}

// Moves the missile to the left and upwards
void Missile::moveLeftUp()
{
    if (_xPosition > 0)
    {
        _xPosition -= _objectSpeed;
        int yPosition = _gradient * _xPosition + _yIntercept;

        if (yPosition > 124)
            _yPosition = yPosition;
        else
        {
            _xPosition += _objectSpeed;
            setState(ObjectState::DEAD);
        }
    }
    else
        setState(ObjectState::DEAD);
}

// Moves the missile to the left and downwards
void Missile::moveLeftDown()
{
    if (_xPosition > 0)
    {
        _xPosition -= _objectSpeed;
        int yPosition = _gradient * _xPosition + _yIntercept;

        if (yPosition < 668)
            _yPosition = yPosition;
        else
        {
            _xPosition += _objectSpeed;
            setState(ObjectState::DEAD);
        }
    }
    else
        setState(ObjectState::DEAD);
}

// Moves the missile to the right and upwards
void Missile::moveRightUp()
{
    if (_xPosition < 880)
    {
        _xPosition += _objectSpeed;
        int yPosition = _gradient * _xPosition + _yIntercept;

        if (yPosition > 124)
            _yPosition = yPosition;
        else
        {
            _xPosition -= _objectSpeed;
            setState(ObjectState::DEAD);
        }
    }
    else
        setState(ObjectState::DEAD);
}

// Moves the missile to the right and downwards
void Missile::moveRightDown()
{
    if (_xPosition < 880)
    {
        _xPosition += _objectSpeed;
        int yPosition = _gradient * _xPosition + _yIntercept;

        if (yPosition < 668)
            _yPosition = yPosition;
        else
        {
            _xPosition -= _objectSpeed;
            setState(ObjectState::DEAD);
        }
    }
    else
        setState(ObjectState::DEAD);
}

// Moves the missile according to its direction
void Missile::Move()
{
    switch (getDirection())
    {
    case Direction::DOWN:
        moveDown();
        break;
    case Direction::LEFT:
        moveLeft();
        break;
    case Direction::LEFTDOWN:
        moveLeftDown();
        break;
    case Direction::LEFTUP:
        moveLeftUp();
        break;
    case Direction::UP:
        moveUp();
        break;
    case Direction::RIGHT:
        moveRight();
        break;
    case Direction::RIGHTDOWN:
        moveRightDown();
        break;
    case Direction::RIGHTUP:
        moveRightUp();
        break;
    default:;
    }
}