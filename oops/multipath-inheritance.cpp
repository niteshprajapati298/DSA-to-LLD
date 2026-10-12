#include <iostream>
using namespace std;

class Human {
public:
    string name;
    int age;

    Human(string name, int age) {
        this->name = name;
        this->age = age;
    }

    void displayHuman() {
        cout << "Name : " << name << endl;
        cout << "Age  : " << age << endl;
    }
};

class Engineer : public Human {
public:
    string company;
    string technology;

    Engineer(string name, int age, string company, string technology)
        : Human(name, age) {
        this->company = company;
        this->technology = technology;
    }

    void writeCode() {
        cout << name << " is writing " << technology
             << " code at " << company << "." << endl;
    }
};

class Youtuber : public Human {
public:
    string channelName;
    int subscribers;

    Youtuber(string name, int age, string channelName, int subscribers)
        : Human(name, age) {
        this->channelName = channelName;
        this->subscribers = subscribers;
    }

    void makeVideo() {
        cout << name << " uploads videos on "
             << channelName << "." << endl;
    }
};

class CodeTeacher : public Engineer, public Youtuber {
public:
    string platform;

    CodeTeacher(
        string name,
        int age,
        string company,
        string technology,
        string channelName,
        int subscribers,
        string platform
    )
        : Engineer(name, age, company, technology),
          Youtuber(name, age, channelName, subscribers) {

        this->platform = platform;
    }

    void teach() {
        cout << "Teaching programming on "
             << platform << "." << endl;
    }
};

int main() {

    CodeTeacher ct(
        "Nitesh",
        22,
        "Google",
        "C++",
        "CodeWithNitesh",
        50000,
        "YouTube"
    );

    ct.writeCode();
    ct.makeVideo();
    ct.teach();

    // Ambiguity
    // ct.displayHuman();

    ct.Engineer::displayHuman();
    ct.Youtuber::displayHuman();

    return 0;
}