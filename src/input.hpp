#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <string>

class Input
{
private:
    /* data */
public:
    static void get_input(int _itemSelection, int _itemAmount);
    static void get_input(std::string _itemSelection, std::string _itemAmount);
    Input(/* args */);
    ~Input();
};

#endif