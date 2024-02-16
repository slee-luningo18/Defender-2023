#include "Game.h"
#include <fstream>
#include <string>
#include <sstream>

Game::Game(StateStack& Stack):State(Stack),_playGame(),_gameData(States::Game)
{
    _texts.setFont(_gameData.getFont(Fonts::Transformer));
    _highScore = _readOrWriteToFile.readFromFile("resources/HighScore.txt");
    setScreenConstants();
    paintBackground();
}
bool Game::handleEvent(const sf::Event& event,RenderWindow& window)
{
    if(event.type == sf::Event::Closed)window.close();
    else if(event.type == Event::KeyPressed)
    {
        switch(event.key.code)
        {
        case Keyboard::Escape:
            requestStackPush(States::Exit);
            break;
        case Keyboard::Backspace:
            requestStackPop();
            requestStackPush(States::Menu);
            break;
        case Keyboard::Right:
            _playGame.moveRight();
            break;
        case Keyboard::Left:
            _playGame.moveLeft();
            break;
        case Keyboard::Up:
            _playGame.moveUp();
            break;
        case Keyboard::Down:
            _playGame.moveDown();
            break;
        case Keyboard::Space:
            _playGame.shoot();
            break;
        default:;
        }
    }
    return true;
}
void Game::drawScreenContents(RenderWindow& window)
{
    writeScreenConstants(window);
    RectangleShape fuelBar(Vector2f(200,20));
    fuelBar.setPosition(400,40);
    RectangleShape Marker(Vector2f(200,20));
    Marker.setPosition(400,40);
    auto fuelBarWidth = 200.0*((_playGame.getPlayer().getFuel().getRemainingFuel())/20.0);
    fuelBar.setFillColor(Color::Green);
    Marker.setFillColor(Color::White);
    Marker.setOutlineThickness(2);
    Marker.setOutlineColor(Color::Green);
    fuelBar.setSize(Vector2f(fuelBarWidth,20));
    _texts.createText(convertToString(_playGame.getScore()), 30, Vector2f(120,35),Text::Bold);
    _texts.displayText(window);
    window.draw(Marker);
    if(_playGame.getPlayer().getFuel().isThereFuel())
        window.draw(fuelBar);
}
void Game::saveHighScore(int score)
{
    auto highScore = 0;
    istringstream (_highScore)>>highScore;
    if(score > highScore)
        _readOrWriteToFile.writeToFile("resources/HighScore.txt",score);
    else
        _readOrWriteToFile.writeToFile("resources/HighScore.txt",highScore);
}
string Game::convertToString(int number)
{
    ostringstream convert;
    convert << number;
    return convert.str();
}
void Game::setScreenConstants()
{
    _texts.createText("HIGH SCORE:",30,Vector2f(687,2),Text::Bold);
    _screenConstants.push_back(_texts.getText());
    _texts.createText(_highScore,30,Vector2f(750,35),Text::Bold);
    _screenConstants.push_back(_texts.getText());
    _texts.createText("SCORE:",30,Vector2f(88,2),Text::Bold);
    _screenConstants.push_back(_texts.getText());
    _texts.createText("FUEL:",30,Vector2f(295,30),Text::Bold);
    _screenConstants.push_back(_texts.getText());
}
void Game::handleEndGame()
{
    saveHighScore(_playGame.getScore());
    _readOrWriteToFile.writeToFile("resources/Score.txt",_playGame.getScore());
    if(_playGame.hasWon())
        _readOrWriteToFile.writeToFile("resources/GameResults.txt",1);
    else
        _readOrWriteToFile.writeToFile("resources/GameResults.txt",0);
    _timer.delay(3.0);
    requestStackPop();
    requestStackPush(States::EndGame);
    return;
}
void Game::paintBackground()
{
    _background.setTexture(_gameData.getTexture(Textures::GameBackground));
    _background.setColor(Color(255, 255, 255, 200));
    _background.setPosition(0,0);
}
void Game::writeScreenConstants(RenderWindow& window)
{
    for(Text text : _screenConstants)
    {
        window.draw(text);
    }
}
void Game::draw(RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    if(!_playGame.isGameOver())
    {
        drawScreenContents(window);
        _drawGameObjects.drawGameObjects(_playGame,window);
        window.display();
    }
    else
    {
        _texts.setTextColor(Color(113,01,147));
        _texts.setFont(_gameData.getFont(Fonts::FireStorm));
        _texts.createText("Game Over",100, Vector2f(180,290),Text::Bold);
        _texts.displayText(window);
        window.display();
        handleEndGame();
    }
}
bool Game::update(Time dt)
{
    _playGame.gameUpdate();
    return true;
}