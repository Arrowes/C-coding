#include <iostream>
using namespace std;

int main()
{
    cout << "multiply two numbers" << endl <<"Enter the first number:";
    int firstNumber = 0; //初始化虽然是可选的，但这样做通常是一个不错的编程习惯
    cin >> firstNumber;

    cout << "Enter the  second number:";
    int secondNumber = 0;
    cin >> secondNumber;
    int multiply = firstNumber*secondNumber;

    cout << firstNumber << " x " << secondNumber << " = " << multiply << endl;
    return 0;
}