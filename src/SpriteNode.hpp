#pragma once

#include <SFML/Graphics.hpp>
#include "SceneNode.hpp"

class SpriteNode : public SceneNode
{
public:
  explicit SpriteNode(const sf::Texture &texture);
  SpriteNode(const sf::Texture &texture, const sf::IntRect &rect);

private:
  sf::Sprite _sprite;

  virtual void drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const override;
};