/**
 * @file Fuel.h
 * @brief This file contains the declaration of the Fuel class for managing the fuel of game objects.
 */
#ifndef FUEL_H
#define FUEL_H
#include "GameObject.h"
#include "RandomGenerator.h"
#include "Timer.h"

/**
 * @class Fuel
 * @brief A class for managing the fuel of game objects.
 */
class Fuel:public GameObject
{
public:
    Fuel(double,double);
    virtual void Move();
    void refuel();
    double getRemainingFuel();
    bool isThereFuel();
private:
    double _fuel;
    Timer _timer;
};
#endif // FUEL_H