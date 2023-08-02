#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    cout << "Enter 0~255: ";
    unsigned short inputNum = 0;
    cin >> inputNum;

    bitset<8> inputBits (inputNum);
    cout << inputNum << " in binary is " << inputBits << endl;

    bitset<8> bitwiseNot = (~inputNum);
    cout << "~inputBits = " << bitwiseNot << endl;

    bitset<8> bitwiseAnd = (0x0F & inputNum); //0001111
    cout << "00001111 & " << inputBits << " = " << bitwiseAnd <<endl;

    bitset<8> bitwiseOR =  (0x0F | inputNum); //0001111
    cout << "00001111 | " << inputBits << " = " << bitwiseOR <<endl;

    bitset<8> bitwiseXOR =  (0x0F ^ inputNum); //0001111
    cout << "00001111 ^ " << inputBits << " = " << bitwiseXOR <<endl;

    return 0;
}