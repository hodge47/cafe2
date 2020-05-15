#include "item.hpp"

void Item::set_name(std::string _name)
{
    m_name = _name;
}

std::string Item::get_name()
{
    return m_name;
}

void Item::set_price(double _price)
{
    m_price = _price;
}

double Item::get_price()
{
    return m_price;
}

Item::Item()
{
}

Item::~Item()
{
}