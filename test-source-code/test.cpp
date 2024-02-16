#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

//the game play screen is 896x688
const double screenLowerBound = 0;
const double screenUpperHorizontalBound = 896;
const double screenUpperVerticalBound = 688;

const double speed = 16; //speed of spaceship
const double x = 416; //initial horizontal position of spaceship
const double y = 384; //initial vertical position of spaceship
#include "GameObject.h"
#include "Lander.h"
#include "SpaceShip.h"
#include "LaserShot.h"
#include "LaserShots.h"
#include "Enemy.h"
#include "Humanoid.h"
#include "Humanoids.h"
#include "Missile.h"
#include "Fuel.h"
//Game objects tests
TEST_CASE("Game object cannot be created outside the boundaries of the play screen")
{
    CHECK_THROWS(GameObject(screenLowerBound-3,screenUpperHorizontalBound+3));
}
TEST_CASE("A logical error is thrown if a created game object is outside the boundaries of play screen")
{
    CHECK_THROWS_AS(GameObject(screenLowerBound-3,screenUpperHorizontalBound+3),std::logic_error);
}
TEST_CASE("A created game object state should be is ALIVE")
{
    auto gameObject = GameObject(220,200);
    CHECK(gameObject.getState() == ALIVE);
}
TEST_CASE("Game object state can be set correctly")
{
    auto gameObject = GameObject(220,200);
    CHECK(gameObject.getState() == ALIVE);
    //Setting the object state to dead
    gameObject.setState(DEAD);
    CHECK(gameObject.getState() == DEAD);
}
TEST_CASE("The game objets position can be found")
{
    //Inital position of the game object
    double x = 320;
    double y = 656;
    auto gameObject = GameObject(x,y);
    CHECK(gameObject.getXpos() == x);
    CHECK(gameObject.getYpos() == y);
}

/////////////////////////////Testing for the Landers/////////////////////////////////////////////////////////

TEST_CASE("Testing Lander Move")
{
    Lander lander(100.0, 200.0);
    lander.setDirection(Direction::LEFT);
    lander.Move();
    CHECK(lander.getXpos() == 100 - (speed*0.125));
}

//The Space ship dimensions are 64x32
TEST_CASE("Lander moveLeft function test")
{
    auto lander = Lander(x,y);
    lander.setDirection(Direction::LEFT);
    lander.Move();

    CHECK(lander.getXpos() == x-(speed*0.125));

}
TEST_CASE("Lander moveRight function test")
{
    auto lander = Lander(x,y);
    lander.setDirection(Direction::RIGHT);
    lander.Move();
    CHECK(lander.getXpos() == x+(speed*0.125));
}
TEST_CASE("Lander moveUp function test")
{
    auto lander = Lander(x,y);
    lander.setDirection(Direction::UP);
    lander.Move();
    CHECK(lander.getYpos() == y-(speed*0.125));

}
TEST_CASE("Lander moveDown function test")
{
    auto lander = Lander(x,y);
    lander.setDirection(Direction::DOWN);
    lander.Move();
    CHECK(lander.getYpos() == y+(speed*0.125));

}
TEST_CASE("Lander does not get out of upper vertical bound")
{
    double y = 92; // Lower vertical bound which is screenLowerBound plus the width of the screen constant area
    auto lander = Lander(x,y);
    lander.setDirection(Direction::UP);
    lander.Move();

    CHECK (lander.getYpos()!=y-speed);
    CHECK ( lander.getYpos()==y);
}
TEST_CASE("Lander does not get out of lower vertical bound")
{
    double y = 684;  //Upper vertical bound(bottom side of the game screen which screenUpperVerticalBound subtract the height of the space ship )
    auto lander = Lander(x,y);
    lander.setDirection(Direction::DOWN);
    lander.Move();

    CHECK (lander.getYpos()!=y+speed);
    CHECK (lander.getYpos()==y);
}
TEST_CASE("Lander does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto lander = Lander(x,y);
    lander.setDirection(Direction::LEFT);
    lander.Move();

    CHECK (lander.getXpos()!=x-speed);
    CHECK (lander.getXpos()==x);
}
TEST_CASE("Test getting Lander object")
{
    Enemy enemy(100.0, 200.0);
    Lander& lander = enemy.getLander();

    // Check if the returned Lander object is not null.
    CHECK(&lander != nullptr);
}

