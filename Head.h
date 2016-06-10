#include<assert.h>
#include <vector>
template <class T>
class Heap
{
public:
        Heap()
                :_arr( NULL)
        {}
         //构造函数
        Heap( const T *arr, size_t size )
        {
                _arr.reserve( size);
                 for (size_t i = 0; i < size; i++)
                {
                        _arr.push_back( arr[i]);
                }
                 for (int j = (_arr.size() - 2) / 2; j >= 0; j--)
                {
                        _AdjustDown(j, size);
                }
        }
        Heap( const vector <T>& h)
        {
                _arr.reserve(_arr.size());
                 for (size_t i = 0; i < _arr.size(); i++)
                {
                        _arr.push_back( h[i]);
                }
        }
         //先储存在顺序表中，在进行下调
         void push(const T& x)
        {
                _arr.push_back( x);
                _AdjustUp(_arr.size()-1);
        }
         //删除
         void pop()
        {
                 size_t size = _arr.size();
                 assert(size > 0);
                swap(_arr[0], _arr[size - 1]); //先把根结点和要删除的结点交换
                _arr.pop_back(); //然后删除
                size = _arr.size();
                _AdjustDown(0, size); //最后上调
        }
         //堆是否为空
         bool Empty()
        {
                 size_t size = _arr.size();
                 assert(size >= 0);
                 return size == 0;
        }
         //堆的大小
         size_t Size()
        {
                 size_t size = _arr.size();
                 assert(size >= 0);
                 return size;
        }
         //访问根结点
         T& Top()
        {
                 size_t size = _arr.size();
                 assert(size > 0);
                 return _arr[0];
        }
         void Print()
        {
                 for (int i = 0; i < Size(); i++)
                {
                        cout << _arr[i] << " ";
                }
                cout << endl;
        }
protected:
         //下调
         void _AdjustDown(size_t parent, size_t size )
        {
                 size_t child = 2 * parent + 1;
                 while (child < size )
                {
                         if (child + 1 < size &&_arr[child] < _arr[child + 1])
                        {
                                child++;
                        }
                         if (_arr[child]>_arr[parent ])
                        {
                                swap(_arr[child],_arr[ parent]);
                                 parent = child;
                                child = 2 * parent + 1;
                        }
                         else
                        {
                                 break;
                        }
                }
        }
         //上调
         void _AdjustUp(int child)
        {
                 int parent = (child - 1) / 2;
                 int size = _arr.size();
                 while (child > 0)
                {
                         if (_arr[child ] > _arr[parent])
                        {
                                swap(_arr[ child], _arr[parent]);
                                 child = parent;
                                parent = ( child - 1) / 2;
                        }
                         else
                        {
                                 break;
                        }
                }
        }
protected:
         vector<T > _arr;
};
