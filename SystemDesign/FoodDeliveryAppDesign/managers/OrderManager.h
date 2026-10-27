#ifndef ORDERMANAGER_H
#define ORDERMANAGER_H
#include <iostream>
using namespace std;
#include <vector>
#include "Order.h"
class OrderManager
{
    static OrderManager *instance;
    vector<Order *> orders;

    static OrderManager *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new OrderManager();
        }
        return instance;
    }
    public:
    void addOrder(Order *order)
    {
        orders.push_back(order);
    }
    const vector<Order *> &getOrders() const
    {
        return orders;
    }
    void listOrders(User *user, vector<Order *> &userOrders)
    {
        for (auto order : orders)
        {
            if (order->getUser() == user)
            {
                userOrders.push_back(order);
            }
        }
    }
};
OrderManager *OrderManager::instance = nullptr;
#endif