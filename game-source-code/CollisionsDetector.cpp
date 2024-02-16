#include "CollisionsDetector.h"

CollisionsDetector::CollisionsDetector()
{
    _isGameOver = false;
    _collisionFlag = false;
    _score = 0;
}
bool CollisionsDetector::hasCollided(GameObjectPtr firstObject,GameObjectPtr secondObject,double w1,double h1,double w2,double h2)
{
    auto x1 = firstObject->getXpos();
    auto y1 = firstObject->getYpos();
    auto x2 = secondObject->getXpos();
    auto y2 = secondObject->getYpos();
    if(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1)
        return false;
    else
        return true;
}
bool CollisionsDetector::hasCollided(SpaceShip& firstObject,GameObjectPtr secondObject,double w1,double h1,double w2,double h2)
{
    auto x1 = firstObject.getXpos();
    auto y1 = firstObject.getYpos();
    auto x2 = secondObject->getXpos();
    auto y2 = secondObject->getYpos();
    if(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1)
        return false;
    else
        return true;
}
bool CollisionsDetector::hasCollided(SpaceShip& spaceShip,Lander& lander,double w1,double h1,double w2,double h2)
{
    auto x1 = spaceShip.getXpos();
    auto y1 = spaceShip.getYpos();
    auto x2 = lander.getXpos();
    auto y2 = lander.getYpos();
    if(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1)
        return false;
    else
        return true;
}
bool CollisionsDetector::hasCollided(GameObjectPtr firstObject,Lander& lander,double w1,double h1,double w2,double h2)
{
    auto x1 = firstObject->getXpos();
    auto y1 = firstObject->getYpos();
    auto x2 = lander.getXpos();
    auto y2 = lander.getYpos();
    if(x1 + w1 <= x2 || x2 + w2 <= x1 || y1 + h1 <= y2 || y2 + h2 <= y1)
        return false;
    else
        return true;
}
int CollisionsDetector::getScore()const
{
    return _score;
}
bool CollisionsDetector::getCollisionFlag()const
{
    return _collisionFlag;
}
void CollisionsDetector::resetCollisionFlag()
{
    _collisionFlag = false;
}
void CollisionsDetector::increamentScore(Objective objective)
{
    switch(objective)
    {
    case Objective::ATTACK:
        _score += 15;
        break;
    case Objective::ABDUCT:
        _score += 20;
        break;
    case Objective::ESCAPE:
        _score += 30;
        break;
    default:
        ;
    }
}
void CollisionsDetector::checkLasersAndMissiles(GameObjectsList firstList,GameObjectsList secondList)
{
    double w1 = 16;
    double h1 = 16;
    double w2 = 8;
    double h2 = 8;
    for(GameObjectsListIter firstIter = begin(firstList); firstIter != end(firstList); firstIter++)
    {
        for(GameObjectsListIter secondIter = begin(secondList); secondIter != end(secondList); secondIter++)
        {
            if(hasCollided((*firstIter),(*secondIter),w1,h1,w2,h2))
            {
                (*firstIter)->setState(ObjectState::DEAD);
                (*secondIter)->setState(ObjectState::DEAD);
                _score += 5;
            }
        }
    }
}
void CollisionsDetector::checkLasersAndHumanoids(GameObjectsList firstList,GameObjectsList secondList)
{
    double w1 = 16;
    double h1 = 16;
    double w2 = 8;
    double h2 = 8;
    for(GameObjectsListIter firstIter = begin(firstList); firstIter != end(firstList); firstIter++)
    {
        for(GameObjectsListIter secondIter = begin(secondList); secondIter != end(secondList); secondIter++)
        {
            if(hasCollided((*firstIter),(*secondIter),w1,h1,w2,h2) && (*firstIter)->getStatus() == Status::ABDUCTED)
            {
                (*firstIter)->setState(ObjectState::DEAD);
                (*secondIter)->setState(ObjectState::DEAD);
            }
        }
    }
}
void CollisionsDetector::checkSpaceshipAndHumanoids(SpaceShip& spaceShip,GameObjectsList List)
{
    double w1 = 48;
    double h1 = 32;
    double w2 = 16;
    double h2 = 32;
    for(auto iter = begin(List); iter != end(List); iter++)
    {
        if(hasCollided(spaceShip,(*iter),w1,h1,w2,h2))
        {
            if((*iter)->getStatus() == Status::FALLING && spaceShip.canRescuee())
            {
                spaceShip.rescueHumanoid((*iter));
                (*iter)->setStatus(Status::RESCUED);
                (*iter)->setPosition(spaceShip.getXpos()+16,spaceShip.getYpos()+32);
            }
        }
    }
}
void CollisionsDetector::checkSpaceshipAndLander(SpaceShip& spaceShip,Lander& lander)
{
    double w1 = 48;
    double h1 = 32;
    double w2 = 16;
    double h2 = 16;
    if(hasCollided(spaceShip,lander,w1,h1,w2,h2))
    {
        spaceShip.setState(ObjectState::DEAD);
        lander.setState(ObjectState::DEAD);
    }
}
void CollisionsDetector::checkSpaceshipAndFuelTank(Player& player,GameObjectPtr object)
{
    double w1 = 48;
    double h1 = 32;
    double w2 = 16;
    double h2 = 16;
    if(hasCollided(player.getSpaceShip(),object,w1,h1,w2,h2))
    {
        player.getFuel().refuel();
        object->setState(ObjectState::DEAD);
    }
}
void CollisionsDetector::checkSpaceShipAndMissiles(SpaceShip& spaceShip,GameObjectsList List)
{
    double w1 = 48;
    double h1 = 32;
    double w2 = 8;
    double h2 = 8;
    for(auto iter = begin(List); iter != end(List); iter++)
    {
        if(hasCollided(spaceShip,(*iter),w1,h1,w2,h2))
        {
            spaceShip.setState(ObjectState::DEAD);
            (*iter)->setState(ObjectState::DEAD);
        }
    }
}
void CollisionsDetector::checkLanderAndHumanoids(Lander& lander,GameObjectsList secondList)
{
    double w1 = 16;
    double h1 = 16;
    double w2 = 16;
    double h2 = 32;
    for(GameObjectsListIter secondIter = begin(secondList); secondIter != end(secondList); secondIter++)
    {
        if(hasCollided((*secondIter),lander,w2,h2,w1,h1))
        {
            if((*secondIter)->getStatus() == Status::FREE && lander.getAbductee().getObjectList().empty() && lander.getObjective() == Objective::ABDUCT)
            {
                lander.setObjective(Objective::ESCAPE);
                lander.setPosition(lander.getXpos(),lander.getYpos()-16);
                (*secondIter)->setStatus(Status::ABDUCTED);
                (*secondIter)->setPosition(lander.getXpos(),lander.getYpos()+16);
                lander.abductHumanoid((*secondIter));
                _collisionFlag = true;
            }
        }
    }
}
void CollisionsDetector::checkLandersAndHumanoids(EnemyList enemies,GameObjectsList List)
{
    for(auto iter = begin(enemies); iter != end(enemies); iter++)
    {
        checkLanderAndHumanoids((*iter)->getLander(),List);
    }
}
void CollisionsDetector::checkLaserAndLander(GameObjectsList firstList,Lander& lander)
{
    double w1 = 16;
    double h1 = 8;
    double w2 = 16;
    double h2 = 16;
    for(GameObjectsListIter firstIter = begin(firstList); firstIter != end(firstList); firstIter++)
    {
        if(hasCollided((*firstIter),lander,w1,h1,w2,h2))
        {
            (*firstIter)->setState(ObjectState::DEAD);
            lander.setState(ObjectState::DEAD);
            increamentScore(lander.getObjective());
        }
    }
}
void CollisionsDetector::checkSpaceshipAndFuelTanks(Player& player,GameObjectsList tanks)
{
    for(auto iter = begin(tanks); iter != end(tanks); iter++)
    {
        checkSpaceshipAndFuelTank(player,(*iter));

    }
}
void CollisionsDetector::checkSpaceshipAndEnemies(Player& player,EnemyList enemies)
{
    for(auto iter = begin(enemies); iter != end(enemies); iter++)
    {
        checkLasersAndMissiles(player.getLaserShots().getObjectList(),(*iter)->getMissiles().getObjectList());
        checkSpaceshipAndLander(player.getSpaceShip(),(*iter)->getLander());
        checkSpaceShipAndMissiles(player.getSpaceShip(),(*iter)->getMissiles().getObjectList());
        checkLaserAndLander(player.getLaserShots().getObjectList(),(*iter)->getLander());
    }
}

void CollisionsDetector::checkCollisions(Player& player,GameObjectsList humanoids,EnemyList enemies,GameObjectsList tanks)
{
    checkSpaceshipAndEnemies(player,enemies);
    checkSpaceshipAndHumanoids(player.getSpaceShip(),humanoids);
    checkLandersAndHumanoids(enemies,humanoids);
    checkLasersAndHumanoids(humanoids,player.getLaserShots().getObjectList());
    checkSpaceshipAndFuelTanks(player,tanks);
}