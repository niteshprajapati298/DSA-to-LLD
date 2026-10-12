#include <iostream>
using namespace std;

class Student {
private:
    int* marks;

public:
    // Parameterized Constructor
    Student(int m) {
        marks = new int(m);
    }

    // Deep Copy Constructor
    Student(const Student& obj) {
        cout << "Copy Constructor Called" << endl;

        marks = new int(*obj.marks);
    }

    void setMarks(int m) {
        *marks = m;
    }

    void display() {
        cout << "Marks : " << *marks << endl;
    }

    ~Student() {
        delete marks;
    }
};

int main() {

    Student s1(95);

    // Copy Constructor
    Student s2 = s1;

    s2.setMarks(100);

    cout << "Student 1" << endl;
    s1.display();

    cout << "Student 2" << endl;
    s2.display();

    return 0;
}