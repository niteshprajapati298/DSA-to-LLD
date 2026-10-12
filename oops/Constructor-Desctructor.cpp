#include <iostream>
using namespace std;
class Student
{
    string name;
    int age;

public:
    Student(string name, int age)
    {
        this->name = name;
        this->age = age;
        cout << "Contructor is Called " << name << endl;
    };
    ~Student()
    {
        cout << "Destructor is Called " << name << endl;
    };
    void display()
    {
        cout << "Name: " << name << endl
             << "Age: " << age << endl;
    }
};

void fun()
{
    Student s2("Kajal", 23);
}

class A {
public:
    void print() {
        cout << "Hello\n";
    }

    ~A() {
        cout << "A destroyed\n";
    }
};

class B {
    A* a;

public:
    B(A* obj) {
        a = obj;
    }

    ~B() {
        a->print();      // Uses A
        cout << "B destroyed\n";
    }
};

class Employee {
    string name;
    public:
    int *salary;
    public:
    Employee(string name, int inputSalary){
        this->name = name;
        this->salary = new int(inputSalary);
        cout << "Constructor is Called " << *salary << endl;
    };
    ~Employee(){
        cout<<"Destructor is Called " << *salary <<endl;
    };
   void display(){
     delete salary;
      cout << "Name: " << name << endl
             << "Salary: " << *salary << endl;
   }
};
int main()
{
    // Student S1("Nitesh", 29);
    // S1.display();
    // Student s1("A",21);
    // Student s2("B",29);
    // Student s3("C",12);
    //    A a;
    // B b(&a);
    // Employee* e1 = new Employee("Nitesh",2000);
    Employee e1("Nitesh",10);
    Employee e2=e1;
    *e2.salary = 200;
    e1.display();
    e2.display();
    
}