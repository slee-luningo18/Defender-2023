#include "DataBase.h"

DataBase::DataBase(States state):_state(state)
{
    loadTextures(_state);
    loadFonts();
}
Font& DataBase::getFont(Fonts fontId)
{
    return (_fonts.get(fontId));
}
Texture& DataBase::getTexture(Textures textureId)
{
    return (_textures.get(textureId));
}
void DataBase::loadTextures(States state)
{
    switch(state)
    {
    case States::SplashScreen:
        _textures.load(Textures::SplashScreenBackground,"resources/Splashscreen Background.png");
        break;
    case States::Menu:
        _textures.load(Textures::MenuBackground,"resources/Menu background.png");
        _textures.load(Textures::Pointer,"resources/Pointer.png");
        break;
    case States::Game:
        _textures.load(Textures::SpaceShip,"resources/SpaceShip.png");
        _textures.load(Textures::Lander,"resources/Landers.png");
        _textures.load(Textures::Laser,"resources/Laser.png");
        _textures.load(Textures::Missile,"resources/Missile.png");
        _textures.load(Textures::Humanoids,"resources/Humanoids.png");
        _textures.load(Textures::Fuel,"resources/Fuel.png");
        _textures.load(Textures::GameBackground,"resources/Game background.png");
        break;
    case States::Help:
        _textures.load(Textures::HelpBackground,"resources/Help background.png");
        break;
    case States::Options:
        _textures.load(Textures::OptionsBackground,"resources/Options background.png");
        break;
    case States::EndGame:
        _textures.load(Textures::EndgameBackground,"resources/EndGame Background.png");
        break;
    default:
        ;
    }
}
void DataBase::loadFonts()
{
    _fonts.load(Fonts::FireStorm,"resources/Fire Storm.otf");
    _fonts.load(Fonts::TimeSplitter,"resources/Future TimeSplitters.otf");
    _fonts.load(Fonts::Transformer,"resources/transformers_movie.ttf");
}