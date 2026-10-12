#include <iostream>
using namespace std;

class Human
{
protected:
    string name, gender;
    int age, weight;

public:
    void introduce()
    {
        cout << "Name: " << name << endl;
        cout << "gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Weight: " << weight << endl;
    };
};
class Student : public Human
{
private:
    string standard, university;
    int fees;

 public:
    Student(string name, string gender, int age, int weight, string standard, string university, int fees)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->weight = weight;
        this->standard = standard;
        this->university = university;
        this->fees = fees;
    }
    
    void getStudentDetails()
    {
                cout << "-------- Student ----------" << endl;

        cout << "Name       : " << name << endl;
        cout << "Gender     : " << gender << endl;
        cout << "Age        : " << age << endl;
        cout << "Weight     : " << weight << endl;
        cout << "Standard   : " << standard << endl;
        cout << "University : " << university << endl;
        cout << "Fees       : " << fees << endl;
    }
};

class Teacher : public Human
{
private:
    string mastery, university;
    int salary;

 public:
    Teacher(string name, string gender, int age, int weight, string mastery, string university, int salary)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->weight = weight;
        this->mastery = mastery;
        this->university = university;
        this->salary = salary;
    }
    
    void getTeacherDetails()
    {
                cout << "-------- Teacher ----------" << endl;

        cout << "Name       : " << name << endl;
        cout << "Gender     : " << gender << endl;
        cout << "Age        : " << age << endl;
        cout << "Weight     : " << weight << endl;
        cout << "Subject   : " << mastery << endl;
        cout << "University : " << university << endl;
        cout << "Salary       : " << salary << endl;
    }
};
class Employee : public Human {

private:
    string role, organization;
    int salary, experience;

 public:
    Employee(string name, string gender, int age, int weight, string role, string organization, int salary ,int experience)
    {
        this->name = name;
        this->gender = gender;
        this->age = age;
        this->weight = weight;
        this->role = role;
        this->organization = organization;
        this->salary = salary;
        this->experience = experience;
    }
    
    void getEmployeeDetails()
    {

        cout << "-------- Emloyee ----------" << endl;
        cout << "Name       : " << name << endl;
        cout << "Gender     : " << gender << endl;
        cout << "Age        : " << age << endl;
        cout << "Weight     : " << weight << endl;
        cout << "Role   : " << role << endl;
        cout << "Organization : " << organization << endl;
        cout << "Salary       : " << salary << endl;
        cout << "Experience       : " << experience << " Years" << endl;


    }
};
int main(){
Student s1("Nitesh Prajapati", "Male", 21, 64, "12-th", "UP Board", 120000);
s1.getStudentDetails();
Teacher t1("Rahul Sharma", "Male", 35, 72, "Mathematics","GLA University", 75000);
t1.getTeacherDetails();
Employee e1("Priya Verma", "Female", 29, 58 ,"Software Engineer" ,"Google" , 85000 , 2);
e1.getEmployeeDetails();

}