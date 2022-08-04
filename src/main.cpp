#include <iostream>

#include "Game.hpp"

int main()
{
  try
  {
    Game game;
    game.run();
    return 0;
  }
  catch (std::exception &e)
  {
    std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    return 1;
  }
}