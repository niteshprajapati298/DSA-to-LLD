#ifndef ORDER_H
#define ORDER_H
#include <iostream>
using namespace std;
#include <vector>
#include "MenuItem.h"
#include "Restaurant.h"
#include "User.h"
class Order {
    static int nextOrderId;
    int orderId;
    User* user;
    Restaurant* restaurant;
    vector<MenuItem> items;
    double totalCost;
  

};
int Order::nextOrderId = 0;
#endif