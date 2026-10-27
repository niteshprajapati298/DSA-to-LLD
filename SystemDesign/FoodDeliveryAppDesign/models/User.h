#ifndef USER_H
#define USER_H
#include <iostream>
using namespace std;
#include <string>
#include "Cart.h"
class User {
    static int nextUserId;
    int userId;
    string name;
    string address;
    Cart* cart;
    public:
    User(string name, string address) : name(name), address(address) {
        this->userId = ++nextUserId;
        this->name = name;
        this->address = address;
        this->cart = new Cart();
    }
    int getUserId() const {
        return userId;
    }
    string getName() const {
        return name;
    }
    string getAddress() const {
        return address;
    }
    Cart* getCart() const {
        return cart;
    }
};

int User::nextUserId = 0;
#endif