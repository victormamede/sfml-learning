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

  explicit Aircraft(Type type, Category::Type category, const TextureHolder &textureHolder);
  void accelerate(sf::Vector2f acceleration);
  virtual unsigned int getCategory() const override;

private:
  Type _type;
  Category::Type _category;
  sf::Sprite _sprite;
  virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
};
