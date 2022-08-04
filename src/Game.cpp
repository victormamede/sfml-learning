#include <iostream>
#include <string>
#include "Game.hpp"
#include "Aircraft.hpp"

const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game() : _window(sf::VideoMode(640, 480), "SFML Window"), _font(), _fpsCounter(), _world(_window)
{
  _window.setFramerateLimit(120);

  if (!_font.loadFromFile("assets/arial.ttf"))
  {
    std::cout << "Could not load font";
  }
  _fpsCounter.setFont(_font);
  _fpsCounter.setCharacterSize(12);
  _fpsCounter.setFillColor(sf::Color::White);
}

void Game::run()
{
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  while (_window.isOpen())
  {
    sf::Time deltaTime = clock.restart();
    timeSinceLastUpdate += deltaTime;
    while (timeSinceLastUpdate > TimePerFrame)
    {
      timeSinceLastUpdate -= TimePerFrame;
      // Fixed update here
    }

    processEvents();
    update(deltaTime);
    render();
  }
}

void Game::processEvents()
{
  sf::Event event;
  while (_window.pollEvent(event))
  {
    switch (event.type)
    {
    case sf::Event::Closed:
      _window.close();
      break;
    }
  }
}

void Game::update(sf::Time deltaTime)
{
  _world.update(deltaTime);
  _fpsCounter.setString("FPS: " + std::to_string(1.f / deltaTime.asSeconds()));
}

void Game::render()
{
  _window.clear();

  _world.draw();

  _window.setView(_window.getDefaultView());
  _window.draw(_fpsCounter);

  _window.display();
}
