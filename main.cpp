#include <iostream>

#include "StoreManager.cpp"
#include "Products.hpp"
#include "macro.h"
#include "Player.hpp"

int main() {
  Fruits fruits;
  Fruits::Apple apple;
  Fruits::Pear pear;
  
  Meat meat;
  Meat::Beef beef;
  Meat::Chicken chicken;

  Player player;
  
  std::string escKey;
  bool running = true;

  while (running) {
    
    // do stuff

    std::cin >> escKey;
    
    purchasing();
    
        
    if (escKey == "q") {
      exit(ESCKEY);
    }
  }
}
