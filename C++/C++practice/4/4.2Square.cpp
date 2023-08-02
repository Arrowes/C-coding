#include <iostream>
using namespace std;
constexpr int Square(int number) {return number*number;}

int main()
{
    const int length = 5;
    int myNumbers [length] = {5, 10, 0, -101, 20};
    int moreNumbers [Square(length)];
    int element=0;
    cout << "Change which one:";
    cin >> element;

    cout << "New value:";
    int newValue=0;
    cin >> newValue;

    myNumbers[element] = newValue; 
   moreNumbers[element] = newValue; 
   cout << "Element " << element << " in array myNumbers is: "; 
    cout << myNumbers[element] << endl; 
    cout << "Element " << element << " in array moreNumbers is: "; 
    cout << moreNumbers[element] << endl; 
    return 0; 
}