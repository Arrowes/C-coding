#include <iostream>
using namespace std;

void GetSquare(int& number)
{
    number *= number;
}

int main()
{
    cout << "Square number: ";
    int number = 0;
    cin >> number;

    GetSquare(number);
    cout << " = " << number <<endl;

    return 0;
}