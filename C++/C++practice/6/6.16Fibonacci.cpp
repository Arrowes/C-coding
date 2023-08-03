#include <iostream>
using namespace std;

int main()
{
    const int numbers=5;
    int num1=0, num2=1;
    char keep='y';

    do
    {
       // for (int count=0; count<numbers; ++count)
       // {
            cout << num1 << " " << num2<< " "  << num1+num2<< " "  << num1+num2+num2<< " "   << num1+num2+num1+num2+num2 << endl;
            int temp=num1+num2+num1+num2+num2;
            num1=temp+ num1+num2+num2;
            num2=num1+temp;
     //   }
        cout << "Press 'y' to Continue: ";
        cin >> keep;
    } while (keep=='y');
    return 0;
}