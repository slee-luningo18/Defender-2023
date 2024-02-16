#include "Humanoids.h"
#include <algorithm>
#include <iostream>

void Humanoids::add(double xPosition,double yPosition,double xx,double yy)
{
    // Create a new humanoid at the specified position.
    // Ensure that the number of humanoids does not exceed the maximum limit (5).
    GameObjectPtr humanoid = std::make_shared<Humanoid>(xPosition,yPosition);
    if(static_cast<int>(_objectsList.size()) < 5)
    {
        humanoid->setDirection(Direction::LEFT);
        _objectsList.push_back(humanoid);
    }
}
void Humanoids::add(GameObjectPtr humanoid)
{
   // Add an existing humanoid to the collection.
    _objectsList.push_back(humanoid);
}
void Humanoids::update()
{
// Update the state of all humanoids in the collection by calling their Move functions.
    for(auto humanoid: _objectsList)
    {
        humanoid->Move();
    }
    removeDeadObjects();
}
bool Humanoids::validPosition(int x)
{
    if(x % 32 == 0)
        return true;
    else
        return false;
}
bool Humanoids::checkClearance(int x)
{
    // Check if the given x-position has enough clearance from other positions.
    // We use std::none_of to check if there are no similar positions,
    // left-adjacent positions, or right-adjacent positions in the _positions vector.
    if(_positions.empty())
        return true;

    auto similarPosition = find(_positions.begin(),_positions.end(),x);
    auto leftAdjacentPosition = find(_positions.begin(),_positions.end(),x-32);
    auto rigthAdjacentPosition = find(_positions.begin(),_positions.end(),x+32);

    if(similarPosition == _positions.end() && leftAdjacentPosition == _positions.end() && rigthAdjacentPosition == _positions.end())
        return true;
    else
        return false;
}
void Humanoids::createHumanoids()
{
    auto x = 0;
    auto y = 652;
    for(int i = 0; i < 5; i++)
    {
        do
        {
            x = _randomGenerator.random_int(96,800);
        }
        while(!validPosition(x) && checkClearance(x));
        _positions.push_back(x);
        add(x,y);
    }
}