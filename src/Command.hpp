#pragma once
#include <functional>
#include <queue>
#include <SFML/System.hpp>

class SceneNode;

struct Command
{
  std::function<void(SceneNode &, sf::Time)> action;
  unsigned int category;
};

typedef std::queue<Command> CommandQueue;