#ifndef CardPaymentStrategy_H
#define CardPaymentStrategy_H
#include "PaymentStrategy.h"
class CardPaymentStrategy : public PaymentStrategy {
public:
    bool pay(double amount) override {
        cout << "Processing card payment of amount: $" << amount << endl;
        // Implement card payment logic here
        cout << "Card payment successful." << endl;
        return true;
    }
};
#endif