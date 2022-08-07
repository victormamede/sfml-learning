#include <memory>
#include "World.hpp"
#include "SpriteNode.hpp"

World::World(sf::RenderWindow &window) : _window(window),
                                         _worldView(window.getDefaultView()),
                                         _worldBounds(0.f, 0.f, _worldView.getSize().x, 2000.f),
                                         _spawnPosition(_worldView.getSize().x / 2.f, _worldBounds.height - _worldView.getSize().y),
                                         _player(nullptr),
                                         _scrollSpeed(-40.f)
{
  loadTextures();
  buildScene();

  _worldView.setCenter(_spawnPosition);
}

void World::loadTextures()
{
  _textureHolder.load(Texture::Id::AircraftEagle, "assets/eagle.png");
  _textureHolder.load(Texture::Id::Ground, "assets/ground.png");

  _textureHolder.get(Texture::Id::Ground).setRepeated(true);
}

void World::buildScene()
{
  for (int i = 0; i < LayerCount; i++)
  {
    auto layer = std::make_unique<SceneNode>();
    _sceneLayers[i] = layer.get();

    _sceneGraph.addChild(std::move(layer));
  }

  sf::Texture &texture = _textureHolder.get(Texture::Id::Ground);
  sf::IntRect textureRect(_worldBounds);

  auto backgroundSprite = std::make_unique<SpriteNode>(texture, textureRect);
  backgroundSprite->setPosition(_worldBounds.left, _worldBounds.top);
  _sceneLayers[Background]->addChild(std::move(backgroundSprite));

  auto player = std::make_unique<Aircraft>(Aircraft::Type::Eagle, Category::Type::PlayerAircraft, _textureHolder);
  _player = player.get();
  _player->setPosition(_spawnPosition);
  _player->setVelocity(0.f, _scrollSpeed);
  _sceneLayers[Air]->addChild(std::move(player));

  auto leftEscort = std::make_unique<Aircraft>(Aircraft::Type::Eagle, Category::Type::AlliedAircraft, _textureHolder);
  leftEscort->setPosition(-80.f, 50.f);
  _player->addChild(std::move(leftEscort));

  auto rightEscort = std::make_unique<Aircraft>(Aircraft::Type::Eagle, Category::Type::AlliedAircraft, _textureHolder);
  rightEscort->setPosition(80.f, 50.f);
  _player->addChild(std::move(rightEscort));
}

void World::draw()
{
  _window.setView(_worldView);
  _window.draw(_sceneGraph);
}

void World::update(sf::Time deltaTime)
{
  _worldView.move(0.f, _scrollSpeed * deltaTime.asSeconds());

  while (_commandQueue.size() > 0)
  {
    _sceneGraph.onCommand(_commandQueue.front(), deltaTime);
    _commandQueue.pop();
  }

  _sceneGraph.update(deltaTime);
}

CommandQueue &World::getCommandQueue()
{
  return _commandQueue;
}