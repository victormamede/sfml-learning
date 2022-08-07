#pragma once

#include <SFML/Graphics.hpp>
#include "Entity.hpp"
#include "TextureHolder.hpp"

class Aircraft : public Entity
{
public:
  enum class Type
  {
    Eagle,
  };

  explicit Aircraft(Type type, const TextureHolder &textureHolder);

private:
  Type _type;
  sf::Sprite _sprite;
  virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
};