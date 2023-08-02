#include <iostream>
using namespace std;

int main()
{
    cout << "Enter two number:" << endl;
    int num1 = 0, num2 = 0;
    cin  >> num1;
    cin  >> num2;

    cout << "+ :" << num1 + num2 <<endl;
    cout << "- :" << num1 - num2 << endl;
    cout << "* :" << num1 * num2 << endl;
    cout << "/ :" << num1 / num2 << endl;
    cout << "% :" << num1 % num2 << endl;

    return 0;
}