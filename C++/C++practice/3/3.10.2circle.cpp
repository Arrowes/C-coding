#include <iostream>
using namespace std;

int main()
{
    cout << "Enter your radius:";
    float radius=0;
    const float Pi = 3.1415926;
    cin >> radius;
    cout << "Area:" <<radius*radius*Pi << endl
    << "Circumference:" << 2*Pi*radius << endl;

    return 0;
}