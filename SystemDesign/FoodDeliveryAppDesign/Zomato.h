#ifndef ZOMATO_H
#define ZOMATO_H

#include <memory>
#include <string>
#include <vector>

#include "factories/NowOrderFactory.h"
#include "factories/ScheduledOrderFactory.h"
#include "managers/OrderManager.h"
#include "managers/RestaurantManager.h"
#include "services/NotificationService.h"

class Zomato
{
public:
    void addRestaurant(Restaurant *restaurant)
    {
        if (restaurant != nullptr)
        {
            RestaurantManager::getInstance()->addRestaurant(restaurant);
        }
    }

    std::vector<Restaurant *> searchRestaurants(const std::string &location)
    {
        return RestaurantManager::getInstance()->searchByLocation(location);
    }

    Order *placeOrder(
        User &user,
        Restaurant &restaurant,
        const std::string &orderType,
        std::unique_ptr<PaymentStrategy> paymentStrategy,
        bool scheduled = false)
    {
        Cart *cart = user.getCart();
        if (cart == nullptr || cart->isEmpty())
        {
            std::cerr << "Cannot place an order with an empty cart." << std::endl;
            return nullptr;
        }
        if (cart->getRestaurant() != &restaurant)
        {
            std::cerr << "The cart items do not belong to the selected restaurant." << std::endl;
            return nullptr;
        }
        if (paymentStrategy == nullptr)
        {
            std::cerr << "Cannot place an order without a payment strategy." << std::endl;
            return nullptr;
        }

        std::unique_ptr<OrderFactory> factory;
        if (scheduled)
        {
            factory = std::make_unique<ScheduledOrderFactory>();
        }
        else
        {
            factory = std::make_unique<NowOrderFactory>();
        }

        Order *order = factory->createOrder(
            &user,
            cart,
            &restaurant,
            cart->getItems(),
            paymentStrategy.get(),
            orderType);
        if (order == nullptr)
        {
            return nullptr;
        }

        PaymentStrategy *strategy = paymentStrategy.release();
        if (!order->processPayment(strategy))
        {
            delete order;
            return nullptr;
        }

        OrderManager::getInstance()->addOrder(order);
        NotificationService::notify(order);
        cart->clear();
        return order;
    }
};

#endif
