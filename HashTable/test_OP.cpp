#include<iostream>
using namespace std;
#include "HashTable.h"

void Test()
{
         typedef HashTableNode <int, char> Node ;
         HashTable<int , char>ht;
        ht.Insert(22, 'm');
        ht.Insert(43, 'p');
        ht.Insert(64, 'x');
        ht.Insert(34, 'z');
        ht.Insert(65, 'w');
        ht.Print();
        
        
         Node* ret = ht.Find(64);
        cout << "字符为:" <<ret->_value << endl;
        cout << "数字为:" <<ret->_key << endl;
        ht.Remove(22);
        ht.Print();
}
void Test1()
{
         HashTable<int , char>ht;
        ht.Insert(22, 'm');
        ht.Insert(43, 'p');
        ht.Insert(64, 'x');
        ht.Insert(34, 'z');
        ht.Insert(65, 'w');

         /*HashTable<int, char>ht1(ht);
        ht1.Print();
*/
         HashTable<int , char>ht2;
        ht2 = ht;
        ht2.Print();
}
int main()
{
         //Test();
        Test1();
        system( "pause");
         return 0;
}
