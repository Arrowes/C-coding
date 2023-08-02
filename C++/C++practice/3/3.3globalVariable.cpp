#include <iostream>
using namespace std;

int firstNumber = 0;
int secondNumber = 0;
int multiply = 0;

void mul()
{
    cout << "multiply two numbers" << endl <<"Enter the first number:";
    cin >> firstNumber;
    cout << "Enter the  second number:";
    cin >> secondNumber;
    multiply = firstNumber*secondNumber;
    cout << firstNumber << " x " << secondNumber << " = " << multiply << endl;

}

int main()
{

    //int firstNumber = 0; //初始化虽然是可选的，但这样做通常是一个不错的编程习惯

    //int secondNumber = 0;

    //int multiply = firstNumber*secondNumber;

    mul();
    cout << firstNumber << " x " << secondNumber << " = " << multiply << endl;
    return 0;
}