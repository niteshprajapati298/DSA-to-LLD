#include <iostream>
#include <string>
using namespace std;

// LSP: Liskov Substitution Principle
// Derived payment classes can replace the base payment type without breaking behavior.
//
// Bad example idea:
// A subclass that throws an exception or behaves differently when used as a payment method.
// That breaks the expectation of the base class contract.
//
// Example:
// class CashPayment : public PaymentMethod {
// public:
//     void pay(double amount) override { /* ... */ }
//     void refund(double amount) override { throw runtime_error("Not supported"); }
// };

class PaymentMethod {
public:
    virtual ~PaymentMethod() = default;

    // Return type rule: derived classes must keep the same contract.
    // Exception rule: these methods should not throw unexpectedly for normal use.
    virtual bool pay(double amount) = 0;
    virtual bool refund(double amount) = 0;
};

class CreditCardPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        cout << "Credit card charged: " << amount << endl;
        return true;
    }

    bool refund(double amount) override {
        cout << "Credit card refund: " << amount << endl;
        return true;
    }
};

class PayPalPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        cout << "PayPal charged: " << amount << endl;
        return true;
    }

    bool refund(double amount) override {
        cout << "PayPal refund: " << amount << endl;
        return true;
    }
};

class CashPayment : public PaymentMethod {
public:
    bool pay(double amount) override {
        cout << "Cash payment accepted: " << amount << endl;
        return true;
    }

    bool refund(double amount) override {
        cout << "Cash refund processed: " << amount << endl;
        return true;
    }
};

class PaymentController {
private:
    PaymentMethod& paymentMethod;

public:
    explicit PaymentController(PaymentMethod& method)
        : paymentMethod(method) {}

    bool charge(double amount) {
        return paymentMethod.pay(amount);
    }

    bool cancel(double amount) {
        return paymentMethod.refund(amount);
    }
};

int main() {
    CreditCardPayment card;
    PaymentController cardController(card);
    cout << "Card charge success: " << cardController.charge(300.0) << endl;
    cout << "Card refund success: " << cardController.cancel(100.0) << endl;

    PayPalPayment paypal;
    PaymentController paypalController(paypal);
    cout << "PayPal charge success: " << paypalController.charge(250.0) << endl;

    CashPayment cash;
    PaymentController cashController(cash);
    cout << "Cash refund success: " << cashController.cancel(50.0) << endl;

    return 0;
}