//////////////////////////Testing of the Spaceship/////////////////////////////////////////////////////////////
TEST_CASE("Testing SpaceShip Move")
{
    SpaceShip spaceShip(100.0, 200.0);
    spaceShip.setDirection(Direction::LEFT);
    spaceShip.Move();
    CHECK(spaceShip.getXpos() == 100 - speed*0.5);
}

//The Space ship dimensions are 64x32
TEST_CASE("Spaceship moveLeft function test")
{
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::LEFT);
    spaceship.Move();

    CHECK(spaceship.getXpos() == x-speed*0.5);

}
TEST_CASE("Spaceship moveRight function test")
{
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::RIGHT);
    spaceship.Move();
    CHECK(spaceship.getXpos() == x+speed*0.5);
}
TEST_CASE("Spaceship moveUp function test")
{
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::UP);
    spaceship.Move();
    CHECK(spaceship.getYpos() == y-speed*0.5);

}
TEST_CASE("Spaceship moveDown function test")
{
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::DOWN);
    spaceship.Move();
    CHECK(spaceship.getYpos() == y+speed*0.5);

}
TEST_CASE("spaceship does not get out of upper vertical bound")
{
    double y = 92; // Lower vertical bound which is screenLowerBound plus the width of the screen constant area
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::UP);
    spaceship.Move();

    CHECK (spaceship.getYpos()!=y-speed);
    CHECK ( spaceship.getYpos()==y);
}
TEST_CASE("spaceship does not get out of lower vertical bound")
{
    double y = 668;  //Upper vertical bound(bottom side of the game screen which screenUpperVerticalBound subtract the height of the space ship )
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::DOWN);
    spaceship.Move();

    CHECK (spaceship.getYpos()!=y+speed);
    CHECK (spaceship.getYpos()==y);
}
TEST_CASE("spaceship does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto spaceship = SpaceShip(x,y);
    spaceship.setDirection(Direction::LEFT);
    spaceship.Move();

    CHECK (spaceship.getXpos()!=x-speed);
    CHECK (spaceship.getXpos()==x);
}

/////////////////////////////////Testing for missiles////////////////////////////////////////////////////

//The Space ship dimensions are 64x32
TEST_CASE("Missile moveLeft function test")
{
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::LEFT);
    missile.Move();

    CHECK(missile.getXpos() == x-speed*0.5);

}
TEST_CASE("Missile moveRight function test")
{
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::RIGHT);
    missile.Move();
    CHECK(missile.getXpos() == x+speed*0.5);
}
TEST_CASE("Missile moveUp function test")
{
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::UP);
    missile.Move();
    CHECK(missile.getYpos() == y-speed*0.5);

}
TEST_CASE("Missile moveDown function test")
{
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::DOWN);
    missile.Move();
    CHECK(missile.getYpos() == y+speed*0.5);

}
TEST_CASE("Missile does not get out of upper vertical bound")
{
    double y = 92; // Lower vertical bound which is screenLowerBound plus the width of the screen constant area
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::UP);
    missile.Move();

    CHECK (missile.getYpos()!=y-speed*0.5);
    CHECK ( missile.getYpos()==y);
}
TEST_CASE("Missile does not get out of lower vertical bound")
{
    double y = 692;  //Upper vertical bound(bottom side of the game screen which screenUpperVerticalBound subtract the height of the space ship )
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::DOWN);
    missile.Move();

    CHECK (missile.getYpos()!=y+speed*0.5);
    CHECK (missile.getYpos()==y);
}
TEST_CASE("Missile does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto missile = Missile(x,y,128,128);
    missile.setDirection(Direction::LEFT);
    missile.Move();

    CHECK (missile.getXpos()!=x-speed*0.5);
    CHECK (missile.getXpos()==x);
}

