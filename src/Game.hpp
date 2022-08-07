#pragma once

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "World.hpp"
#include "Player.hpp"

class Game
{
public:
  Game();
  void run();

private:
  sf::RenderWindow _window;
  sf::Font _font;
  sf::Text _fpsCounter;
  World _world;
  Player _player;

  void processEvents();
  void update(sf::Time deltaTime);
  void render();
};