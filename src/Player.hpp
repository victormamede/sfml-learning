#pragma once
#include <SFML/Window.hpp>
#include "Command.hpp"

class Player
{
public:
  void handleEvent(const sf::Event &event, CommandQueue &commands);
  void handleRealtimeInput(CommandQueue &commands);
};