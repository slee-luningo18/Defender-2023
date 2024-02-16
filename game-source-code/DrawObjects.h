/**
 * @file DrawObjects.h
 * @brief Defines the DrawObjects class for rendering game objects.
 */
#ifndef DRAWOBJECTS_H
#define DRAWOBJECTS_H

#include "DataBase.h"
#include "GameBase.h"
#include "GameObjectsContainer.h"

/**
 * @class DrawObjects
 * @brief Responsible for rendering game objects in the game.
 */
class DrawObjects {
public:
    /**
     * @brief Constructor for the DrawObjects class.
     */
    DrawObjects();

    /**
     * @brief Draw game objects using the specified GameBase and RenderWindow.
     *
     * @param gameBase Reference to the GameBase containing game state.
     * @param window Reference to the RenderWindow used for rendering.
     */
    void drawGameObjects(GameBase&, RenderWindow&);

private:
    /**
     * @brief Draw a single game object at the specified position with a texture.
     *
     * @param x X-coordinate of the object.
     * @param y Y-coordinate of the object.
     * @param texture Texture to be applied to the object.
     * @param window Reference to the RenderWindow used for rendering.
     */
    void drawObject(double, double, Texture&, RenderWindow&);

    /**
     * @brief Draw a list of game objects using a common texture.
     *
     * @param window Reference to the RenderWindow used for rendering.
     * @param objectList List of game objects to be drawn.
     * @param texture Texture to be applied to the objects.
     */
    void drawObjectList(RenderWindow&, GameObjectsList, Texture&);

    /**
     * @brief Draw the player's spaceship with a texture.
     *
     * @param spaceShip Reference to the player's spaceship.
     * @param texture Texture to be applied to the spaceship.
     * @param window Reference to the RenderWindow used for rendering.
     */
    void drawPlayer(SpaceShip&, Texture&, RenderWindow&);

    /**
     * @brief Draw a lander at the specified position with a texture.
     *
     * @param x X-coordinate of the lander.
     * @param y Y-coordinate of the lander.
     * @param texture Texture to be applied to the lander.
     * @param window Reference to the RenderWindow used for rendering.
     */
    void drawLander(double, double, Texture&, RenderWindow&);

    /**
     * @brief Draw a list of enemy objects with textures.
     *
     * @param window Reference to the RenderWindow used for rendering.
     * @param enemyList List of enemy objects to be drawn.
     * @param landerTexture Texture for lander objects.
     * @param missileTexture Texture for missile objects.
     */
    void drawEnemies(RenderWindow&, EnemyList, Texture&, Texture&);

    /**
     * @brief Draw a humanoid game object with a texture.
     *
     * @param gameObject Reference to the humanoid game object.
     * @param texture Texture to be applied to the humanoid.
     * @param window Reference to the RenderWindow used for rendering.
     */
    void drawHumanoid(GameObjectPtr, Texture&, RenderWindow&);

    /**
     * @brief Draw a list of humanoid game objects with a common texture.
     *
     * @param window Reference to the RenderWindow used for rendering.
     * @param humanoidList List of humanoid game objects to be drawn.
     * @param texture Texture to be applied to the humanoids.
     */
    void drawHumanoids(RenderWindow&, GameObjectsList, Texture&);

    bool _flag;
    Timer _timer;
    DataBase _gameData;
};

#endif // DRAWOBJECTS_H
