#include <iostream>
using namespace std;
#include "Symmetry.h"
void Test()
{
         int arr[5][5] = {
                {0,1,2,3,4},
                {1,0,1,2,3},
                {2,1,0,1,2},
                {3,2,1,0,1},
                {4,3,2,1,0}
        };
         Symmetry<int >s((int*)arr, 5);
        s.Print(5);
}
int main()
{
        Test();
        system( "pause");
         return 0;
}
