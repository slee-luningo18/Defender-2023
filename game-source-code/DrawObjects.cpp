#include "DrawObjects.h"

/**
 * @brief Constructor for the DrawObjects class.
 *
 * Initializes the DrawObjects class by setting the animation flag and starting a timer.
 */
DrawObjects::DrawObjects():_gameData(States::Game)
{
    _flag = true;
    _timer.start();
}

/**
 * @brief Draw a single game object at the specified position.
 *
 * @param x The X-coordinate of the object.
 * @param y The Y-coordinate of the object.
 * @param texture The texture of the object.
 * @param window The render window to draw on.
 */
void DrawObjects::drawObject(double x, double y, Texture& texture, RenderWindow& window)
{
    Sprite objectSprite(texture);
    objectSprite.setPosition(x, y);
    window.draw(objectSprite);
}

/**
 * @brief Draw a list of game objects.
 *
 * @param window The render window to draw on.
 * @param gameobjectList The list of game objects to draw.
 * @param texture The texture of the game objects.
 */
void DrawObjects::drawObjectList(RenderWindow& window, GameObjectsList gameobjectList, Texture& texture)
{
    for(auto iter = begin(gameobjectList); iter != end(gameobjectList); iter++)
    {
        if((*iter)->isAlive()) drawObject((*iter)->getXpos(), (*iter)->getYpos(), texture, window);
    }
}

/**
 * @brief Draw a humanoid game object.
 *
 * @param humanoid The humanoid game object to draw.
 * @param texture The texture of the humanoid.
 * @param window The render window to draw on.
 */
void DrawObjects::drawHumanoid(GameObjectPtr humanoid, Texture& texture, RenderWindow& window)
{
    IntRect rectangle(0, 0, 16, 32);
    if(humanoid->getHeading() == Heading::RIGHTHEADIND)
        rectangle.left = 16;

    Sprite objectSprite(texture, rectangle);
    objectSprite.setPosition(humanoid->getXpos(), humanoid->getYpos());
    window.draw(objectSprite);
}

/**
 * @brief Draw a list of humanoid game objects.
 *
 * @param window The render window to draw on.
 * @param gameobjectList The list of humanoid game objects to draw.
 * @param texture The texture of the humanoids.*/
void DrawObjects::drawHumanoids(RenderWindow& window, GameObjectsList gameobjectList, Texture& texture)
{
    for(auto iter = begin(gameobjectList); iter != end(gameobjectList); iter++)
    {
        if((*iter)->isAlive()) drawHumanoid((*iter), texture, window);
    }
}

/**
 * @brief Draw a lander game object.
 *
 * @param x The X-coordinate of the lander.
 * @param y The Y-coordinate of the lander.
 * @param texture The texture of the lander.
 * @param window The render window to draw on.
 */
void DrawObjects::drawLander(double x, double y, Texture& texture, RenderWindow& window)
{
    IntRect rectangle(0, 0, 16, 16);
    if(_timer.readTime() >= 0.2)
    {
        _flag = !_flag;
        _timer.start();
    }
    if(_flag)
        rectangle.left = 16;

    Sprite objectiveSprite(texture, rectangle);
    objectiveSprite.setPosition(x, y);
    window.draw(objectiveSprite);
}

/**
 * @brief Draw enemy game objects.
 *
 * This function draws both enemy landers and their missiles.
 *
 * @param window The render window to draw on.
 * @param enemies The list of enemy game objects.
 * @param landerTexture The texture of enemy landers.
 * @param missileTexture The texture of enemy missiles.
 */
void DrawObjects::drawEnemies(RenderWindow& window, EnemyList enemies, Texture& landerTexture, Texture& missileTexture)
{
    for(auto iter = begin(enemies); iter != end(enemies); iter++)
    {
        if((*iter)->isAlive())
        {
            drawObjectList(window, (*iter)->getMissiles().getObjectList(), missileTexture);
            auto Lander = (*iter)->getLander();
            drawLander(Lander.getXpos(), Lander.getYpos(), landerTexture, window);
        }
    }
}

/**
 * @brief Draw the player's spaceship.
 *
 * @param spaceship The player's spaceship.
 * @param texture The texture of the player's spaceship.
 * @param window The render window to draw on.
 */
void DrawObjects::drawPlayer(SpaceShip& spaceship, Texture& texture, RenderWindow& window)
{
    IntRect rectangle(0, 0, 48, 32);
    if(spaceship.getHeading() == LEFTHEADING)
        rectangle.left = 48;

    Sprite objectiveSprite(texture, rectangle);
    objectiveSprite.setPosition(spaceship.getXpos(), spaceship.getYpos());
    window.draw(objectiveSprite);
}

/**
 * @brief Draw all game objects within the gamebase.
 *
 * This function is used to draw all game objects, including the player's spaceship, enemies, missiles, and humanoids.
 *
 * @param gamebase The GameBase containing the game objects to draw.
 * @param window The render window to draw on.
 */
void DrawObjects::drawGameObjects(GameBase& gamebase, RenderWindow& window)
{
    drawPlayer((gamebase.getPlayer()).getSpaceShip(), _gameData.getTexture(Textures::SpaceShip), window);
    drawObjectList(window, ((gamebase.getPlayer()).getLaserShots()).getObjectList(), _gameData.getTexture(Textures::Laser));
    drawEnemies(window, (gamebase.getEnemies()).getEnemyList(), _gameData.getTexture(Textures::Lander), _gameData.getTexture(Textures::Missile));
    drawHumanoids(window, (gamebase.getHumanoids()).getObjectList(), _gameData.getTexture(Textures::Humanoids));
    drawObjectList(window, (gamebase.getFuelTanks()).getObjectList(), _gameData.getTexture(Textures::Fuel));
}