#include <iostream>
using namespace std;

int main()
{
    const int Rows=3;
    const int Colums = 4;

    int Array[Rows][Colums]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    for (int row=0; row<Rows; ++row)
    {
        for (int colums=0; colums<Colums; ++colums)
        {
            cout << Array[row][colums] << endl;
        }
    }
    return 0;
}