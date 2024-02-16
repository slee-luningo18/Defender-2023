/**
 * @file FuelTanks.h
 * @brief This file contains the declaration of the FuelTanks class for managing fuel tanks in the game.
 */
#ifndef FUELTANKS_H
#define FUELTANKS_H
#include "GameObjectsContainer.h"
#include "Timer.h"

/**
 * @class FuelTanks
 * @brief A class for managing fuel tanks in the game.
 */
class FuelTanks:public GameObjectsContainer
{
public:
    virtual void add(double x,double y,double xx = 0, double yy = 0);
    virtual void update();
private:
    Timer _timer;
};
#endif // FUELTANK_H