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
    static std::vector<std::vector<int>> basket;
    
    static std::vector<std::vector<std::string>> buildItemsDB();
    static void buildInventory(std::vector<std::vector<std::string>> itemsDB);
    static void displayItems();
    static void sleep(int duration, int type = 2);
    static void checkInventory(int itemID);
    static void addToBasket();
};

#endif // SHOP_HPP