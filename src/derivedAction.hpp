#pragma once
#include <SFML/System.hpp>
#include <functional>
#include "SceneNode.hpp"

template <typename GameObject, typename Function>
std::function<void(SceneNode &, sf::Time)> derivedAction(Function fn)
{
  return [=](SceneNode &node, sf::Time deltaTime)
  {
    assert(dynamic_cast<GameObject *>(&node) != nullptr); // check is casting is safe

    fn(static_cast<GameObject &>(node), deltaTime);
  };
}