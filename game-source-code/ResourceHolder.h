/**
 * @file ResourceHolder.h
 * @brief Header file for the ResourceHolder class, which manages loading and accessing game resources such as textures and fonts.
 */
#ifndef RESOURCEHOLDER_H
#define RESOURCEHOLDER_H

#include <SFML/Graphics.hpp>
#include <map>
#include <memory>
#include "States.h"

enum class Textures
{
    Pointer, SpaceShip, Missile, Laser, Lander, Humanoids, Fuel, ShieldedShip,
    MenuBackground, OptionsBackground, HelpBackground, SplashScreenBackground, EndgameBackground, GameBackground
};

enum class Fonts
{
    Transformer, TimeSplitter, FireStorm
};

/**
 * @class ResourceHolder
 * @brief A template class for managing game resources, such as textures and fonts.
 *
 * This class provides methods for loading and accessing resources based on their unique identifiers.
 *
 * @tparam Resource The type of resource to be managed (e.g., sf::Texture or sf::Font).
 * @tparam Identifier The enum class type representing unique resource identifiers.
 */
template<typename Resource, typename Identifier>
class ResourceHolder
{
public:
    /**
     * @brief Load a resource from a file.
     * @param id The unique identifier for the resource.
     * @param filename The file path to the resource.
     */
    void load(Identifier, const std::string&);

    /**
     * @brief Get a reference to a loaded resource.
     * @param id The unique identifier of the resource.
     * @return A reference to the resource.
     */
    Resource& get(Identifier);

    /**
     * @brief Get a const reference to a loaded resource.
     * @param id The unique identifier of the resource.
     * @return A const reference to the resource.
     */
    const Resource& get(Identifier) const;

private:
    std::map<Identifier, std::unique_ptr<Resource>> ResourceMap; ///< A map for storing loaded resources.
};
#endif // RESOURCEHOLDER_H
