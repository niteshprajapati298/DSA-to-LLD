#include <iostream>
#include <string>
using namespace std;

class Burger
{   public :
    virtual void prepare() = 0;
    virtual ~Burger() {};
};
class BasicBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Basic Burger " << endl;
    };
};
class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Standard Burger " << endl;
    };
};
class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "Preparing Premium Burger " << endl;
    };
};
class BurgerFactory
{
public:
    Burger *createBurger(string& type)
    {
        if (type == "BASIC")
        {
            return new BasicBurger();
        }
        if (type == "STANDARD")
        {
            return new StandardBurger();
        }
        if (type == "PREMIUM")
        {
            return new PremiumBurger();
        }
        else
            return nullptr;
    }
};


int main()
{
    string type = "BASIC";
    BurgerFactory* myBurgerFactory = new BurgerFactory();
    Burger * burger = myBurgerFactory->createBurger(type);
    burger->prepare();
}