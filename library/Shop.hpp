#ifndef SHOP_HPP
#define SHOP_HPP

#include <string>
#include <vector>
#include <tuple>

class Shop {
  public:
    static void welcomeUser();
    static void shopItems();
    static void checkout();
  
  private:
    static std::vector<std::tuple<int, std::string, int, double>> inventory;
    // static std::vector<std::vector<int>> basket;
    static std::vector<std::string> basket;
    static double total;
    
    static std::vector<std::vector<std::string>> buildItemsDB();
    static void buildInventory(const std::vector<std::vector<std::string>> itemsDB);
    static void displayItems();
    static void sleep(const int duration, const int type = 2);
    static void checkInventory(const int itemID);
    static bool addToBasket(const std::string item, const double itemPrice);
};

#endif // SHOP_HPP