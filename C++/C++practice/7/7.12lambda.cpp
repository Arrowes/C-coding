#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void DisplayNums(vector<int>& dynArray)
{   //for_each, sort是STL算法
    for_each (dynArray.begin(), dynArray.end(), [](int Element){cout << Element << " ";});
    cout << endl;
}

int main()
{
    vector<int> myNums; //将几个整数压入到一个动态数组中
    myNums.push_back(501);
    myNums.push_back(-1);
    myNums.push_back(25);
    myNums.push_back(-35);

    DisplayNums(myNums);

    cout << "Descending order: " << endl;
    sort (myNums.begin(), myNums.end(),  [](int Num1, int Num2) {return (Num2 < Num1); } );

    DisplayNums(myNums);

    return 0;
}