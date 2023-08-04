#include <iostream>
using namespace std;

inline long DoubleNum (int inputNum)
{
    return inputNum*2;
}

int main()
{
    cout << "Enter an integer: ";
    int inputNum = 0;
    cin >> inputNum;

    cout << "Double is: " << DoubleNum(inputNum) << endl; 
    return 0;
}