#ifndef INVENTORY_H
#define INVENTORY_H
#include <string>
#include <vector>
#include "soda.hpp"
#include "burger.hpp"

class Inventory
{
private:
    std::vector<Soda> m_sodaInv;
    std::vector<Burger> m_burgerInv;

public:
    void order_stock();
    int get_soda_count();
    int get_burger_count();
    double get_burger_price();
    double get_soda_price();
    Inventory(/* args */);
    ~Inventory();
};

#endif