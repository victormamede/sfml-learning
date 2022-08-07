#include <algorithm>
#include <cassert>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "SceneNode.hpp"

SceneNode::SceneNode() : _children(), _parent(nullptr)
{
}

void SceneNode::addChild(SceneNodePtr child)
{
  child->_parent = this;
  _children.push_back(std::move(child));
}

SceneNode::SceneNodePtr SceneNode::removeChild(const SceneNode &child)
{
  auto found = std::find_if(_children.begin(), _children.end(), [&](SceneNodePtr &p) -> bool
                            { return p.get() == &child; });
  assert(found != _children.end());

  SceneNodePtr result = std::move(*found);
  result->_parent = nullptr;
  _children.erase(found);

  return result;
}

void SceneNode::update(sf::Time deltaTime)
{
  for (const auto &child : _children)
  {
    child->update(deltaTime);
  }
  updateCurrent(deltaTime);
}
void SceneNode::updateCurrent(sf::Time deltaTime)
{
}

void SceneNode::draw(sf::RenderTarget &target,
                     sf::RenderStates states) const
{
  states.transform *= getTransform();
  drawCurrent(target, states);

  for (const auto &child : _children)
  {
    child->draw(target, states);
  }
}

void SceneNode::drawCurrent(sf::RenderTarget &target,
                            sf::RenderStates states) const
{
}

sf::Transform SceneNode::getWorldTransform() const
{
  if (_parent == nullptr)
    return getTransform();

  return _parent->getTransform() * getTransform();
}

unsigned int SceneNode::getCategory() const
{
  return (unsigned int)Category::Type::Scene;
}

void SceneNode::onCommand(const Command &command, sf::Time deltaTime)
{
  if (command.category & getCategory())
    command.action(*this, deltaTime);

  for (const auto &child : _children)
    child->onCommand(command, deltaTime);
}