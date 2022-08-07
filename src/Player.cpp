#include <SFML/System.hpp>
#include <iostream>
#include "Player.hpp"
#include "Aircraft.hpp"
#include "derivedAction.hpp"

void Player::handleRealtimeInput(CommandQueue &commands)
{
  const float playerSpeed = 30.f;

  Command moveCommand;

  sf::Vector2f moveDir;
  moveDir.x = sf::Keyboard::isKeyPressed(sf::Keyboard::Right) - sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
  moveDir.y = sf::Keyboard::isKeyPressed(sf::Keyboard::Down) - sf::Keyboard::isKeyPressed(sf::Keyboard::Up);

  moveCommand.category = (unsigned int)Category::Type::PlayerAircraft;
  moveCommand.action = derivedAction<Aircraft>([moveDir](Aircraft &aircraft, sf::Time deltaTime)
                                               { aircraft.accelerate(moveDir); });

  commands.push(moveCommand);
}

void Player::handleEvent(const sf::Event &event, CommandQueue &commands)
{

  if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::P)
  {
    Command output;
    output.category = (unsigned int)Category::Type::PlayerAircraft;
    output.action = [](SceneNode &s, sf::Time)
    {
      std::cout << s.getPosition().x << ","
                << s.getPosition().y << "\n";
    };
    commands.push(output);
  }
}