#pragma once

#include <SFML/System.hpp>
#include "SceneNode.hpp"

class Entity : public SceneNode
{
public:
  void setVelocity(sf::Vector2f velocity);
  void setVelocity(float x, float y);
  sf::Vector2f getVelocity() const;

protected:
  virtual void updateCurrent(sf::Time deltaTime) override;

private:
  sf::Vector2f _velocity;
};