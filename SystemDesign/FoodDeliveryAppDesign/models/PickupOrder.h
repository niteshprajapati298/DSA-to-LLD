#ifndef PICKUPORDER_H
#define PICKUPORDER_H
#include "Order.h"
class PickupOrder : public Order {
    string restaurantAddress;
public:
    PickupOrder() {
        restaurantAddress = "";
    };
    string getRestaurantAddress() const {
        return restaurantAddress;
    }
    void setRestaurantAddress(const string& address) {
        restaurantAddress = address;
    }
    string getType() const override {
        return "Pickup";
    }
};
#endif