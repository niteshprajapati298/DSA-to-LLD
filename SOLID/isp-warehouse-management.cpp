#include <iostream>
#include <string>
using namespace std;

// ISP: Interface Segregation Principle
// Clients use only the methods they need, instead of depending on big interfaces.
//
// Bad example idea:
// One huge interface with methods like placeOrder, shipOrder, cancelOrder,
// trackInventory, and refundOrder, even though a client only needs one or two of them.
//
// Example:
// class WarehouseInterface {
// public:
//     virtual void placeOrder() = 0;
//     virtual void shipOrder() = 0;
//     virtual void trackInventory() = 0;
//     virtual void refundOrder() = 0;
// };

class IInventoryChecker {
public:
    virtual ~IInventoryChecker() = default;
    virtual bool hasStock(const string& item, int quantity) = 0;
};

class IOrderPlacer {
public:
    virtual ~IOrderPlacer() = default;
    virtual void placeOrder(const string& item, int quantity) = 0;
};

class IShipmentManager {
public:
    virtual ~IShipmentManager() = default;
    virtual void shipOrder(const string& orderId) = 0;
};

class WarehouseSystem : public IInventoryChecker, public IOrderPlacer, public IShipmentManager {
public:
    bool hasStock(const string& item, int quantity) override {
        cout << "Checking stock for " << quantity << " of " << item << endl;
        return true;
    }

    void placeOrder(const string& item, int quantity) override {
        cout << "Order placed for " << quantity << " of " << item << endl;
    }

    void shipOrder(const string& orderId) override {
        cout << "Shipping order " << orderId << endl;
    }
};

int main() {
    WarehouseSystem warehouse;

    IInventoryChecker& inventory = warehouse;
    IOrderPlacer& orderPlacer = warehouse;
    IShipmentManager& shipment = warehouse;

    cout << boolalpha << inventory.hasStock("Mouse", 5) << endl;
    orderPlacer.placeOrder("Mouse", 5);
    shipment.shipOrder("ORD-500");

    return 0;
}
