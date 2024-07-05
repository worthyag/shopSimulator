#ifndef SHOP_HPP
#define SHOP_HPP

#include <string>
#include <vector>

class Shop {
  public:
    static void welcomeUser();
    static std::vector<std::vector<std::string>> buildItemsDB();
    static void displayItems();
    static void shopItems();
    static void checkout();
};

#endif // SHOP_HPP