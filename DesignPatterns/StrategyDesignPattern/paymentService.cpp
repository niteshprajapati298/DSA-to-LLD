#include <iostream>
using namespace std;

class PaymentStrategy
{
public:
    virtual ~PaymentStrategy() = default;
    virtual void pay() = 0;
};

class PaymentService
{
private:
    PaymentStrategy* strategy;

public:
    PaymentService(PaymentStrategy* strategy) : strategy(strategy) {}

    void processPayment()
    {
        strategy->pay();
    }
    void setStrategy(PaymentStrategy* strategy) {
        this->strategy = strategy; 
    }
};

class CreditCardPaymentStrategy : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Payment done via Credit Card" << endl;
    }
};

class UPIPaymentStrategy : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Payment done via UPI" << endl;
    }
};

class NetBankingPaymentStrategy : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Payment done via Net Banking" << endl;
    }
};

class RazorpayPaymentStrategy : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Payment done via Razorpay" << endl;
    }
};

int main()
{
    CreditCardPaymentStrategy creditCard;
    UPIPaymentStrategy upi;
    NetBankingPaymentStrategy netBanking;
    RazorpayPaymentStrategy razorpay;

    PaymentService service(&upi);
    service.processPayment();
    service.setStrategy(&creditCard);
    service.processPayment(); 
  
   

    return 0;
}