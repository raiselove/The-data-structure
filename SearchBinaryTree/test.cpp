#include <iostream>
using namespace std;
#include "SearchBinaryTree.h"
void Test()
{
         int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
         SearchBinaryTree<int , int>s;
         for (int i = 0; i < 10; i++)
        {
                s.Insert_R(arr[i],1);
        }
        s.InOrder();

         for (int i = 0; i < 10; i++)
        {
                s.Rmove_R(arr[i]);
        }

        s.InOrder();
}
int main()
{
        Test();
        system( "pause");
         return 0;
}
