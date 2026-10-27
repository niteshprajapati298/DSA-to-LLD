#ifndef SCHEDULED_ORDER_FACTORY_H
#define SCHEDULED_ORDER_FACTORY_H

#include "OrderFactory.h"
#include "../models/Cart.h"
#include "../models/PickupOrder.h"
#include "../models/DeliveryOrder.h"
class ScheduledOrderFactory : public OrderFactory
{
public:
    Order *createOrder(User *user, Cart *cart, Restaurant *restaurant, const vector<MenuItem> &items, PaymentStrategy *paymentStrategy, const string &orderType)
    {
        Order *order = nullptr;
        if (orderType == "Pickup")
        {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        }
        else if (orderType == "Delivery")
        {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        }
        else
        {
            cout << "Invalid order type." << endl;
            return nullptr;
        }
        order->setUser(user);
        order->setTotal(cart->getTotalCost());
        order->setPaymentStrategy(paymentStrategy);
        order->setRestaurant(restaurant);
        order->setScheduled("Later");
        order->setItems(items);
        return order;
    }
};
#endif