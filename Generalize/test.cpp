#include <iostream>
using namespace std;
#include "Generalized.h"
void Test()
{
         Generalize s1("(a,b,(c,d),(e,(f),h))" );
         Generalize s2(s1);
         Generalize s3;
        s3 = s1;
        s1.PrintList();
        cout << endl;
        s2.PrintList();
        cout << endl;
        s3.PrintList();
        cout << endl;

         size_t size = s1.Size();
        cout << "size=" << size << endl;
         size_t depth = s1.Depth();
        cout << "depth=" << depth << endl;
}
int main()
{
        Test();
        system( "pause");
         return 0;
}
