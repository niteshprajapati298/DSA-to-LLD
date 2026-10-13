#include<iostream>
using namespace std;



class MenuItem {
    string name;
    double price;
    string code;
    public:
    MenuItem(string name, double price, string code) : name(name), price(price), code(code) {

        this->name = name;
        this->price = price;
        this->code = code;
    }
    ~MenuItem() {
        cout << "MenuItem " << name << " destroyed." << endl;
    }
    string getName() {
        return name;
    }
    double getPrice() {
        return price;
    }
    string getCode() {
        return code;
    }
    void setName(string name) {
        this->name = name;
    }
    void setPrice(double price) {
        this->price = price;
    }
    void setCode(string code) {
        this->code = code;
    }
};
int main(){
}
