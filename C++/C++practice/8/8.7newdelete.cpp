#include <iostream>
using namespace std;

int main()
{
    int* point= new int;

    cout << "Enter age: ";
    cin >> *point;

    cout << "Age: " << *point << " stored at: " << point << endl;
    delete point;

    return 0;
}