////////////////////////////LaserShot/////////////////////////////////////////////////////////////////////////
TEST_CASE("The initial direction is none")
{
    auto laserShots = LaserShot(x,y);
    CHECK(laserShots.getDirection() == Direction::NONE);
}
TEST_CASE("LaserShot does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto laserShots = LaserShot(x,y);
    CHECK(laserShots.getDirection() == Direction::NONE);
    laserShots.setDirection(Direction::LEFT);
    CHECK(laserShots.getDirection() == Direction::LEFT);
    CHECK(laserShots.getHeading() == Heading::LEFTHEADING);
    laserShots.Move();

    CHECK (laserShots.getXpos()!=x-speed);
    CHECK (laserShots.getXpos()==x);
}
TEST_CASE("LaserShots does not get out of left horizontal bound")
{
    double x = 880; //left horizontal bound(left side of the game screen)
    auto laserShots = LaserShot(x,y);
    laserShots.setDirection(Direction::RIGHT);
    laserShots.Move();

    CHECK (laserShots.getXpos()!=x-speed);
    CHECK (laserShots.getXpos()==x);
}
TEST_CASE("Laser shot  cannot be created outside the boundaries of the play screen")
{
    CHECK_THROWS(LaserShot(screenLowerBound-3,screenUpperHorizontalBound+3));
}
TEST_CASE("A logical error is thrown if a created a laser shot is outside the boundaries of play screen")
{
    CHECK_THROWS_AS(LaserShot(screenLowerBound-3,screenUpperHorizontalBound+3),std::logic_error);
}
TEST_CASE("A created laser shot state should be is ALIVE")
{
    auto laserShots = LaserShot(220,200);
    CHECK(laserShots.getState() == ALIVE);
}
TEST_CASE("Game laser shot can be set correctly")
{
    auto laserShots = LaserShot(220,200);
    CHECK(laserShots.getState() == ALIVE);
    //Setting the object state to dead
    laserShots.setState(DEAD);
    CHECK(laserShots.getState() == DEAD);
}
TEST_CASE("The lasershot position can be found")
{
    //Inital position of the laser object
    double x = 320;
    double y = 656;
    auto laserShots = LaserShot(x,y);
    CHECK(laserShots.getXpos() == x);
    CHECK(laserShots.getYpos() == y);
}
TEST_CASE("the laser shot initial is left headed")
{
    auto laserShots = LaserShot(220,200);
    CHECK(laserShots.getHeading() == Heading::LEFTHEADING);
}
TEST_CASE("heading can be set correctly")
{
    auto laserShots = LaserShot(220,200);
    laserShots.setHeading(Heading::RIGHTHEADIND);
    CHECK(laserShots.getHeading() == Heading::RIGHTHEADIND);
    laserShots.setHeading(Heading::LEFTHEADING);
    CHECK(laserShots.getHeading() == Heading::LEFTHEADING);
}

