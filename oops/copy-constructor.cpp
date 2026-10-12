#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r, int i) {
        real = r;
        imag = i;
    }

    // Copy Constructor
    Complex(const Complex& obj) {
        cout << "Copy Constructor Called" << endl;

        real = obj.real;
        imag = obj.imag;
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {

    Complex c1(3, 4);

    // Copy Constructor is called
    Complex c2 = c1;

    c2.display();

    return 0;
}