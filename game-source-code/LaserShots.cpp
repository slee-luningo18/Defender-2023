#include "LaserShots.h"

// Constructor for the LaserShots class
LaserShots::LaserShots()
{
    _heading = Heading::LEFTHEADING;
}

// Adds a laser shot to the container
void LaserShots::add(double x, double y, double xx, double yy)
{
    double xPosition;
    double yPosition = y + 16;
    Direction dir;

    if (_heading == Heading::RIGHTHEADIND)
    {
        xPosition = x + 40;
        dir = Direction::RIGHT;
    }
    else
    {
        xPosition = x;
        dir = Direction::LEFT;
    }

    GameObjectPtr laserShot = std::make_shared<LaserShot>(xPosition, yPosition);
    if (static_cast<int>(_objectsList.size()) < 15)
    {
        laserShot->setDirection(dir);
        _objectsList.push_back(laserShot);
    }
}

// Updates the laser shots
void LaserShots::update()
{
    for (auto laserShot : _objectsList)
    {
        laserShot->Move();
    }
    removeDeadObjects();
}

// Sets the heading for the laser shots
void LaserShots::setHeading(Heading heading)
{
    _heading = heading;
}