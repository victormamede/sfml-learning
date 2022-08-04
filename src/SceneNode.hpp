#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable
{
public:
  typedef std::unique_ptr<SceneNode> SceneNodePtr;

  SceneNode();

  void update(sf::Time deltaTime);
  void addChild(SceneNodePtr child);
  SceneNodePtr removeChild(const SceneNode &child);
  sf::Transform getWorldTransform() const;

private:
  std::vector<SceneNodePtr> _children;
  SceneNode *_parent;

  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const override final;
  virtual void drawCurrent(sf::RenderTarget &target,
                           sf::RenderStates states) const;
  virtual void updateCurrent(sf::Time deltaTime);
};