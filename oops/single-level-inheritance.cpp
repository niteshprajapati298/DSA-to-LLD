#include<iostream>
using namespace std;

class Employee  {
    protected : 
    string name;
    int age; 
    int weight;
    int salary;
    public : 
    void introduce(){
        cout <<"Name: "<< name << endl << "Age: " << age << endl << "Weight " << weight << endl << "Salary: "<< salary << endl;
     }
};
class Manager : public Employee {
    protected :
    string department;
    string team;
    public :
    Manager(string name , int age , int weight ,int salary , string department,string team){
      this->name = name;
      this->age = age;
      this->weight = weight;
      this->salary = salary;
      this->department = department;
      this->team = team;
   }
};

int main(){
    Manager m1("Nitesh Prajapti",21,65,25000,"IT","Team1");
    m1.introduce();
}