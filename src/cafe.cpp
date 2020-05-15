#include "cafe.hpp"

Cafe::Cafe()
{
    m_inventory = new Inventory();
    m_inventory->order_stock();
    // Tell the customer hello
    std::cout << "Hello, welcome to the cafe. Here is a list of our current inventory." << std::endl;
    this->list_inventory_stock();
}

Cafe::~Cafe()
{
    delete m_inventory;
}

Inventory Cafe::get_inventory()
{
    return *m_inventory;
}

void Cafe::list_inventory_stock()
{
    std::cout << "\n----------------------------------------" << std::endl;
    std::cout << "What would you like today?" << std::endl;
    std::cout << "----------------------------------------" << std::endl;
    std::cout << "Burger          " << m_inventory->get_soda_count() << std::endl;
    std::cout << "Soda            " << m_inventory->get_burger_count() << std::endl;
    std::cout << "----------------------------------------" << std::endl;
}

void Cafe::get_user_input()
{
    std::cin >> this->m_item >> this->m_item_amount;
    //std::cout << this->m_item << this->m_item_amount << std::endl;
    std::cout << std::endl;
    this->check_availablility();
}

void Cafe::check_availablility()
{
    // Burger
    if (this->m_item == "Burger" || this->m_item == "burger")
    {
        if (this->m_item_amount < m_inventory->get_burger_count())
        {
            m_total_cost = this->calculate_cost();
            std::cout << "Your total: " << m_total_cost << std::endl;
        }
        else
        {
            std::cout << "I'm sorry, we don't have that many burgers in our inventory." << std::endl;
            this->redo();
            return;
        }
    }
    // Soda
    // Burger
    else if (this->m_item == "Soda" || this->m_item == "soda")
    {
        if (this->m_item_amount < m_inventory->get_soda_count())
        {
            this->m_total_cost = this->calculate_cost();
            std::cout << "Your total: " << m_total_cost << std::endl;
        }
        else
        {
            std::cout << "I'm sorry, we don't have that many sodas in our inventory." << std::endl;
            this->redo();
            return;
        }
    }
    else
    {
        std::cout << "That item doesn't exist!" << std::endl;
        this->redo();
        return;
    }
    // Get the payment
    this->get_user_payment();
}

void Cafe::redo()
{
    this->list_inventory_stock();
    this->get_user_input();
}

double Cafe::calculate_cost()
{
    double cost = 0;
    double cost_multiplier = (this->m_item_amount > 1) ? this->m_item_amount : 1;

    if (this->m_item == "Burger" || this->m_item == "burger")
    {
        std::cout << "Burger price: " << m_inventory->get_burger_price() << std::endl;
        cost = m_inventory->get_burger_price() * cost_multiplier;
    }
    // Soda
    // Burger
    else if (this->m_item == "Soda" || this->m_item == "soda")
    {
        cost = m_inventory->get_soda_price() * cost_multiplier;
    }
    else
    {
        std::cout << "\nError" << std::endl;
        return 0;
    }

    return cost;
}

void Cafe::get_user_payment()
{
    std::cout << "\nWe accept 5's, 10's, 20's, 50's. Please hand the cashier your payment below." << std::endl;
    std::cin >> this->m_payment;
    this->calculate_payment();
}

void Cafe::calculate_payment()
{
    bool enter_approved_bill = false;
    switch ((int)m_payment)
    {
    case 5:
        enter_approved_bill = true;
        break;
    case 10:
        enter_approved_bill = true;
        break;
    case 20:
        enter_approved_bill = true;
        break;
    case 50:
        enter_approved_bill = true;
        break;
    default:
        enter_approved_bill = false;
        break;
    }
    if (enter_approved_bill)
    {
        if (this->m_payment >= this->m_total_cost)
        {
            std::cout << m_payment << " " << m_total_cost << std::endl;
            this->m_change_due = this->m_payment - this->m_total_cost;
            std::cout << "\nYour change is " << this->m_change_due << ". Thank you for your purchase!" << std::endl;
            this->redo();
            return;
        }
        else
        {
            std::cout << "You did not give enough money for the purchase. Try again." << std::endl;
            this->get_user_payment();
            return;
        }
    }
    else
    {
        std::cout << "\nYou did not enter an approved bill.\n"
                  << std::endl;
        this->get_user_payment();
        return;
    }
}