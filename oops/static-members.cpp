#include <iostream>
using namespace std;
class Customer
{
    string name;
    int account_number, balance;

public:
    static int total_customer;
    static int total_balance;
    Customer(string name, int account_number, int balance)
    {
        this->name = name;
        this->account_number = account_number;
        this->balance = balance;
        total_customer++;
        total_balance = total_balance + balance;
    };
    void deposit(int amount)
    {
        if (amount > 0)
        {
            balance = balance + amount;
            total_balance = total_balance + amount;
        }
    };
    void withdraw(int amount)
    {
        if (amount > 0 && this->balance >= amount)
        {
            balance =balance - amount;
            total_balance = total_balance - amount;
        }
    }
    void display()
    {
        cout << "Name - " << name << endl;
        cout << "AccountNumber - " << account_number << endl;
        cout << "Balance - " << balance << endl;
        // cout << "totalCustomer - " << total_customer << endl;
    }
    static void display_total()
    {
        cout << "totalCustomer - " << total_customer << endl;
        cout << "totalBalance - " << total_balance << endl;
    }
};
int Customer::total_customer = 0;
int Customer::total_balance = 0;

int main()
{
    Customer A1("Nitesh", 1, 1000);
    Customer A2("Vikash", 2, 5000);
    Customer A3("Mukesh", 3, 9000);
    Customer A4("Hemu", 4, 2000);
    Customer A5("Kajal", 5, 300);
    Customer A6("Shivani", 6, 300);
    Customer A7("Adani", 7, 400);
    // int Customer::total_balance = 0;
    A2.deposit(4000);
    A4.withdraw(100);
    A2.display();
    Customer::display_total();

    // A1.display_total();
}