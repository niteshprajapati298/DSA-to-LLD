#include <iostream>
using namespace std;

class Burger
{
public:
    virtual ~Burger() = default;
    virtual void prepare() = 0;
};

class NormalBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "-----------------------------------" << endl;
        cout << "Preparing Normal Burger" << endl;
        cout << "Classic taste with fresh bun and patty." << endl;
        cout << "-----------------------------------" << endl;
    }
};

class StandardBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "-----------------------------------" << endl;
        cout << "Preparing Standard Burger" << endl;
        cout << "Fresh veggies, juicy patty, and tasty sauce." << endl;
        cout << "-----------------------------------" << endl;
    }
};

class PremiumBurger : public Burger
{
public:
    void prepare() override
    {
        cout << "-----------------------------------" << endl;
        cout << "Preparing Premium Burger" << endl;
        cout << "Chef special ingredients with rich flavor." << endl;
        cout << "-----------------------------------" << endl;
    }
};

class BurgerFactory
{
public:
    virtual Burger *createBurger(string type) = 0;
};
class SinghBurgerFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "Normal")
        {
            cout << "SinghBurgerFactory: Burger Type Selected: Normal" << endl;
            return new NormalBurger();
        }
        else if (type == "Standard")
        {
            cout << "SinghBurgerFactory: Burger Type Selected: Standard" << endl;
            return new StandardBurger();
        }
        else if (type == "Premium")
        {
            cout << "SinghBurgerFactory: Burger Type Selected: Premium" << endl;
            return new PremiumBurger();
        }
        else
        {
            cout << "SinghBurgerFactory: Invalid burger type selected!!!" << endl;
            return nullptr;
        }
    }
};

class KingBurgerFactory : public BurgerFactory
{
public:
    Burger *createBurger(string type) override
    {
        if (type == "Normal")
        {
            cout << "KingBurgerFactory: Burger Type Selected: Normal" << endl;
            return new NormalBurger();
        }
        else if (type == "Standard")
        {
            cout << "KingBurgerFactory: Burger Type Selected: Standard" << endl;
            return new StandardBurger();
        }
        else if (type == "Premium")
        {
            cout << "KingBurgerFactory: Burger Type Selected: Premium" << endl;
            return new PremiumBurger();
        }
        else
        {
            cout << "KingBurgerFactory: Invalid burger type selected!!!" << endl;
            return nullptr;
        }
    }
};

int main()
{
    string type = "Premium";
    KingBurgerFactory *kingBurgerFactory = new KingBurgerFactory();
    Burger *burger = kingBurgerFactory->createBurger(type);
    burger->prepare();
    return 0;
}