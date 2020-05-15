#include <iostream>
#include <memory>
#include "fib.hpp"
#include "log.hpp"
#include "cafe.hpp"
#include "item.hpp"
#include "inventory.hpp"

int main()
{
  Cafe *cafe = new Cafe();
  cafe->get_user_input();
  delete cafe;
  // Inventory *inv = new Inventory();
  // inv->order_stock();
  // delete inv;
  // Log::LogLine("This is a test message");
  //std::cout << "Hello, World!" << std::endl;
  // Item *newItem = new Item();
  // newItem->set_name("Soda");
  // newItem->set_price(1.99);
  // std::string name = newItem->get_name();
  // double price = newItem->get_price();
  // std::cout << "1 " << name << " is $" << price << std::endl;
  // delete newItem;
  return 0;
}
