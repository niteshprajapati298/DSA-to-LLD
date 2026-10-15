#ifndef RESURANT_H
#define RESURANT_H
#include <iostream>
using namespace std;
#include <vector>
#include "string"
#include "MenuItem.h"

class Restaurant
{
    static int nextRestaurantId;
    int restaurantId;
    string name;
    string location;
    vector<MenuItem> menu;

public:
    Restaurant(string name, string location) : name(name), location(location)
    {
        this->restaurantId = ++nextRestaurantId;
        this->name = name;
        this->location = location;
    }
    ~Restaurant()
    {
        cout << "Restaurant " << name << " destroyed." << endl;
        menu.clear();
    }
    string getName()
    {
        return name;
    }
    void setLocation(string location)
    {
        this->location = location;
    }
    string getLocation()
    {
        return location;
    }
    const vector<MenuItem> &getMenu() const
    {
        return menu;
    }
    void addMenuItem(MenuItem item)
    {
        menu.push_back(item);
    }
    void setName(string name)
    {
        this->name = name;
    }
};
int Restaurant::nextRestaurantId = 1;

#endif