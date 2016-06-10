#include <iostream>
using namespace std;
#include "Sparse.h"
void Test()
{
         int arr[ROW ][COL] = {
                {1,0,3,0,5},
                {0,0,0,0,0},
                {0,0,0,0,0},
                {2,0,4,0,6},
                {0,0,0,0,0},
                {0,0,0,0,0}
        };
         SparseMatrix<int > sm((int*)arr, ROW, COL , 0);
        sm.DisPlay( ROW,COL ,0);
         SparseMatrix<int > sm1;
        sm1 = sm.TrasPortMatirx(( int*)arr,ROW , COL, 0);
         sm1.DisPlay( COL, ROW , 0);

         SparseMatrix<int > sm2;
         sm2 = sm.FastTrasPortMatirx( ROW, COL , 0);
         sm2.DisPlay( COL, ROW , 0);
}
int main()
{
        Test();

        system( "pause");
         return 0;
}
