#include "Lander.h"
#include <cmath>
#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

Lander::Lander(double x,double y):GameObject(x,y)
{
    _xTarget = 0;
    _yTarget = 0;
    _gradient = 0;
    _yIntercept = 0;
    _objectSpeed = _objectSpeed*0.125;
    setObjective(Objective::ATTACK);
}
void Lander::abductHumanoid(GameObjectPtr abductee)
{
    _abductee.add(abductee);
}
Humanoids Lander::getAbductee()
{
    return _abductee;
}
void Lander::Move()
{
    switch(getObjective())
    {
    case Objective::ABDUCT:
        moveInAbduct();
        break;
    case Objective::ATTACK:
        moveInAttack();
        break;
    case Objective::ESCAPE:
        moveInEscape();
        break;
    default:
        ;
    }
}
void Lander::observe(double x,double y)
{
    _xTarget = x;
    _yTarget = y;
}
void Lander::moveInEscape()
{
    moveUp();
}
void Lander::moveInAttack()
{
    moveInAbduct();
}
void Lander::moveInAbduct()
{
    switch(getDirection())
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
    default:
        ;
    }
}
void Lander::setTarget(double x,double y)
{
    _xTarget = x;
    _yTarget = y;

    double angle = atan2(_yTarget-_yPosition,_xTarget-_xPosition);
    double angle_degrees = angle*180/M_PI;

    if(angle_degrees <0)
        angle_degrees += 360;

    int direction_index = static_cast<int>((angle_degrees+22.5)/45)%8;
    Direction direction = static_cast<Direction>(direction_index);

    if(direction_index == 1 || direction_index == 3 || direction_index == 5 || direction_index == 7)
    {
        _gradient = (_yTarget-_yPosition)/(_xTarget-_xPosition);
        _yIntercept = (_yTarget-_gradient*_xTarget);
    }
    setDirection(direction);
}

//Moves Lander left
void Lander::moveLeft()
{
    if(_xPosition > 0)
        _xPosition -= _objectSpeed;
}

//Moves Lander right
void Lander::moveRight()
{
    if(_xPosition < 880)
        _xPosition += _objectSpeed;
}

//Moves Lander down
void Lander::moveDown()
{
    if(_yPosition < 680)
        _yPosition += _objectSpeed;
}

//Moves Lander up
void Lander::moveUp()
{
    if(_yPosition > 92)
        _yPosition -= _objectSpeed;
    else
    {
        if(getObjective() == Objective::ESCAPE)
        {
            setState(ObjectState::DEAD);
        }
    }
}

//Moves Lander leftUp
void Lander::moveLeftUp()
{
    if(_xPosition > 0)
    {
        _xPosition -= _objectSpeed;
        double yPosition = round((_gradient*_xPosition+_yIntercept)/_objectSpeed)*_objectSpeed;

        if(yPosition > 92)
            _yPosition = yPosition;
        else
        {
            _xPosition += _objectSpeed;
        }
    }
}

//Moves Lander leftDown
void Lander::moveLeftDown()
{
    if(_xPosition > 0)
    {
        _xPosition -= _objectSpeed;
        double yPosition = round((_gradient*_xPosition+_yIntercept)/_objectSpeed)*_objectSpeed;

        if(yPosition < 680)
            _yPosition = yPosition;
        else
        {
            _xPosition += _objectSpeed;
        }
    }
}

//Moves Lander rightUp
void Lander::moveRightUp()
{
    if(_xPosition < 880)
    {
        _xPosition += _objectSpeed;
        double yPosition = round((_gradient*_xPosition+_yIntercept)/_objectSpeed)*_objectSpeed;

        if(yPosition > 92)
            _yPosition = yPosition;
        else
        {
            _xPosition -= _objectSpeed;
        }
    }
}

//Moves Lander rightDown
void Lander::moveRightDown()
{
    if(_xPosition < 880)
    {
        _xPosition += _objectSpeed;
        double yPosition = round((_gradient*_xPosition+_yIntercept)/_objectSpeed)*_objectSpeed;

        if(yPosition < 680)
            _yPosition = yPosition;
        else
        {
            _xPosition -= _objectSpeed;
        }
    }
}