#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> dynArray (3);
    dynArray[0]=1;
    dynArray[1]=2;
    dynArray[2]=3;

    cout << "Array Size:" << dynArray.size() << endl;
    cout << "Inser an element:";
    int newValue = 0;
    cin >> newValue;
    dynArray.push_back(newValue);

    cout << "New Array Size: " << dynArray.size() << endl; 
    cout << "Last element in array: "; 
    cout << dynArray[dynArray.size() - 1] << endl; 
    return 0; 
}