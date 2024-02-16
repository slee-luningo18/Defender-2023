#include "Missiles.h"

// Adds a new missile to the container
void Missiles::add(double xPosition, double yPosition, double xTarget, double yTarget)
{
    GameObjectPtr missile = std::make_shared<Missile>(xPosition, yPosition, xTarget, yTarget);

    // Ensure the maximum number of missiles is not exceeded (e.g., 3)
    if (static_cast<int>(_objectsList.size()) < 3)
    {
        _objectsList.push_back(missile);
    }
}

// Updates the state of missiles in the container
void Missiles::update()
{
    for (auto missile : _objectsList)
    {
        missile->Move();
    }
    removeDeadObjects();
}