#include <iostream>
using namespace std;

int main()
{
    int age =30, dogAge=9;

    int* pointsToInt = &age;
    cout << "Adress = " << pointsToInt << endl << "Value = " << *pointsToInt << endl ;

    pointsToInt = &dogAge;
    cout << "Adress = " << pointsToInt << endl << "Value = " << *pointsToInt << endl ;

    return 0;
}