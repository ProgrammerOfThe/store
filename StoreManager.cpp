#include <cctype>
#include <iostream>

#include "Player.hpp"
#include "Products.hpp"

Fruits fruits;
Meat meat;
Player player;

Fruits::Apple apple;
Fruits::Pear pear;

Meat::Beef beef;
Meat::Chicken chicken;

void printTables() {

  /*
    apple.printValues();
    pear.printValues();

    beef.printValues();
    chicken.printValues();
  */

  for (int k = 0; k < FRUIT_PRODUCT_SIZE; k++) {
    for (int n = 0; n < MEAT_PRODUCT_SIZE; n++) {
      std::cout << fruits.fruitProductsList[k] << '\n';
      std::cout << meat.meatProductsList[n] << '\n';

      break;
    }
  }
}

int purchasing() {
  std::string escKey;

  std::string selectItem; // choose the item
  std::string selectedItem;
  std::string fileName = "test.txt";
  std::string dataDesc = "Selected Item:";
  int selectedItemCost;
  
  char buyItem;

  while (true) {
    std::cin >> escKey;

    printTables();
    // work on the code to purchase items
    std::cout << ">> ";
    std::cin >> selectItem;

    if (selectItem == fruits.fruitProductsList[0]) {
      apple.printValues();
      selectedItem = fruits.fruitProductsList[0];
      selectedItemCost = apple.price;
    } else if (selectItem == fruits.fruitProductsList[1]) {
      pear.printValues();
      selectedItem = fruits.fruitProductsList[1];
      selectedItemCost = pear.price;
    } else if (selectItem == meat.meatProductsList[0]) {
      beef.printValues();
      selectedItem = meat.meatProductsList[0];
      selectedItemCost = beef.price;
    } else if (selectItem == meat.meatProductsList[1]) {
      chicken.printValues();
      selectedItem = meat.meatProductsList[1];
      selectedItemCost = chicken.price;
    }else{
      std::cout << "invalid input";
      break;
    }

    std::cout << "do you wish to buy >> " << selectedItem << '\n';
    std::cin >> buyItem;

    if (buyItem == 'y') {
      player.purchase(selectedItem, selectedItemCost);
      player.saveData(fileName, selectedItem, dataDesc);
    }else if (buyItem == 'n'){
      return 0;
    }

    if (escKey == "q") {
      return ESCKEY;
    }
  }

  return 0;
}
