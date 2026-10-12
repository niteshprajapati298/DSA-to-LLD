#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

/*
Liskov Substitution Principle (LSP) - Advanced Example

This file explains several important design ideas in simple interview terms:

1. History Constraint
   - A derived class must not break the order of operations expected by the base class.
   - If base class says: "first validate, then update", the derived class must follow that too.

2. Invariant
   - Some rules must always remain true for all objects of the hierarchy.
   - Example: an account balance must never become negative.

3. Precondition
   - A method should require valid inputs before it starts its work.
   - Example: withdrawal amount must be positive and not more than balance.

4. Immutable Class / Immutable Method Idea
   - An immutable object should not change its internal state after creation.
   - In practice, this means methods should not modify the object unless the design clearly allows it.

5. Exception Handling
   - A derived class should not throw unexpected exceptions for normal operations.
   - If base class promises a valid result, derived classes should also return a valid result.

Why this matters:
   If a subclass behaves differently, then code using the base type can fail unexpectedly.
*/

class Account {
protected:
    double balance;

public:
    explicit Account(double initialBalance) : balance(initialBalance) {
        if (initialBalance < 0) {
            throw invalid_argument("Initial balance cannot be negative");
        }
    }

    // Invariant: balance must always remain non-negative.
    virtual bool withdraw(double amount) {
        // Precondition: caller must provide a valid amount.
        if (amount <= 0) {
            throw invalid_argument("Withdrawal amount must be positive");
        }

        if (amount > balance) {
            throw runtime_error("Insufficient balance");
        }

        balance -= amount;
        return true;
    }

    virtual bool deposit(double amount) {
        // Precondition: deposit amount must be positive.
        if (amount <= 0) {
            throw invalid_argument("Deposit amount must be positive");
        }

        balance += amount;
        return true;
    }

    double getBalance() const {
        return balance;
    }
};

class ImmutableUserProfile {
private:
    string name;
    int age;

public:
    ImmutableUserProfile(string userName, int userAge) : name(std::move(userName)), age(userAge) {
        if (userAge < 0) {
            throw invalid_argument("Age cannot be negative");
        }
    }

    // Immutable class idea: once created, it cannot be changed.
    string getName() const { return name; }
    int getAge() const { return age; }
};

class SavingsAccount : public Account {
public:
    explicit SavingsAccount(double initialBalance) : Account(initialBalance) {}

    // Good LSP behavior:
    // It keeps the same contract as base class.
    bool withdraw(double amount) override {
        try {
            return Account::withdraw(amount);
        } catch (const runtime_error& e) {
            cout << "SavingsAccount warning: " << e.what() << endl;
            return false;
        } catch (const invalid_argument& e) {
            cout << "SavingsAccount warning: " << e.what() << endl;
            return false;
        }
    }

    bool deposit(double amount) override {
        try {
            return Account::deposit(amount);
        } catch (const invalid_argument& e) {
            cout << "SavingsAccount warning: " << e.what() << endl;
            return false;
        }
    }
};

class CheckingAccount : public Account {
public:
    explicit CheckingAccount(double initialBalance) : Account(initialBalance) {}

    // This keeps the same history constraint:
    // Validate -> update -> return success/failure.
    bool withdraw(double amount) override {
        if (amount <= 0) {
            cout << "CheckingAccount warning: amount must be positive" << endl;
            return false;
        }

        if (amount > balance) {
            cout << "CheckingAccount warning: insufficient balance" << endl;
            return false;
        }

        balance -= amount;
        return true;
    }

    bool deposit(double amount) override {
        if (amount <= 0) {
            cout << "CheckingAccount warning: amount must be positive" << endl;
            return false;
        }

        balance += amount;
        return true;
    }
};

void testAccount(Account& account, double amount) {
    cout << "Before: " << account.getBalance() << endl;

    bool success = account.withdraw(amount);
    cout << "Withdraw success: " << success << endl;
    cout << "After: " << account.getBalance() << endl;
    cout << "----------------------" << endl;
}

int main() {
    try {
        SavingsAccount savings(1000);
        CheckingAccount checking(1000);

        cout << "=== History Constraint Demo ===" << endl;
        testAccount(savings, 300);
        testAccount(checking, 300);

        cout << "=== Invariant Demo ===" << endl;
        cout << "Checking account balance is still valid: " << checking.getBalance() << endl;

        cout << "=== Exception Handling Demo ===" << endl;
        bool result = savings.withdraw(5000);
        cout << "Over-withdraw result: " << result << endl;

        cout << "=== Immutable Class Demo ===" << endl;
        ImmutableUserProfile user("Nitesh", 21);
        cout << "Immutable user: " << user.getName() << " (" << user.getAge() << ")" << endl;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
    }

    return 0;
}
