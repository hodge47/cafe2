#ifndef ITEM_H
#define ITEM_H
#include <string>

class Item
{
protected:
    std::string m_name = "null";
    double m_price = 0.00;

public:
    void set_name(std::string _name);
    std::string get_name();
    void set_price(double _price);
    double get_price();
    Item(/* args */);
    ~Item();
};

#endif