///Lazershots tests
///Lazershot are simply the collection of lazershot, the movement tests and other functionality has already been tested
///the container in which the lasershots are stored is a hidden implementaion so we used getObjectList to access it
TEST_CASE("a newly created Lazershots container is empty")
{
     auto lasershots = LaserShots();
     CHECK(lasershots.getObjectList().size() == 0);
     CHECK(lasershots.getObjectList().empty());
}
TEST_CASE("lasershot's are successfully added in the collection container")
{
    auto lasershots = LaserShots();
    CHECK(lasershots.getObjectList().size() == 0);
    lasershots.add(64,48);
    CHECK(lasershots.getObjectList().size() == 1);
    lasershots.add(86,256);
    CHECK(lasershots.getObjectList().size() == 2);
}
//The update method moves the laser and removes dead lasershots. Since the lasershots movement has been teste
//the focus is on the ability to remove dead laser shots
TEST_CASE("dead lasershot's are successfully removed from the lasershots")
{
    double x = 0;
    //last y position before getting out of screen bound
    double y = 128;
    auto lasershots = LaserShots();
    lasershots.add(x,y);
    lasershots.add(86,256);
    lasershots.add(256,256);
    auto numberOfLaserShots = lasershots.getObjectList().size();
    CHECK(lasershots.getObjectList().size() == 3);
    //When the laser shots are moved the first laser shot dies as it goes out of screen bound
    lasershots.update();
    lasershots.update();
    CHECK(lasershots.getObjectList().size() == --numberOfLaserShots);
}
///////////////////////////Testing the humanoid class///////////////////////////////////////////

