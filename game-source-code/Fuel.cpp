#include "Fuel.h"

Fuel::Fuel(double x,double y):GameObject(x,y)
{
    _fuel = 20;
    _timer.start();
}
void Fuel::Move(){/*The fuel does not move*/}
void Fuel::refuel()
{
    _fuel = 20;
    _timer.start();
}
double Fuel::getRemainingFuel()
{
    return (_fuel-_timer.readTime());
}
bool Fuel::isThereFuel()
{
    return (getRemainingFuel() > 0);
}