#include <iostream>
#include <memory>

#include "Zomato.h"
#include "strategies/CardPaymentStrategy.h"

int main()
{
    Zomato zomato;

    Restaurant restaurant("Spice House", "Downtown");
    restaurant.addMenuItem(MenuItem("Paneer Tikka", 12.50, "P001"));
    restaurant.addMenuItem(MenuItem("Naan", 3.00, "B001"));
    zomato.addRestaurant(&restaurant);

    User customer("Asha", "42 Market Street");
    std::vector<Restaurant *> nearbyRestaurants = zomato.searchRestaurants("Downtown");
    if (nearbyRestaurants.empty())
    {
        std::cerr << "No restaurants found nearby." << std::endl;
        return 1;
    }

    Cart *cart = customer.getCart();
    cart->addItem(MenuItem("Paneer Tikka", 12.50, "P001"), &restaurant);
    cart->addItem(MenuItem("Naan", 3.00, "B001"), &restaurant);

    Order *order = zomato.placeOrder(
        customer,
        *nearbyRestaurants.front(),
        "Delivery",
        std::make_unique<CardPaymentStrategy>());

    if (order == nullptr)
    {
        std::cerr << "Order could not be placed." << std::endl;
        return 1;
    }

    std::cout << "Order placed successfully." << std::endl;
    return 0;
}
