#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H
#include "Order.h"
class DeliveryOrder : public Order {
public:
    string userAddress;
    DeliveryOrder(){
        userAddress = "";
    };
    string getType() const override {
        return "Delivery";
    }
    void setUserAddress(const string& address) {
        userAddress = address;
    }
    const string& getUserAddress() const {
        return userAddress;
    }
};
#endif