#include "Shop.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>

void Shop::welcomeUser() {
  std::cout << "----------------------------" << std::endl;
  std::cout << "Welcome to Worthy's Shop." << std::endl;
  std::cout << "----------------------------" << std::endl;
  std::cout << std::endl;

  sleep(1);

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
  std::cout << "Items." << std::endl;
  std::cout << "========" << std::endl;

  std::vector<std::vector<std::string>> itemsDB {buildItemsDB()};

  // Testing.
  for (auto itemInfo : itemsDB) {
    for (auto token : itemInfo) {
      std::cout << token << " ";
      sleep(10, 1);
    }
    std::cout << std::endl;
    sleep(1, 2);
  }

  std::cout << std::endl;
}

void Shop::shopItems() {
  // while (true) {

  // }

  std::cout << "Shop." << std::endl;
}

void Shop::checkout() {
  std::cout << "Checkout." << std::endl;
}

void Shop::sleep(int duration, int type) {
  // Adding timeout to allow users to properly digest the information.

  switch (type) {
    case 1:
      std::this_thread::sleep_for(std::chrono::milliseconds(duration));
      break;
    case 2:
      std::this_thread::sleep_for(std::chrono::seconds(duration));
      break;
    case 3:
      std::this_thread::sleep_for(std::chrono::minutes(duration));
      break;
    default:
      std::cerr << "Type doesn't exist!" << std::endl;
  }
}