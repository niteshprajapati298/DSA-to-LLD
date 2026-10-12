#include <iostream>
using namespace std;

// class SingleTon
// {
// public:
//     SingleTon()
//     {
//         cout << "Calling SingleTon Constructor" << endl;
//     }
// };

// int main()
// {
//     SingleTon * s1 = new SingleTon();
//     SingleTon * s2 = new SingleTon();
//     if (s1==s2) cout << "True" << endl;
//     else cout << "False" << endl;

// }

class SingleTon
{
    static SingleTon *instance;

private:
    SingleTon()
    {
        cout << "Single Ton Constructor Called" << endl;
    }

public:
    static SingleTon *getSingleTon()
    {
        if (instance == nullptr)
        {
            instance = new SingleTon();
        }
        else
            return instance;
    }
};

SingleTon *SingleTon::instance = nullptr;

// solution : ->
int main()
{
    SingleTon *s1 = SingleTon::getSingleTon();
    SingleTon *s2 = SingleTon::getSingleTon();
    if (s1 == s2)
        cout << "True" << endl;
    else
        cout << "False" << endl;
}