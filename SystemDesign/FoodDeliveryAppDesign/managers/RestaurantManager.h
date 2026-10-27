#ifndef RESTAURANTMANAGER_H
#define RESTAURANTMANAGER_H

#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
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
        if (restaurant != nullptr) {
            restaurants.push_back(restaurant);
        }
    }
    vector<Restaurant*> searchByLocation(const string& location) {
        vector<Restaurant*> result;
        string normalizedLocation = location;
        transform(normalizedLocation.begin(), normalizedLocation.end(), normalizedLocation.begin(),
                  [](unsigned char character) { return static_cast<char>(tolower(character)); });
        for (auto r : restaurants) {
            string restaurantLocation = r->getLocation();
            transform(restaurantLocation.begin(), restaurantLocation.end(), restaurantLocation.begin(),
                      [](unsigned char character) { return static_cast<char>(tolower(character)); });
            if (restaurantLocation == normalizedLocation) {
                result.push_back(r);
            }
        }
        return result;
    }

  
};
RestaurantManager* RestaurantManager::instance = nullptr;
#endif 