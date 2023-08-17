#include <iostream>
#include <string>
using namespace std;

class Human
{
public:
    string name;
    int age;
    void Talk()
    { cout << "I am " + name <<", " << age <<   " years old" << endl;
    }
};

int main()
{
    Human Man;
    Man.name = "wyj";
    Man.age = 23;

    Human Woman;
    Woman.name = "girl";
    Woman.age = 22;

    Man.Talk();
    Woman.Talk();
}