#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include "../models/Restaurant.h"

class RestaurantManager {
private:
    static RestaurantManager* instance;
    vector<Restaurant*> restaurants;

public:
    static RestaurantManager* getInstance() {
        if (instance == nullptr) {
            instance = new RestaurantManager();
        }
        return instance;
    }

    void addRestaurant(Restaurant* restaurant) {
        restaurants.push_back(restaurant);
    }
    vector<Restaurant*> searchByLocation(const string& location) {
        vector<Restaurant*> result;
        transform(location.begin(), location.end(), location.begin(), ::tolower);
        for (auto r : restaurants) {
            string restaurantLocation = r->getLocation();
            transform(restaurantLocation.begin(), restaurantLocation.end(), restaurantLocation.begin(), ::tolower);
            if (restaurantLocation == location) {
                result.push_back(r);
            }
        }
        return result;
    }

  
};
RestaurantManager* RestaurantManager::instance = nullptr;
#endif 