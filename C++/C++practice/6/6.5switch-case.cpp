#include <iostream>
using namespace std;

int main()
{
    enum Days
    {
        Sunday=0,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    cout << "To find how the week named after, Enter a day(0 for sunday): ";
    int dayInput=0;
    cin >> dayInput;

    switch(dayInput)
    {
        case Sunday:
        cout << "Sunday: Sun" << endl;
        break;
        case Monday:
        cout << "Monday: Moon" << endl;
        break;
        case Tuesday:
        cout << "Tursday: Mars" << endl;
        break;
        case Wednesday:
        cout << "Wednesday: Mercury(水星)" << endl;
        break;
        case Thursday:
        cout << "Thursday: Jupiter(木星)" << endl;
        break;
        case Friday:
        cout << "Friday: Venus(金星)" << endl;
        break;
        case Saturday:
        cout << "Saturday: Saturn(土星)" << endl;
        break;

        default:
            cout << "Wrong Input" << endl;
            break;
    }
    return 0;
}