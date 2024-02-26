#ifndef PRODUCTS_H
#define PRODUCTS_H

#include <iostream>
#include <string>

#include "macro.h"

enum Brands {
  DeliFresh,   // 0
  FlavorBurst, // 1
  CrunchMunch  // 2
};

struct Products {

  int totalProducts = 0;

  static const int basePrice = 5;
  static const float baseWeight;
  static const int baseProducts = 5;

  static const int fruitPrice;
  static const int meatPrice;

  static const float fruitWeight;
  static const float meatWeight;

  static const int numFruit = baseProducts;
  static const int numMeat = baseProducts;

  Products() = default;
};

const float Products::baseWeight = 0.20;
const int Products::fruitPrice = Products::basePrice + 3;
const int Products::meatPrice = Products::basePrice + 0.33;
const float Products::fruitWeight = Products::baseWeight + 0.3;
const float Products::meatWeight = Products::baseWeight + 0.10;

struct Fruits : Products {
  std::string fruitProductsList[FRUIT_PRODUCT_SIZE] = {"Apple", "Pear"};
  struct Apple {
    int price;
    float weight;
    int amount;
    std::string name; //  = Products::fruitProductsList[0];

    Apple()
        : price(Products::fruitPrice), weight(Products::fruitWeight),
          amount(Products::numFruit) {
      name = "Apple";
    }

    void printValues() {
      std::cout << "Price: " << price << '\n';
      std::cout << "Weight: " << weight << '\n';
      std::cout << "Amount: " << amount << '\n';
    }

    int requestCheck(int request) {
      if (request > amount) {
        std::cout << "You have requested more than the total amount of " << name
                  << std::endl;
      } else {
        return 0;
      }
      return 0;
    }
  };

  struct Pear {
    int price;
    int weight;
    int amount;
    std::string name;

    Pear()
        : price(Products::fruitPrice), weight(Products::fruitWeight),
          amount(Products::numFruit) {
      name = "Pear";
    }

    void printValues() {
      std::cout << "Price: " << price << '\n';
      std::cout << "Weight: " << weight << '\n';
      std::cout << "Amount: " << amount << '\n';
    }
  };
};

struct Meat : Products {
  std::string meatProductsList[MEAT_PRODUCT_SIZE] = {"Beef", "Chicken"};
  struct Beef {
    int price;
    float weight;
    int amount;
    std::string name;

    Beef()
        : price(Products::meatPrice), weight(Products::meatWeight),
          amount(Products::numMeat) {
      name = "Beef";
    }

    void printValues() {
      std::cout << "Price: " << price << '\n';
      std::cout << "Weight: " << weight << '\n';
      std::cout << "Amount: " << amount << '\n';
    }

    int requestCheck(int request) {
      if (request > amount) {
        std::cout << "You have requested more than the total amount of " << name
                  << std::endl;
      } else {
        return 0;
      }
      return 0;
    }
  };

  struct Chicken {
    int price;
    int weight;
    int amount;
    std::string name;

    Chicken()
        : price(Products::meatPrice), weight(Products::meatWeight),
          amount(Products::numMeat) {
      name = "Chicken";
    }

    void printValues() {
      std::cout << "Price: " << price << '\n';
      std::cout << "Weight: " << weight << '\n';
      std::cout << "Amount: " << amount << '\n';
    }

    int requestCheck(int request) {
      if (request > amount) {
        std::cout << "You have requested more than the total amount of " << name
                  << '\n';
      } else {
        return 0;
      }

      return 0;
    }
  };
};
#endif
