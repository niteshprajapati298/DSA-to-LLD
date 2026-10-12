#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FileManager {
public:

    // Read an entire file
    void read(string fileName) {
        cout << "Reading file: " << fileName << endl;
    }

    // Read a specific number of lines
    void read(string fileName, int lines) {
        cout << "Reading first " << lines
             << " lines from " << fileName << endl;
    }

    // Read from a specific line to another line
    void read(string fileName, int startLine, int endLine) {
        cout << "Reading lines "
             << startLine << " to "
             << endLine << " from "
             << fileName << endl;
    }

    // Read selected line numbers
    void read(string fileName, vector<int> lineNumbers) {
        cout << "Reading selected lines from "
             << fileName << ": ";

        for (int line : lineNumbers)
            cout << line << " ";

        cout << endl;
    }

    // Read file in binary or text mode
    void read(string fileName, bool binaryMode) {
        if (binaryMode)
            cout << "Reading " << fileName << " in Binary Mode" << endl;
        else
            cout << "Reading " << fileName << " in Text Mode" << endl;
    }
};
class Calculator
{
public:
    int add(int a, int b)
    {
        cout << " Adding two integers ";
        return a + b;
    }
    // Function 2
    int add(int a, int b, int c)
    {
        cout << " Adding three integers ";
        return a + b + c;
    }
    // Function 3
    double add(double a, double b)
    {
        cout << " Adding two decimal numbers ";
        return a + b;
    }
};

class BankAccount {
private:
    double balance;

public:
    BankAccount() {
        balance = 1000;
    }

    // Deposit using cash
    void deposit(double amount) {
        balance += amount;
        cout << "Cash Deposited: ₹" << amount << endl;
    }

    // Deposit using cash with a description
    void deposit(double amount, const string& description) {
        balance += amount;
        cout << "Cash Deposited: ₹" << amount
             << " | Description: " << description << endl;
    }

    // Deposit using cheque
    void deposit(const string& chequeNumber, double amount) {
        balance += amount;
        cout << "Cheque No: " << chequeNumber
             << " | Amount: ₹" << amount << endl;
    }

    // Deposit in foreign currency
    void deposit(double amount, double exchangeRate) {
        double convertedAmount = amount * exchangeRate;
        balance += convertedAmount;

        cout << "Foreign Currency Deposited: "
             << amount << " USD"
             << " = ₹" << convertedAmount << endl;
    }

    void showBalance() {
        cout << "Current Balance: ₹" << balance << endl;
    }
};
int main()
{
    Calculator c1;
    cout << c1.add(1, 1) << endl;
    cout << c1.add(1, 2, 3) << endl;
    cout << c1.add(20.12, 12.98) << endl;
}