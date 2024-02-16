/**
 * @file CollisionsDetector.h
 * @brief This file contains the declaration of the CollisionsDetector class for handling collision detection in the game.
 */
#ifndef COLLISIONSDETECTOR_H
#define COLLISIONSDETECTOR_H
#include "Player.h"
#include "Missiles.h"
#include "EnemyContainer.h"
#include "LaserShots.h"
#include "Humanoids.h"

/**
 * @class CollisionsDetector
 * @brief A class for handling collision detection in the game.
 */
class CollisionsDetector
{
public:
    CollisionsDetector();
    void checkCollisions(Player&,GameObjectsList,EnemyList,GameObjectsList);
    void resetCollisionFlag();
    bool getCollisionFlag()const;
    int getScore()const;
private:
    void checkLasersAndMissiles(GameObjectsList,GameObjectsList);
    void checkLasersAndHumanoids(GameObjectsList,GameObjectsList);
    void checkSpaceshipAndHumanoids(SpaceShip&,GameObjectsList);
    void checkSpaceshipAndLander(SpaceShip&,Lander&);
    void checkSpaceshipAndFuelTank(Player&,GameObjectPtr);
    void checkSpaceShipAndMissiles(SpaceShip&,GameObjectsList);
    void checkLaserAndLander(GameObjectsList,Lander&);
    void checkLanderAndHumanoids(Lander&,GameObjectsList);
    void checkLandersAndHumanoids(EnemyList,GameObjectsList);
    void checkSpaceshipAndEnemies(Player&,EnemyList);
    void checkSpaceshipAndFuelTanks(Player&,GameObjectsList);
    bool hasCollided(GameObjectPtr,GameObjectPtr,double,double,double,double);
    bool hasCollided(SpaceShip&,GameObjectPtr,double,double,double,double);
    bool hasCollided(SpaceShip&,Lander&,double,double,double,double);
    bool hasCollided(GameObjectPtr,Lander&,double,double,double,double);
    void increamentScore(Objective);
    bool _isGameOver;
    bool _collisionFlag;
    int _score;
};
#endif // COLLISIONSDETECTOR_H