TEST_CASE("The initial direction of the humanoid is none")
{
    auto humanoid = Humanoid(x,y);
    CHECK(humanoid.getDirection() == Direction::NONE);
}
TEST_CASE("humanoid does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto humanoid = Humanoid(x,y);
    CHECK(humanoid.getDirection() == Direction::NONE);
    humanoid.setDirection(Direction::LEFT);
    CHECK(humanoid.getDirection() == Direction::LEFT);
    CHECK(humanoid.getHeading() == Heading::LEFTHEADING);
    humanoid.Move();

    CHECK (humanoid.getXpos()!=x-speed*0.125);
    CHECK (humanoid.getXpos()==x);
}
TEST_CASE("humanoid does not get out of left horizontal bound")
{
    double x = 896; //left horizontal bound(left side of the game screen)
    auto humanoid = Humanoid(x,y);
    humanoid.setDirection(Direction::RIGHT);
    humanoid.Move();

    CHECK (humanoid.getXpos()!=x-speed*0.125);
    CHECK (humanoid.getXpos()==x);
}
TEST_CASE("humanoid  cannot be created outside the boundaries of the play screen")
{
    CHECK_THROWS(Humanoid(screenLowerBound-3,screenUpperHorizontalBound+3));
}
TEST_CASE("A logical error is thrown if a created a humanoid is outside the boundaries of play screen")
{
    CHECK_THROWS_AS(Humanoid(screenLowerBound-3,screenUpperHorizontalBound+3),std::logic_error);
}
TEST_CASE("A created humanoid state should be is ALIVE")
{
    auto humanoid = Humanoid(220,200);
    CHECK(humanoid.getState() == ALIVE);
}
TEST_CASE("Game humanoid can be set correctly")
{
    auto humanoid = Humanoid(220,200);
    CHECK(humanoid.getState() == ALIVE);
    //Setting the object state to dead
    humanoid.setState(DEAD);
    CHECK(humanoid.getState() == DEAD);
}
TEST_CASE("The humanoid position can be found")
{
    //Inital position of the humanoid
    double x = 320;
    double y = 656;
    auto humanoid = Humanoid(x,y);
    CHECK(humanoid.getXpos() == x);
    CHECK(humanoid.getYpos() == y);
}
TEST_CASE("the humanoids's initial is left headed")
{
    auto humanoid = Humanoid(220,200);
    CHECK(humanoid.getHeading() == Heading::LEFTHEADING);
}
TEST_CASE("heading can be set correctly")
{
    auto humanoid = Humanoid(220,200);
    humanoid.setHeading(Heading::RIGHTHEADIND);
    CHECK(humanoid.getHeading() == Heading::RIGHTHEADIND);
    humanoid.setHeading(Heading::LEFTHEADING);
    CHECK(humanoid.getHeading() == Heading::LEFTHEADING);
}
//////////////////////Humanoids class testing/////////////////////
TEST_CASE("a newly created humanoids's container is empty")
{
     auto humanoids = Humanoids();
     CHECK(humanoids.getObjectList().size() == 0);
     CHECK(humanoids.getObjectList().empty());
}
TEST_CASE("humanoids's's are successfully added in the collection container")
{
    auto humanoids = Humanoids();
    CHECK(humanoids.getObjectList().size() == 0);
    humanoids.add(64,48);
    CHECK(humanoids.getObjectList().size() == 1);
    humanoids.add(86,256);
    CHECK(humanoids.getObjectList().size() == 2);
}
TEST_CASE("dead humanoids's are successfully removed from the humanoids collection")
{
    double x = 0;
    //last y position before getting out of screen bound
    double y = 128;
    auto humanoids = Humanoids();
    humanoids.add(x,y);
    humanoids.add(86,256);
    humanoids.add(256,256);
    (humanoids.getObjectList().at(0))->setState(ObjectState::DEAD);
    auto numberOfhumanoids = humanoids.getObjectList().size();
    CHECK(humanoids.getObjectList().size() == 3);
    humanoids.update();
    CHECK(humanoids.getObjectList().size() == --numberOfhumanoids);
}
///////////////////////////////Testing missiles ///////////////////////////
TEST_CASE("The initial direction of the missile is not none")
{
    auto missile = Missile(x,y,0,0);
    CHECK(missile.getDirection() != Direction::NONE);
}
TEST_CASE("missile does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto missile = Missile(x,y,0,0);
    CHECK(missile.getDirection() != Direction::NONE);
    missile.setDirection(Direction::LEFT);
    CHECK(missile.getDirection() == Direction::LEFT);
    CHECK(missile.getHeading() == Heading::LEFTHEADING);
    missile.Move();

    CHECK (missile.getXpos()!=x-speed*0.125);
    CHECK (missile.getXpos()==x);
}
TEST_CASE("missile does not get out of left horizontal bound")
{
    double x = 896; //left horizontal bound(left side of the game screen)
    auto missile = Missile(x,y,0,0);
    missile.setDirection(Direction::RIGHT);
    missile.Move();

    CHECK (missile.getXpos()!=x-speed*0.125);
    CHECK (missile.getXpos()==x);
}
TEST_CASE("missile  cannot be created outside the boundaries of the play screen")
{
    CHECK_THROWS(Missile(screenLowerBound-3,screenUpperHorizontalBound+3,0,0));
}
TEST_CASE("A logical error is thrown if a created a missile is outside the boundaries of play screen")
{
    CHECK_THROWS_AS(Missile(screenLowerBound-3,screenUpperHorizontalBound+3,0,0),std::logic_error);
}
TEST_CASE("A created missile state should be is ALIVE")
{
    auto missile = Missile(220,200,0,0);
    CHECK(missile.getState() == ALIVE);
}
TEST_CASE("Game missile can be set correctly")
{
    auto missile  = Missile(220,200,0,0);
    CHECK(missile.getState() == ALIVE);
    //Setting the object state to dead
    missile.setState(DEAD);
    CHECK(missile.getState() == DEAD);
}
TEST_CASE("The missile position can be found")
{
    //Inital position of the missile
    double x = 320;
    double y = 656;
    auto missile = Missile(x,y,0,0);
    CHECK(missile.getXpos() == x);
    CHECK(missile.getYpos() == y);
}
TEST_CASE("the humanoids's initial is left headed")
{
    auto missile = Missile(220,200,0,0);
    CHECK(missile.getHeading() == Heading::LEFTHEADING);
}
TEST_CASE("heading can be set correctly")
{
    auto missile = Missile(220,200,0,0);
    missile.setHeading(Heading::RIGHTHEADIND);
    CHECK(missile.getHeading() == Heading::RIGHTHEADIND);
    missile.setHeading(Heading::LEFTHEADING);
    CHECK(missile.getHeading() == Heading::LEFTHEADING);
}
//////////////////////Missile class testing/////////////////////
TEST_CASE("a newly createdmissile's container is empty")
{
     auto missiles = Missiles();
     CHECK(missiles.getObjectList().size() == 0);
     CHECK(missiles.getObjectList().empty());
}
TEST_CASE("missiles's's are successfully added in the collection container")
{
    auto missiles = Missiles();
    CHECK(missiles.getObjectList().size() == 0);
    missiles.add(64,48);
    CHECK(missiles.getObjectList().size() == 1);
    missiles.add(86,256);
    CHECK(missiles.getObjectList().size() == 2);
}
TEST_CASE("dead missiles's are successfully removed from the lasershots")
{
    double x = 0;
    //last y position before getting out of screen bound
    double y = 128;
    auto missiles = Missiles();
    missiles.add(x,y);
    missiles.add(86,256);
    missiles.add(256,256);
    (missiles.getObjectList().at(0))->setState(ObjectState::DEAD);
    auto numberOfmissiles = missiles.getObjectList().size();
    CHECK(missiles.getObjectList().size() == 3);
    missiles.update();
    CHECK(missiles.getObjectList().size() == --numberOfmissiles);
}
///////////////////////////////Testing fuel ///////////////////////////
TEST_CASE("The initial direction of the fuel is none")
{
    auto fuel = Fuel(x,y);
    CHECK(fuel.getDirection() == Direction::NONE);
}
TEST_CASE("fuel does not get out of left horizontal bound")
{
    double x = 0; //left horizontal bound(left side of the game screen)
    auto fuel = Fuel(x,y);
    CHECK(fuel.getDirection() == Direction::NONE);
    fuel.setDirection(Direction::LEFT);
    CHECK(fuel.getDirection() == Direction::LEFT);
    CHECK(fuel.getHeading() == Heading::LEFTHEADING);
    fuel.Move();

    CHECK (fuel.getXpos()!=x-speed*0.125);
    CHECK (fuel.getXpos()==x);
}

