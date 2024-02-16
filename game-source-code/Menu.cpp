#include "Menu.h"

// Constructor for the Menu class
Menu::Menu(StateStack& Stack) : State(Stack), _screenData(States::Menu)
{
    _pointer.setTexture(_screenData.getTexture(Textures::Pointer));
    _menuOptions.setFont(_screenData.getFont(Fonts::TimeSplitter));
    _menuOptions.setTextColor(Color::White);
    _optionsIndex = 0;
    setMenuOptions();
    paintBackground();
}

// Handles events in the main menu state
bool Menu::handleEvent(const sf::Event& event, RenderWindow& window)
{
    if (event.type == sf::Event::Closed)
        window.close();
    if (event.type == Event::KeyPressed)
    {
        switch (event.key.code)
        {
        case Keyboard::Up:
            if (_optionsIndex > 0)
                _optionsIndex--;
            else
                _optionsIndex = static_cast<int>(_options.size()) - 1;
            break;
        case Keyboard::Down:
            if (_optionsIndex < static_cast<int>(_options.size()) - 1)
                _optionsIndex++;
            else
                _optionsIndex = 0;
            break;
        case Keyboard::Escape:
            window.close();
            break;
        case Keyboard::Enter:
            optionSelection();
            break;
        default:;
        }
    }
    return true;
}

// Handles menu option selection
void Menu::optionSelection()
{
    switch (_optionsIndex)
    {
    case Play:
        requestStackPop();
        requestStackPush(States::Game);
        break;
    case Options:
        requestStackPush(States::Options);
        break;
    case Help:
        requestStackPush(States::Help);
        break;
    case Quit:
        requestStackPop();
        requestStackPush(States::Exit);
    default:
        ;
    }
}

// Paints the background of the main menu
void Menu::paintBackground()
{
    _background.setTexture(_screenData.getTexture(Textures::MenuBackground));
    _background.setColor(Color(255, 255, 255, 255));
    _background.setPosition(0, 0);
}

// Sets up the main menu options
void Menu::setMenuOptions()
{
    _menuOptions.createText("Play", 50, Vector2f(410, 230), Text::Bold);
    _options.push_back(_menuOptions.getText());
    _menuOptions.createText("Options", 50, Vector2f(385, 300), Text::Bold);
    _options.push_back(_menuOptions.getText());
    _menuOptions.createText("Help", 50, Vector2f(410, 370), Text::Bold);
    _options.push_back(_menuOptions.getText());
    _menuOptions.createText("Quit", 50, Vector2f(410, 440), Text::Bold);
    _options.push_back(_menuOptions.getText());
}

// Draws the main menu options
void Menu::drawMenuOptions(RenderWindow& window)
{
    for (Text text : _options)
    {
        window.draw(text);
    }
}

// Renders the main menu screen
void Menu::draw(RenderWindow& window)
{
    window.clear();
    window.draw(_background);
    drawMenuOptions(window);
    window.draw(_pointer);
    window.display();
}

// Updates the appearance of menu options
bool Menu::update(Time dt)
{
    int x = 335;
    for (Text& text : _options)
    {
        text.setFillColor(Color::White);
    }
    _options[_optionsIndex].setFillColor(Color::Green);

    if (_optionsIndex == 1)
        x = 310;
    int y = 246 + _optionsIndex * 70;
    _pointer.setPosition(x, y);

    return true;
}