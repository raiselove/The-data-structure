#include <iostream>
using namespace std;
#include "Hash.h"
//void Test()
//{
//      HashTable<int> ht(10);
//      ht.Insert(24);
//      ht.Insert(20);
//      ht.Insert(36);
//      ht.Insert(23);
//      ht.Insert(30);
//      ht.print();
//
//      int ret = ht.Find(30);
//      cout << "下标为："<<ret << endl;
//
//      ht.Remove(30);
//      ht.print();
//
//}

void Test1()
{
         HashTable<string > ht(10);
        ht.Insert( "杭哥");
        ht.Insert( "张哥");
        ht.Insert( "詹姐");
        ht.Insert( "亮哥");
        ht.Insert( "蛋蛋");
        ht.print();

         int ret = ht.Find("蛋蛋" );
        cout << "下标为：" << ret << endl;

        ht.Remove( "亮哥");
        ht.print();
}
int main()
{
         //Test();
        Test1();
        system( "pause");
         return 0;
}
