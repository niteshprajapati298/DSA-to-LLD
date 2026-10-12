#include<iostream>
using namespace std;
// class Student {
//     string name;
//     string grade;
//     int rollNo;
//     int age;
// };

class Student {
    string name;
    string grade;
    int rollNo;
    int age;

    public:
    void setName (string name1) {
        name = name1;
    }
    void setRollNo (int rollNo1){
       rollNo = rollNo1;
    }
    void setGrade (string grade1){
        grade = grade1;
    }
    void setAge (int age1){
        age = age1;
    }
    string getName(){
        return name;
    }
    string getGrade (){
        return grade;
    }
    int getRollNo (){
        return rollNo;
    }
    int getAge(){
        return age;
    }
};

void print (string name , string grade, int rollNo, int age){
    cout << "Name : " << name << endl << "Roll : " << rollNo << endl << "Grade : " << grade << endl << "Age : " << age << endl;
}
int main(){
    // string name;
    // string grade;
    // int rollNo,age;
    // cin>>name>>grade>>rollNo>>age;
    // print(name,grade,rollNo,age);  
    Student s1 ;
   s1.setAge(20);
   s1.setGrade("A+");
   s1.setName("Nitesh Prajapati");
   s1.setRollNo(21);
   cout << "Name : " << s1.getName() << endl;
   cout << "Grade : "<< s1.getGrade() << endl;
   cout <<  "RollNo : "<< s1.getRollNo() << endl;
   cout << "Age : " <<  s1.getAge() << endl;
}