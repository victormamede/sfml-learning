#pragma once

#include <SFML/Graphics.hpp>
#include "ResourceHolder.hpp"

namespace Texture
{
  enum class Id
  {
    AircraftEagle,
    Ground
  };
};

typedef ResourceHolder<sf::Texture, Texture::Id> TextureHolder;