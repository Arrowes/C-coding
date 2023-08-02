#include <iostream>
constexpr double GetPi() {return 22.0/7;}
constexpr double TwicePi() {return 2*GetPi();}

int main()
{
    using namespace std;
    const double pi = 22.0/7;

    cout << "const pi:" << pi << endl
    << "constexpr GetPi:" << GetPi() << endl
    << "constexpr TwicePi:" << TwicePi() << endl;

    return 0;
}