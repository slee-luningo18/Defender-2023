#include "GameBase.h"
#include <iostream>
GameBase::GameBase():_player(416,384)
{
    _humanoidTarget = 0;
    _timer.start();
    _humanoids.createHumanoids();
}
Player GameBase::getPlayer()
{
    return _player;
}
EnemyContainer GameBase::getEnemies()
{
    return _enemies;
}
Humanoids GameBase::getHumanoids()
{
    return _humanoids;
}
FuelTanks GameBase::getFuelTanks()
{
    return _fuelTank;
}
void GameBase::moveRight()
{
    if(_player.getSpaceShip().getState() != ObjectState::FAIL)
    {
        _player.getSpaceShip().setHeading(Heading::RIGHTHEADIND);
        _player.getSpaceShip().setDirection(Direction::RIGHT);
        _player.getSpaceShip().Move();
        _player.getSpaceShip().setDirection(Direction::NONE);
    }
}
void GameBase::moveLeft()
{
    if(_player.getSpaceShip().getState() != ObjectState::FAIL)
    {
        _player.getSpaceShip().setHeading(Heading::LEFTHEADING);
        _player.getSpaceShip().setDirection(Direction::LEFT);
        _player.getSpaceShip().Move();
        _player.getSpaceShip().setDirection(Direction::NONE);
    }
}
void GameBase::moveUp()
{
    if(_player.getSpaceShip().getState() != ObjectState::FAIL)
    {
        _player.getSpaceShip().setDirection(Direction::UP);
        _player.getSpaceShip().Move();
        _player.getSpaceShip().setDirection(Direction::NONE);
    }
}
void GameBase::moveDown()
{
    if(_player.getSpaceShip().getState() != ObjectState::FAIL)
    {
        _player.getSpaceShip().setDirection(Direction::DOWN);
        _player.getSpaceShip().Move();
        _player.getSpaceShip().setDirection(Direction::NONE);
    }
}
void GameBase::shoot()
{
    _player.shoot();
}
int GameBase::getScore()const
{
    return _collisionsDetector.getScore();
}
void GameBase::chooseHumanoidTarget()
{
    if(!(_humanoids.getObjectList().empty()))
    {
        int choice;
        RandomGenerator _selector;
        do
        {
            choice = _selector.random_int(0,static_cast<int>((_humanoids.getObjectList().size())-1));
        }
        while((_humanoids.getObjectList().at(choice))->getStatus() == Status::FREE);
        _humanoidTarget = choice;
    }
}
void GameBase::introduceFuel()
{
    if(_timer.readTime() >= 6.0)
    {
        auto x = 0;
        RandomGenerator choice;
        do
        {
            x = choice.random_int(128,800);
        }
        while(!(x % 4 == 0));
        _fuelTank.add(x,668);
        _timer.start();
    }
}
bool GameBase::isGameOver()
{
    if(!(_player.isAlive()) || ( _enemies.getEnemyCount() == 8 && _enemies.getEnemyList().empty())|| _humanoids.getObjectList().empty())
        return true;
    else
        return false;
}
bool GameBase::hasWon()
{
    if(_player.isAlive() && _enemies.getEnemyCount() && _enemies.getEnemyList().empty())
        return true;
    else
        return false;
}
void GameBase::gameUpdate()
{

    _player.playerUpdate();
    _enemies.observeTarget(_player.getSpaceShip().getXpos(),_player.getSpaceShip().getYpos());
    if(!(_humanoids.getObjectList().empty()))
    {
        if(_humanoidTarget <= static_cast<int>((_humanoids.getObjectList().size())-1))
        {
            auto x = ((_humanoids.getObjectList()).at(_humanoidTarget))->getXpos();
            auto y = ((_humanoids.getObjectList()).at(_humanoidTarget))->getYpos();
            _enemies.observePotentialAbductee(x,y);
        }
    }
    _enemies.update();
    _humanoids.update();
    _fuelTank.update();
    _collisionsDetector.checkCollisions(_player,_humanoids.getObjectList(),_enemies.getEnemyList(),_fuelTank.getObjectList());
    _enemies.introduceEnemy();
    introduceFuel();
    if(_collisionsDetector.getCollisionFlag())
    {
        chooseHumanoidTarget();
        _collisionsDetector.resetCollisionFlag();
    }
}