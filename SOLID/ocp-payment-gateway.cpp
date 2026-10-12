#include <iostream>
#include <string>
using namespace std;

// OCP: Open/Closed Principle
// The checkout logic is open for extension but closed for modification.
// New payment methods can be added by creating new subclasses.
//
// Bad example idea:
// A CheckoutProcessor with many if/else statements for CreditCard, PayPal, UPI,
// and Stripe. Adding a new gateway means changing the same class again and again.
//
// Example:
// class CheckoutProcessor {
// public:
//     void pay(string method, double amount) {
//         if (method == "card") { /* ... */ }
//         else if (method == "paypal") { /* ... */ }
//     }
// };

class PaymentGateway {
public:
    virtual ~PaymentGateway() = default;
    virtual void processPayment(double amount) = 0;
};

class CreditCardGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Charging credit card: " << amount << endl;
    }
};

class PayPalGateway : public PaymentGateway {
public:
    void processPayment(double amount) override {
        cout << "Charging PayPal account: " << amount << endl;
    }
};

class CheckoutProcessor {
private:
    PaymentGateway& gateway;

public:
    explicit CheckoutProcessor(PaymentGateway& paymentGateway)
        : gateway(paymentGateway) {}

    void pay(double amount) {
        gateway.processPayment(amount);
    }
};

int main() {
    CreditCardGateway cardGateway;
    CheckoutProcessor checkout(cardGateway);
    checkout.pay(1500.00);

    PayPalGateway paypalGateway;
    CheckoutProcessor paypalCheckout(paypalGateway);
    paypalCheckout.pay(900.00);

    return 0;
}
