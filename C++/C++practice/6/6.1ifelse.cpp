#include <iostream>
using namespace std;
 int main()
 {
    cout << "enter two numbers: " ;
    int num1=0, num2=0;
    cin >> num1 >>num2;

    cout << "enter m to multiply, else to add: ";
    char entered='\0';
    cin >> entered;

    int result =0 ;
    if (entered == 'm')
        result = num1*num2;
    else
        result = num1 + num2;

    cout << "result: " << result << endl;
    return 0;
 }