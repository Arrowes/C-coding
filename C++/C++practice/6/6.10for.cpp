#include <iostream>
using namespace std;

int main()
{
    const int ARRAY=5;
    int myNums[ARRAY] = {0};

    cout << "Populate array of " << ARRAY << " integers" << endl;

    for (int counter = 0; counter < ARRAY; ++counter)
    {
        cout << "Enter an integer for element " << counter << ": ";
        cin >> myNums[counter]; 
    }

    for (int counter = 0; counter < ARRAY; ++counter)
        cout << "Element " << counter << " = " << myNums[counter] << endl;
    return 0;
}