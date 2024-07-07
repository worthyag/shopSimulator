#include "Shop.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <limits>

std::vector<std::vector<int>> Shop::basket {};

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
  char willBuy {};
  std::cout << "Would you like to make a purchase? ('y' or 'n') > ";
  std::cin >> willBuy;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  if (willBuy == 'n') return;

  bool makePurchase {true};

  do {
    int itemID {};
    std::cout << "What would you like to purchase?" << std::endl;
    std::cout << "Enter item id > ";
    std::cin >> itemID;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    char checkout {};
    std::cout << "Ready to checkout? ('y' or 'n') > ";
    std::cin >> checkout;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (checkout == 'y') break;
  } while (makePurchase);

  std::vector<int> a {1, 2};
  std::vector<int> b {3, 2};
  std::vector<int> c {5, 1};

  /* TODO:
   Write the logic that checks whether there is stock for an item available
   If there is, add the item to the basket, and the number of it purchased.
   To checkout, calculate the cost using the basket.
   Pay using card.
  */

  basket.push_back(a);
  basket.push_back(b);
  basket.push_back(c);
}

void Shop::checkout() {
  std::cout << "Checkout." << std::endl;

  for (auto item : basket) {
    for (auto token : item) {
      std::cout << token << " ";
    }
    std::cout << std::endl;
  }
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