#ifndef NOTIFICATION_SERVICE_H
#define NOTIFICATION_SERVICE_H
#include <iostream>
#include "../models/Order.h"
class NotificationService
{
public:
    static void notify(Order *order)
    {
        if (order == nullptr)
        {
            cerr << "Notification failed: order is null." << endl;
            return;
        }

        User *user = order->getUser();
        if (user == nullptr)
        {
            cerr << "Notification failed: order has no user." << endl;
            return;
        }

        Restaurant *restaurant = order->getRestaurant();
        cout << "[Notification] User: " << user->getName()
             << " | Order type: " << order->getType()
             << " | Restaurant: " << (restaurant != nullptr ? restaurant->getName() : "not set")
             << " | Items: " << order->getItems().size() << endl;
    }
};
#endif
