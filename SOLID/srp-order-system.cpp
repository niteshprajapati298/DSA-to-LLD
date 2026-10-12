#include <iostream>
#include <string>
using namespace std;

// SRP: Single Responsibility Principle
// This example keeps one responsibility per class:
// - Order stores data
// - OrderRepository saves data
// - InvoicePrinter formats output
// - OrderService coordinates the workflow
//
// Bad example idea:
// A single class doing everything at once: storing data, saving to DB,
// printing invoice, and handling payment logic. That makes the class hard to maintain.
//
// Example:
// class Order {
// public:
//     void saveToDatabase() { /* ... */ }
//     void printInvoice() { /* ... */ }
//     void processPayment() { /* ... */ }
// };

class Order {
private:
    string id;
    string customer;
    double total;
    bool paid;

public:
    Order(string orderId, string customerName, double amount)
        : id(orderId), customer(customerName), total(amount), paid(false) {}

    string getId() const { return id; }
    string getCustomer() const { return customer; }
    double getTotal() const { return total; }
    bool isPaid() const { return paid; }

    void markPaid() { paid = true; }
};

class OrderRepository {
public:
    void save(const Order& order) {
        cout << "Saved order " << order.getId() << " for " << order.getCustomer() << endl;
    }
};

class InvoicePrinter {
public:
    void printInvoice(const Order& order) {
        cout << "Invoice for " << order.getCustomer() << " -> Total: " << order.getTotal() << endl;
    }
};

class OrderService {
private:
    OrderRepository& repository;
    InvoicePrinter& printer;

public:
    OrderService(OrderRepository& repo, InvoicePrinter& print)
        : repository(repo), printer(print) {}

    void checkout(Order& order) {
        order.markPaid();
        repository.save(order);
        printer.printInvoice(order);
    }
};

int main() {
    Order order("ORD-101", "Nitesh", 450.50);
    OrderRepository repository;
    InvoicePrinter printer;
    OrderService service(repository, printer);

    service.checkout(order);

    cout << "Payment status: " << (order.isPaid() ? "Paid" : "Pending") << endl;
    return 0;
}
