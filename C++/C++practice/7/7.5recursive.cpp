#include <iostream>
using namespace std;

int Fib(int fibIndex)
{
    if (fibIndex<2)
        return fibIndex;
    else
        return Fib(fibIndex-1)+Fib(fibIndex-2); //Fibonacci(n) = Fibonacci(n - 1) + Fibonacci(n - 2)  （n>1）
}

int main()
{
    cout << "Enter fibonacci Index: ";
    int index =0;
    cin >> index;

    cout << "Fibonacci is: "<< Fib(index) << endl;
    return 0;

}
