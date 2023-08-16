#include <iostream>
using namespace std;

int main()
{
    int age = 30;
    const double Pi=3.1415926;

    cout << "age is located at: 0x" << &age << endl << "Pi is located at: 0x" <<hex<< &Pi << endl;

    return 0;
}