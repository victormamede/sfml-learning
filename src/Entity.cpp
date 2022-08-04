#include "Entity.hpp"
#include <iostream>

sf::Vector2f Entity::getVelocity() const
{
  return _velocity;
}

void Entity::setVelocity(sf::Vector2f velocity)
{
  _velocity = velocity;
}

void Entity::setVelocity(float x, float y)
{
  _velocity.x = x;
  _velocity.y = y;
}

void Entity::updateCurrent(sf::Time deltaTime)
{
  move(_velocity * deltaTime.asSeconds());
}