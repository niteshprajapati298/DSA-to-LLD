#ifndef PaymentStrategy_H
#define PaymentStrategy_H
#include <iostream>
using namespace std;
class PaymentStrategy
{
public:
    virtual bool pay(double amount) = 0;
    virtual ~PaymentStrategy() {}
};
#endif