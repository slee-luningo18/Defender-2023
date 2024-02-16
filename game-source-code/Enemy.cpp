#include "Enemy.h"

Enemy::Enemy(double x,double y):_lander(x,y)
{

}
Lander& Enemy::getLander()
{
    return _lander;
}
Missiles Enemy::getMissiles()
{
    return _missiles;
}
bool Enemy::isAlive()const
{
    return _lander.isAlive();
}
void Enemy::setEnemyTarget(double x,double y)
{
    _lander.setTarget(x,y);
}
void Enemy::observeTarget(double x,double y)
{
    _lander.observe(x,y);
}
void Enemy::changeStrategy(Objective objective)
{
    _lander.setObjective(objective);
}
void Enemy::shootTarget(double x,double y)
{
    _missiles.add(_lander.getXpos(),_lander.getYpos(),x,y);
}
void Enemy::updateEnemy()
{
    _lander.Move();
    if(_lander.getYpos() == 92 && _lander.getObjective() == Objective::ESCAPE && !(_lander.getAbductee().getObjectList().empty()))
    {
        _lander.getAbductee().getObjectList().at(0)->setState(ObjectState::DEAD);
    }
    _missiles.update();
    if(!isAlive() && !(_lander.getAbductee().getObjectList().empty()))
       _lander.getAbductee().getObjectList().at(0)->setStatus(Status::FALLING);
}