#ifndef ORDER_H
#define ORDER_H
#include <iostream>
using namespace std;
#include <vector>
#include "MenuItem.h"
#include "Restaurant.h"
#include "User.h"
#include "../strategies/PaymentStrategy.h"
class Order
{
    static int nextOrderId;
    int orderId;
    User *user;
    Restaurant *restaurant;
    vector<MenuItem> items;
    PaymentStrategy *paymentStrategy;
    double totalCost;
    string scheduled;

public:
    Order()
    {
        user = nullptr;
        restaurant = nullptr;
        paymentStrategy = nullptr;
        totalCost = 0;
        scheduled = "";
        this->orderId = ++nextOrderId;
    }
    virtual ~Order()
    {
        delete paymentStrategy;
        cout << "Order " << orderId << " destroyed." << endl;
    }
    bool processPayment(PaymentStrategy *strategy)
    {
        if (strategy == nullptr)
        {
            cout << "Payment strategy is not set." << endl;
            return false;
        }
        paymentStrategy = strategy;
        totalCost = calculateTotalCost();
        return paymentStrategy->pay(totalCost);
    }
    double calculateTotalCost()
    {
        double total = 0;
        for (auto &item : items)
        {
            total += item.getPrice();
        }
        return total;
    }
    void setUser(User *user)
    {
        this->user = user;
    }

    void setRestaurant(Restaurant *restaurant)
    {
        this->restaurant = restaurant;
    }
    Restaurant *getRestaurant() const
    {
        return restaurant;
    }
    virtual string getType() const = 0;
    User *getUser() const
    {
        return user;
    }
    void setItems(const vector<MenuItem> &items)
    {
        this->items = items;
    }
    const vector<MenuItem> &getItems() const
    {
        return items;
    }
    void setPaymentStrategy(PaymentStrategy *strategy)
    {
        this->paymentStrategy = strategy;
    }
    void setScheduled(const string &scheduled)
    {
        this->scheduled = scheduled;
    }
    void setTotal(double total)
    {
        this->totalCost = total;
    }
};
int Order::nextOrderId = 0;
#endif