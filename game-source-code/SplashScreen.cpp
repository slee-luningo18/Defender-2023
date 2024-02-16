#include "SplashScreen.h"

/**
 * @brief Constructor for the SplashScreen class.
 * @param Stack The StateStack to which the splash screen belongs.
 */
SplashScreen::SplashScreen(StateStack& Stack): State(Stack), _screenData(States::SplashScreen)
{
    _screenText.setFont(_screenData.getFont(Fonts::TimeSplitter));
    paintBackground();
    setScreenText();
}

/**
 * @brief Handle an event for the splash screen.
 * @param event The SFML event to be handled.
 * @param window The RenderWindow for handling the event.
 * @return True if the event is successfully handled, false otherwise.
 */
bool SplashScreen::handleEvent(const sf::Event& event, RenderWindow& window)
{
    if(event.type == sf::Event::Closed) window.close();
    if(event.type == Event::KeyPressed && event.key.code == Keyboard::Enter)
    {
        requestStackPop();
        requestStackPush(States::Menu);
    }
    return true;
}

/**
 * @brief Paint the background of the splash screen.
 */
void SplashScreen::paintBackground()
{
    _background.setTexture(_screenData.getTexture(Textures::SplashScreenBackground));
    _background.setColor(Color(255, 255, 255, 255));
    _background.setPosition(0, 0);
}

/**
 * @brief Set the text to be displayed on the splash screen.
 */
void SplashScreen::setScreenText()
{
    _screenText.setTextColor(Color(255, 200, 110));
    _screenText.createText("Players movement", 35, Vector2f(320, 590));
    _screenTexts.push_back(_screenText.getText());
    _screenText.createText("Shooting", 35, Vector2f(580, 590));
    _screenTexts.push_back(_screenText.getText());
    _screenText.createText("Press Enter to continue", 60, Vector2f(300, 340));
    _screenTexts.push_back(_screenText.getText());
}

/**
 * @brief Draw the text on the splash screen.
 * @param window The RenderWindow in which to draw the text.
 */
void SplashScreen::drawScreenText(RenderWindow& window)
{
    for (Text text : _screenTexts)
    {
        window.draw(text);
    }
}

/**
 * @brief Draw the splash screen in the provided RenderWindow.
 * @param window The RenderWindow in which to draw the splash screen.
 */
void SplashScreen::draw(RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    drawScreenText(window);
    window.display();
}

/**
 * @brief Update the splash screen with the specified time.
 * @param dt The time elapsed since the last update.
 * @return True if the update is successful, false otherwise.
 */
bool SplashScreen::update(Time dt)
{
    return true;
}
