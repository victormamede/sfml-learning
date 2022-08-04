#include "Aircraft.hpp"

Texture::Id aircraftTypeToTextureId(Aircraft::Type type)
{
  switch (type)
  {
  case Aircraft::Type::Eagle:
    return Texture::Id::AircraftEagle;
  default:
    return Texture::Id::AircraftEagle;
  }
}

Aircraft::Aircraft(Type type, const TextureHolder &textureHolder) : _type(type), _sprite(textureHolder.get(aircraftTypeToTextureId(type)))
{
  sf::FloatRect bounds = _sprite.getLocalBounds();
  _sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const
{
  target.draw(_sprite, states);
}