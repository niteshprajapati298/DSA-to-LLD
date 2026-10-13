#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "../models/Restaurant.h"

class RestaurantManager {
private:
    vector<Restaurant> restaurants;

public:
    void addRestaurant(Restaurant restaurant);
    void removeRestaurant(Restaurant restaurant);
    const vector<Restaurant> &getRestaurants() const;
};

#endif 