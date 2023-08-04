#include <iostream>
using namespace std;

const double Pi = 3.14159265;

double Area(double radius);
double Cir(double radius);

int main()
{
    cout << "Enter radius: ";
    double radius=0;
    cin >> radius;
    cout << "Area is: " << Area(radius) << endl;
    cout << "Circumference is: " << Cir(radius) << endl;

    return 0; 
}

double Area(double radius)
{
    return Pi*radius*radius;
}

double Cir(double radius)
{
    return 2*Pi*radius;
}