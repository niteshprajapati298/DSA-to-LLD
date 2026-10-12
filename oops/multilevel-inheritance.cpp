#include<iostream>
using namespace std;
class Person {
    protected : 
    string name;
    int age; 
    int weight;
    public : 
    void introduce(){
        cout <<"Name: "<< name << endl << "Age: " << age << endl << "Weight " << weight << endl;
     }
};
class Employee : public Person {
     protected:
     int salary ;
     public :
     void display_salary(){
        cout << "Salary: " << salary << endl;
     }
    
};
class Manager : public Employee {
    protected :
    string department;
    public :
    Manager(string name , int age , int weight , int salary , string department){
      this->name = name;
      this->age = age;
      this->weight = weight;
      this->salary = salary;
      this->department = department;
   }

};

int main(){
    Manager m1("Nitesh Prajapti",21,65,25000,"IT");
    m1.display_salary();
    m1.introduce();
}