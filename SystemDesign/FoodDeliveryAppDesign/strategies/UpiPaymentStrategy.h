#ifndef UPIPAYMENTSTRATEGY_H
#define UPIPAYMENTSTRATEGY_H
#include "PaymentStrategy.h"
class UpiPaymentStrategy : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Processing UPI payment of amount: $" << amount << endl;
        // Implement card payment logic here
        cout << "UPI payment successful." << endl;
        return true;
    }
};
#endif