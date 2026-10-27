#ifndef CART_H
#define CART_H
#include <iostream>
using namespace std;
#include <vector>
#include "MenuItem.h"
#include "Restaurant.h"
class Cart
{
    vector<MenuItem> items;
    Restaurant *restaurant;

public:
    Cart()
    {
        restaurant = nullptr;
    }
    void addItem(const MenuItem &item, Restaurant *restaurant)
    {
        if (this->restaurant == nullptr)
        {
            this->restaurant = restaurant;
        }
        else if (this->restaurant != restaurant)
        {
            cout << "Cannot add items from different restaurants." << endl;
            return;
        }
        items.push_back(item);
    }
    double getTotalCost()
    {
        double total = 0;
        for (auto &item : items)
        {
            total += item.getPrice();
        }
        return total;
    }
    bool isEmpty()
    {
        return items.empty();
    }
    void clear()
    {
        items.clear();
        restaurant = nullptr;
    }
    void setRestaurant(Restaurant *restaurant)
    {
        this->restaurant = restaurant;
    }
    Restaurant *getRestaurant() const
    {
        return restaurant;
    }
    const vector<MenuItem> &getItems() const
    {
        return items;
    }
};

#endif
