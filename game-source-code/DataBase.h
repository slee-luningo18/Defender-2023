#pragma once
/**
 * @file DataBase.h
 * @brief Header file for the DataBase class, providing access to fonts and textures for the game.
 */
#ifndef DATABASE_H
#define DATABASE_H

#include "States.h"
#include "GameStates.h"
#include "ResourceHolder.h"

/*
 * @class DataBase
 * @brief Provides access to fonts and textures used in the game.*/
 
class DataBase
{
public:
    /*
      @brief Constructor for the DataBase class.
     
      @param state The current game state to load resources for.
     */
    DataBase(States);

    /*
      @brief Get the font associated with a specific font type.
     
      @param fontType The type of font to retrieve.
      @return Reference to the requested Font object.
     */
    Font& getFont(Fonts);

    /*
      @brief Get the texture associated with a specific texture type.
     
      @param textureType The type of texture to retrieve.
      @return Reference to the requested Texture object.
     */
    Texture& getTexture(Textures);

private:
    /*
      @brief Load fonts required for the game.
     */
    void loadFonts();

    /*
      @brief Load textures required for the game based on the game state.
     
      @param state The current game state to determine which textures to load.
     */
    void loadTextures(States);

    States _state;  //The current game state.
    ResourceHolder<Texture, Textures> _textures;  //Resource holder for textures.
    ResourceHolder<Font, Fonts >_fonts;  //Resource holder for fonts.
};

#endif  //DATABASE_H