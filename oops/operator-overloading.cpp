#include <iostream>
using namespace std;

class Vector2D {
private:
    int x, y;

public:
    Vector2D(int x = 0, int y = 0) {
        this->x = x;
        this->y = y;
    }

    // + Operator
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // - Operator
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // == Operator
    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    // Prefix ++
    Vector2D& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // << Operator
    friend ostream& operator<<(ostream& out, const Vector2D& v) {
        out << "(" << v.x << ", " << v.y << ")";
        return out;
    }
};

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // Overloading + operator
    Complex operator+(const Complex& obj) {
        return Complex(real + obj.real, imag + obj.imag);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {

    Complex c1(3, 4);
    Complex c2(5, 6);

    Complex c3 = c1 + c2;

    c3.display();

    Vector2D v1(10, 20);
    Vector2D v2(5, 15);

    Vector2D sum = v1 + v2;
    Vector2D diff = v1 - v2;

    cout << "v1 : " << v1 << endl;
    cout << "v2 : " << v2 << endl;

    cout << "Sum : " << sum << endl;
    cout << "Difference : " << diff << endl;

    if (v1 == v2)
        cout << "Vectors are Equal" << endl;
    else
        cout << "Vectors are Not Equal" << endl;

    ++v1;

    cout << "After Prefix ++ : " << v1 << endl;

    return 0;
}