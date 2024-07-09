#include "Shop.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <thread>
#include <chrono>
#include <limits>
#include <iomanip>

std::vector<std::tuple<int, std::string, int, double>> Shop::inventory {};
std::vector<std::vector<int>> Shop::basket {};

void Shop::welcomeUser() {
  std::cout << "----------------------------\n";
  std::cout << "Welcome to Worthy's Shop.\n";
  std::cout << "----------------------------\n";
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

  // Discard header.
  std::string discardHeader {};
  std::getline(ifs, discardHeader);

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

void Shop::buildInventory(const std::vector<std::vector<std::string>> itemsDB) {
  for (auto itemInfo : itemsDB) {
    if (itemInfo.size() < 4) {
      std::cerr << "Error: Invalid item data format in CSV." << std::endl;
      continue;
    }

    int id {};
    std::string name {};
    int quantity {};
    double price {};

    try {
      id = std::stoi(itemInfo[0]);          // Converting string to int for id.
      name = itemInfo[1];                   // Extracting name directly.
      quantity = std::stoi(itemInfo[2]);    // Converting string to int for quantity.
      price = std::stod(itemInfo[3]);       // Converting string to double for price.

    } catch (const std::exception& e) {
      std::cerr << "Error converting item data: " << e.what() << std::endl;
      continue;
    }

    std::tuple<int, std::string, int, double> itemTuple(id, name, quantity, price);
    inventory.push_back(itemTuple);
  }
}

void Shop::displayItems() {
  std::cout << "Items\n";
  std::cout << "======\n";

  std::vector<std::vector<std::string>> itemsDB {buildItemsDB()};

  // Displaying the header.
  std::cout << std::left << std::setw(5) << "ID"
            << std::left << std::setw(20) << "Item"
            << std::left << std::setw(10) << "Quantity"
            << std::left << "Price (£)\n";

  std::string line (45, '-');
  std::cout << line << std::endl;

  // Building the inventory from itemsDB.
  buildInventory(itemsDB);

  // Displaying items.
  // for (auto itemTuple : inventory) {
  //   std::cout << std::left << std::setw(5) << std::get<0>(itemTuple)         // id
  //             << std::left << std::setw(20) << std::get<1>(itemTuple)        // name
  //             << std::left << std::setw(10) << std::get<2>(itemTuple) << "£" // quantity
  //             << std::left << std::fixed << std::setprecision(2) <<          // price
  //             std::get<3>(itemTuple) << '\n';           
  //   sleep(175, 1);
  // }

  for (auto [id, name, quantity, price] : inventory) {
    std::cout << std::left << std::setw(5) << id
              << std::left << std::setw(20) << name
              << std::left << std::setw(10) << quantity << "£"
              << std::left << std::fixed << std::setprecision(2) << price << '\n';           
    sleep(175, 1);
  }

  std::cout << std::endl;
  sleep(1, 2);
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

    // Checking the inventory.
    checkInventory(itemID);

    char checkout {};
    std::cout << "Ready to checkout? ('y' or 'n') > ";
    std::cin >> checkout;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (checkout == 'y') break;
  } while (makePurchase);

  // std::vector<int> a {1, 2};
  // std::vector<int> b {3, 2};
  // std::vector<int> c {5, 1};

  /* TODO:
   Write the logic that checks whether there is stock for an item available
   If there is, add the item to the basket, and the number of it purchased.
   To checkout, calculate the cost using the basket.
   Pay using card.
  */

  // basket.push_back(a);
  // basket.push_back(b);
  // basket.push_back(c);
}

void Shop::checkInventory(const int itemID) {
  std::cout << "Checking the inventory\n";
}

void Shop::addToBasket() {

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

void Shop::sleep(const int duration, const int type) {
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