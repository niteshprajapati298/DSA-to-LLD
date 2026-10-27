#ifndef NOWORDERFACTORY_H
#define NOWORDERFACTORY_H
#include "OrderFactory.h"
#include "../models/PickupOrder.h"
#include "../models/DeliveryOrder.h"
#include "../strategies/PaymentStrategy.h"
class NowOrderFactory : public OrderFactory {
public:
    Order* createOrder(User *user ,Cart *cart , Restaurant *restaurant , const vector<MenuItem>& items , PaymentStrategy *paymentStrategy , const string &orderType) override {
        Order* order = nullptr;
        if (orderType == "Pickup") {
            auto pickupOrder = new PickupOrder();
            pickupOrder->setRestaurantAddress(restaurant->getLocation());
            order = pickupOrder;
        } else if (orderType == "Delivery") {
            auto deliveryOrder = new DeliveryOrder();
            deliveryOrder->setUserAddress(user->getAddress());
            order = deliveryOrder;
        } else {
            cout << "Invalid order type." << endl;
            return nullptr;
        }
        order->setUser(user);
        order->setRestaurant(restaurant);
        order->setItems(items);
        order->setPaymentStrategy(paymentStrategy);
        order->setScheduled("Now");
        order->setTotal(cart->getTotalCost()); // Set the total cost based on the cart
         // Set the scheduled time to "Now"
        return order;
    }
};
#endif