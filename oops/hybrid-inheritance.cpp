#include <iostream>
using namespace std;

class Person {
public:
    void displayPerson() {
        cout << "I am a Person." << endl;
    }
};

class Student : public Person {
public:
    void study() {
        cout << "Studying..." << endl;
    }
};

class Employee : public Person {
public:
    void work() {
        cout << "Working..." << endl;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    void assist() {
        cout << "Teaching Assistant is assisting." << endl;
    }
};

int main() {
    TeachingAssistant ta;

    ta.study();
    ta.work();
    ta.assist();

    // ta.displayPerson(); // ❌ Error (Diamond Problem)

    ta.Student::displayPerson();
    ta.Employee::displayPerson();

    return 0;
}