#include "Player.h"
#include <iostream>

Player::Player(double x,double y):_player(x,y),_fuel(x,y)
{
    _fuel.refuel();
}
SpaceShip& Player::getSpaceShip()
{
    return _player;
}
Fuel& Player::getFuel()
{
    return _fuel;
}
LaserShots Player::getLaserShots()
{
    return _laserShots;
}
bool Player::isAlive()
{
    return (_player.isAlive());
}
void Player::shoot()
{
    if(!(_player.getState() == ObjectState::FAIL))
    {
        _laserShots.setHeading(_player.getHeading());
        _laserShots.add(_player.getXpos(),_player.getYpos());
    }
}
void Player::playerUpdate()
{
    if(_player.getState() == ObjectState::FAIL)
    {
        _player.Move();
    }
    if(!_fuel.isThereFuel())
        _player.setState(ObjectState::FAIL);
    if(_player.getYpos() >= 652 && _player.getState() == ObjectState::FAIL)
        _player.setState(ObjectState::DEAD);

    _laserShots.update();
    if(!(_player.getRescuee().getObjectList().empty()))
    {
        if(_player.getYpos() >= 616)
        {
            _player.getRescuee().getObjectList().back()->setStatus(Status::FREE);
            _player.getRescuee().getObjectList().back()->setPosition(_player.getXpos()+16,652);
            _player.getRescuee().emptyList();
        }
        else
        {
            if(_player.getRescuee().getObjectList().back()->getStatus() == Status::RESCUED)
            {
                _player.getRescuee().getObjectList().back()->setHeading(_player.getHeading());
                _player.getRescuee().getObjectList().back()->setPosition(_player.getXpos()+16,_player.getYpos()+32);
            }
        }
    }
}
void Player::handlePlayerInput(Button input)
{
    switch(input)
    {
    case Button::UP:
        _player.setDirection(UP);
        break;
    case Button::DOWN:
        _player.setDirection(DOWN);
        break;
    case Button::LEFT:
        _player.setHeading(Heading::LEFTHEADING);
        _player.setDirection(LEFT);
        break;
    case Button::RIGHT:
        _player.setHeading(Heading::RIGHTHEADIND);
        _player.setDirection(RIGHT);
        break;
    case Button::SPACE:
        if(!(_player.getState() == ObjectState::FAIL))
        {
            _laserShots.setHeading(_player.getHeading());
            _laserShots.add(_player.getXpos(),_player.getYpos());
        }
        break;
    default:
        ;
    }
}