TEST_CASE("fuel does not get out of left horizontal bound")
{
    double x = 896; //left horizontal bound(left side of the game screen)
    auto fuel = Fuel(x,y);
    fuel.setDirection(Direction::RIGHT);
    fuel.Move();

    CHECK (fuel.getXpos()!=x-speed*0.125);
    CHECK (fuel.getXpos()==x);
}
TEST_CASE("fuel  cannot be created outside the boundaries of the play screen")
{
    CHECK_THROWS(Fuel(screenLowerBound-3,screenUpperHorizontalBound+3));
}
TEST_CASE("A logical error is thrown if a created a fuel is outside the boundaries of play screen")
{
    CHECK_THROWS_AS(Fuel(screenLowerBound-3,screenUpperHorizontalBound+3),std::logic_error);
}
TEST_CASE("A created fuel state should be is ALIVE")
{
    auto fuel = Fuel(220,200);
    CHECK(fuel.getState() == ALIVE);
}
TEST_CASE("Game fuel can be set correctly")
{
    auto fuel  = Fuel(220,200);
    CHECK(fuel.getState() == ALIVE);
    //Setting the object state to dead
   fuel.setState(DEAD);
    CHECK(fuel.getState() == DEAD);
}
TEST_CASE("The fuel position can be found")
{
    //Inital position of the fuel
    double x = 320;
    double y = 656;
    auto fuel =Fuel(x,y);
    CHECK(fuel.getXpos() == x);
    CHECK(fuel.getYpos() == y);
}
TEST_CASE("the Fuel's initial is left headed")
{
    auto fuel = Fuel(220,200);
    CHECK(fuel.getHeading() == Heading::LEFTHEADING);
}
TEST_CASE("heading can be set correctly")
{
    auto fuel = Fuel(220,200);
    fuel.setHeading(Heading::RIGHTHEADIND);
    CHECK(fuel.getHeading() == Heading::RIGHTHEADIND);
    fuel.setHeading(Heading::LEFTHEADING);
    CHECK(fuel.getHeading() == Heading::LEFTHEADING);
}