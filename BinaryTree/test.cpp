#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;
#include "Binary.h"
void Test()
{
         int arr[10] = { 1, 2, 3, '#' , '#', 4, '#', '#' , 5, 6 };
         BinaryTree<int > s(arr, 10, '#');
         BinaryTree<int > s1(arr, 10, '#');
         BinaryTree<int > s3(arr, 10, '#');
         BinaryTree<int > s5(arr, 10, '#');
        s.PrevOrder();
        s1.InOrder();
        s3.PostOrder();
        s5.LevelOrder();
         BinaryTree<int > s4(arr, 10, '#');
        cout << "size=" << s4.Size() << endl;
        cout << "depth=" << s4.Depth() << endl;
        cout << "leafsize=" << s4.LeafSize() << endl;
        cout << "KLevelsize=" << s4.KLevelSize(1) << endl;
        cout << "KLevelsize=" << s4.KLevelSize(2) << endl;
        cout << "KLevelsize=" << s4.KLevelSize(3) << endl;

         BinaryTree<int > s6(arr, 10, '#');
         BinaryTree<int > s7(s6);
         BinaryTree<int >s8;
        s8 = s7;
        s7.PrevOrder();
        s8.PrevOrder();
}
int main()
{
        Test();
        system( "pause");
         return 0;
}
