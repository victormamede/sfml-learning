#pragma once

#include <SFML/Graphics.hpp>
#include <array>
#include "TextureHolder.hpp"
#include "SceneNode.hpp"
#include "Aircraft.hpp"

class World : private sf::NonCopyable
{
public:
  explicit World(sf::RenderWindow &window);
  void update(sf::Time deltaTime);
  void draw();

private:
  enum Layer
  {
    Background,
    Air,
    LayerCount
  };

  sf::RenderWindow &_window;
  sf::View _worldView;
  TextureHolder _textureHolder;
  SceneNode _sceneGraph;
  std::array<SceneNode *, LayerCount> _sceneLayers;
  sf::FloatRect _worldBounds;
  sf::Vector2f _spawnPosition;
  float _scrollSpeed;
  Aircraft *_player;

  void loadTextures();
  void buildScene();
};