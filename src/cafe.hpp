#ifndef CAFE_H
#define CAFE_H
#include <iostream>
#include <string>
#include "inventory.hpp"
class Cafe
{
private:
    Inventory *m_inventory = nullptr;
    std::string m_item = "";
    int m_item_amount = 0;
    double m_total_cost = 0;
    double m_payment = 0;
    double m_change_due = 0;

public:
    Inventory get_inventory();
    void list_inventory_stock();
    void get_user_input();
    void check_availablility();
    void redo();
    double calculate_cost();
    void get_user_payment();
    void calculate_payment();
    Cafe(/* args */);
    ~Cafe();
};

#endif