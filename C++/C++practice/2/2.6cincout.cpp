#include <iostream>
#include <string>
using namespace std;

int main()
{
    int inputNumber;
    cout << "Enter an integer:";
    cin >> inputNumber;

    string Name;
    cout  << "Name:";
    cin >> Name;

    cout << Name << " entered " << inputNumber << endl;

    return 0;
}