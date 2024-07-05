#include "Shop.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

void Shop::welcomeUser() {
  std::cout << "Welcome to Worthy's Shop." << std::endl;

  // Display items.
  displayItems();
}

std::vector<std::vector<std::string>> Shop::buildItemsDB() {
  std::ifstream ifs {};
  std::string itemInfoStr {};

  // Building the items DB.
  std::vector<std::vector<std::string>> itemsDB {};
  
  ifs.open("../items/shopItems.csv");

  while (std::getline(ifs, itemInfoStr)) {
    std::vector<std::string> itemInfo {};
    std::stringstream ss {itemInfoStr};
    std::string value {};

    while (std::getline(ss, value, ',')) {
      itemInfo.push_back(value);
    }

    itemsDB.push_back(itemInfo);
  }

  ifs.close();
  return itemsDB;
}

void Shop::displayItems() {
  std::cout << "Display items." << std::endl;

  std::vector<std::vector<std::string>> itemsDB {buildItemsDB()};

  // Testing.
  for (auto itemInfo : itemsDB) {
    for (auto token : itemInfo) {
      std::cout << token << " ";
    }
    std::cout << std::endl;
  }
}

void Shop::shopItems() {
  // while (true) {

  // }

  std::cout << "Shop." << std::endl;
}

void Shop::checkout() {
  std::cout << "Checkout." << std::endl;
}