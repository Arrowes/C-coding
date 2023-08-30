#include <iostream>
using namespace std;

class Fish
{
    public:
        bool isFreshWaterFish;

        void Swim()
        {
            if (isFreshWaterFish)
                cout << "Swims in lake" << endl;
            else
                cout << "Swims in sea" << endl;
        }
};

class Tuna: public Fish
{
    public:
        Tuna()
        {
            isFreshWaterFish=false;
        }
};

class Carp: public Fish
{
    public:
        Carp()
        {
            isFreshWaterFish=true;
        }
};

int main()
{
    Carp myLunch;
    Tuna myDinner;

    cout << "My lunch: ";
    myLunch.Swim();

    cout<<"My dinner: ";
    myDinner.Swim();

    return 0;
}

