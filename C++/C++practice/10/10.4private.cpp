#include <iostream>
using namespace std;

class Motor
{
    public:
        void SwitchIgnition()
        {
            cout << "Ignition ON"<<endl;
        }
        void PumpFuel()
        {
            cout<< "Feul in cylingders"<<endl;
        }
        void FireCylinders()
        {
            cout << "Vrooooom"<<endl;
        }
};

class Car:private Motor
{
    public:
        void Move()
        {
            SwitchIgnition();
            PumpFuel();
            FireCylinders();
        }
};

int main()
{
    Car myDreamCar;
    myDreamCar.Move();
    myDreamCar.PumpFuel();
    return 0;
}