#include "FuelTanks.h"

void FuelTanks::add(double x,double y,double xx,double yy)
{
    GameObjectPtr fuelTank = std::make_shared<GameObject>(x,y);
    if(static_cast<int>(_objectsList.size()) <= 2)
    {
        _objectsList.push_back(fuelTank);
        _timer.start();
    }
}
void FuelTanks::update()
{
    if(_timer.readTime()>= 5.0)
    {
        for(auto laserShot: _objectsList)
        {
            laserShot->setState(ObjectState::DEAD);
        }
    }
    removeDeadObjects();
}