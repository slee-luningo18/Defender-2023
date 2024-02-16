#include "EndGame.h"
#include <string>
#include <stdexcept>
#include <fstream>

EndGame::EndGame(StateStack& Stack):State(Stack),_endGameData(States::EndGame)
{
    _screenText.setTextColor(Color(113,01,147));
    _screenText.setFont(_endGameData.getFont(Fonts::TimeSplitter));
    _resultText.setFont(_endGameData.getFont(Fonts::FireStorm));
    _resultText.setTextColor(Color(113,01,147));
    _score = _readOrWrite.readFromFile("resources/Score.txt");
    _gameResults = _readOrWrite.readFromFile("resources/GameResults.txt");
    setScreenTexts();
    paintBackground();
}
bool EndGame::handleEvent(const sf::Event& event,RenderWindow& window)
{
    if(event.type == sf::Event::Closed)window.close();
    if(event.type == Event::KeyPressed)
    {
        switch(event.key.code)
        {
        case Keyboard::Enter:
            requestStackPop();
            requestStackPush(States::Game);
            break;
        case Keyboard::Escape:
            requestStackPop();
            window.close();
            break;
        default:;
        }
    }
    return true;
}
void EndGame::setScreenTexts()
{
    _screenText.createText("Press Enter to Start a New Game",38,Vector2f(113,513),Text::Bold);
    _screenTexts.push_back(_screenText.getText());
    _screenText.createText("Press Escape to Exit Game",38,Vector2f(60,600),Text::Bold);
    _screenTexts.push_back(_screenText.getText());
    _resultText.createText("You "+gameResults(),90,Vector2f(380,320),Text::Bold);
    _screenTexts.push_back(_resultText.getText());
    _resultText.createText("Your score is: "+_score,80,Vector2f(5,250),Text::Bold);
    _screenTexts.push_back(_resultText.getText());
}
void EndGame::drawScreenTexts(RenderWindow& window)
{
    for(Text text: _screenTexts)
    {
        window.draw(text);
    }
}
void EndGame::paintBackground()
{
    _background.setTexture(_endGameData.getTexture(Textures::EndgameBackground));
    _background.setColor(Color(255, 255, 255, 255));
    _background.setPosition(0,0);
}
string EndGame::gameResults()const
{
    auto  gameResult = 0;
    istringstream (_gameResults)>> gameResult;
    switch(gameResult)
    {
    case 1:
        return "Won";
        break;
    case 0:
        return "Lose";
        break;
    default:
        return " ";
        ;
    }
}
void EndGame::draw(RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    drawScreenTexts(window);
    window.display();
}
bool EndGame::update(Time dt)
{
    return true;
}