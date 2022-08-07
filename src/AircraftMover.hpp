#pragma once

#include <SFML/System.hpp>
#include "SceneNode.hpp"
#include "Aircraft.hpp"

struct AircraftMover
{
  sf::Vector2f velocity;

  AircraftMover(float vx, float vy) : velocity(vx, vy) {}
  void operator()(Aircraft &aircraft, sf::Time) const
  {
    aircraft.accelerate(velocity);
  }
};