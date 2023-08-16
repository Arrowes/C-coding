#include <iostream>
using namespace std;

// remove the try-catch block to see this application crash 
int main()
{
   // try
   // {
      // Request a LOT of memory!
      int* pointsToManyNums = new int [0xffffffff];

      // Use the allocated memory 

	  delete[] pointsToManyNums;
     cout << pointsToManyNums  <<endl;
   // }
   // catch (bad_alloc)
   // {
   //    cout << "Memory allocation failed. Ending program" << endl;
   // }
   return 0;
}