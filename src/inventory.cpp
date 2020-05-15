#include <iostream>
#include <memory>
#include "inventory.hpp"

void Inventory::order_stock()
{
    int soda_stock = 20;
    int burger_stock = 15;

    // Order sodas
    for (int i = 0; i < soda_stock; i++)
    {
        std::shared_ptr<Soda> _soda = std::make_shared<Soda>();
        _soda->set_name("Soda");
        _soda->set_price(1.99);
        m_sodaInv.push_back(*_soda);
    }
    // Order burgers
    for (int i = 0; i < burger_stock; i++)
    {
        std::shared_ptr<Burger> _burger = std::make_shared<Burger>();
        _burger->set_name("Burger");
        _burger->set_price(3.99);
        m_burgerInv.push_back(*_burger);
    }

    // Output inventory
    //std::cout << "Soda stock: " << m_sodaInv.size() << std::endl;
    //std::cout << "Burger stock: " << m_burgerInv.size() << std::endl;
}

int Inventory::get_soda_count()
{
    return m_sodaInv.size();
}

int Inventory::get_burger_count()
{
    return m_burgerInv.size();
}

double Inventory::get_burger_price()
{
    return m_burgerInv.begin()->get_price();
}

double Inventory::get_soda_price()
{
    return m_sodaInv.begin()->get_price();
}

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}