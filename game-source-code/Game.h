/**
 * @file Game.h
 * @brief This file contains the declaration of the Game class, representing the game state.
 */
#ifndef GAME_H
#define GAME_H
#include "States.h"
#include "WriteText.h"
#include "GameBase.h"
#include "FileHandler.h"
#include "InputHandler.h"
#include "DrawObjects.h"
#include "DataBase.h"
#include "Timer.h"

/**
 * @class Game
 * @brief A class representing the game state of the application.
 */
class Game:public State
{
public:
    Game(StateStack&);
    virtual void draw(RenderWindow&);
    virtual bool update(Time dt);
    virtual bool handleEvent(const Event&,RenderWindow&);
private:
    void paintBackground();
    void setScreenConstants();
    void writeScreenConstants(RenderWindow&);
    void saveHighScore(int);
    void drawScreenContents(RenderWindow&);
    void handleEndGame();
    string convertToString(int);
    string _highScore;

    GameBase _playGame;
    FileHandler _readOrWriteToFile;
    InputHandler _playersInput;
    DrawObjects _drawGameObjects;
    DataBase _gameData;
    Timer _timer;

    vector<Text> _screenConstants;
    WriteText _texts;
    Texture _backgroundTexture;
    Sprite _background;
};
#endif //GAME_H