#include <iostream>
using namespace std;


// Strategy Interface for Walk 
class WalkableRobot
{
    public :
    virtual void walk() = 0;
    virtual ~WalkableRobot() {}
};
class NormalWalk : public WalkableRobot
{
    public :
    void walk() override
    {
        cout << "Normal Walking..." << endl;
    }
};

class NoWalk : public WalkableRobot
{
    public :
    void walk() override
    {
        cout << "Cannot Walk..." << endl;
    }
};

// Strategy Interface for Talk 
class TalkableRobot
{
    public :
    virtual void talk() = 0;
    virtual ~TalkableRobot() {};
};

// Concrete Stratigies for walk
class NormalTalk : public TalkableRobot
{
    public :
    void talk() override
    {
        cout << "Normal Talking...." << endl;
    };
};
class NoTalk : public TalkableRobot
{   
    public :
    void talk() override
    {
        cout << "Cannot Talk...." << endl;
    };
};

// Strategy Interface for Fly
class FlyableRobot
{  
    public :
    virtual void fly() = 0;
    virtual ~FlyableRobot() {};
};
class NormalFly : public FlyableRobot
{  
    public :
    void fly() override
    {
        cout << "Normally Flying..." << endl;
    };
};
class NoFly : public FlyableRobot
{    public :
    void fly() override
    {
        cout << "Cannot Fly" << endl;
    };
};

class Robot {
    protected :
    WalkableRobot *walkBehaviour;
    TalkableRobot *talkBehaviour;
    FlyableRobot *flyBehaviour;
    public :
    Robot(WalkableRobot* w , TalkableRobot* t , FlyableRobot* f){
      this->flyBehaviour = f;
      this->talkBehaviour = t;
      this->walkBehaviour = w;
    };
    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        talkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->fly();
    }

};

int main()
{

}
