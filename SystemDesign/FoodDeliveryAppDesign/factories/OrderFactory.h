#ifndef ORDERFACTORY_H
#define ORDERFACTORY_H
#include "Order.h"

class OrderFactory {
public:
    virtual Order* createOrder(User *user ,Cart *cart , Restaurant *restaurant , const vector<MenuItem>& items , PaymentStrategy *paymentStrategy , const string &orderType) = 0;
    virtual ~OrderFactory() {}
};
#endif