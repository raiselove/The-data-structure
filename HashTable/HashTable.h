数据的放入法
//哈希表中存放数据的状态
enum State
{
    EMPTY,//没有数据
    DELETE,//删除数据后
    EXIST//有数据
};
template <class K>
class HashTable
{
public:
    //构造函数
    HashTable()
        :_table(NULL)
        , state(NULL)
        , _size(0)
        , _capatity(0)
    {}
    //构造函数
    HashTable(size_t size)
        :_table(new K[size])
        , _state(new State[size])
        , _capatity(size)
        , _size(0)
    {
        for (int i = 0; i < _capatity; i++)
        {
            _state[i] = EMPTY;
        }
    }
    //插入数据
    bool Insert(const K& key)
    {
        //检测静态哈希表是否已满
        if (_size == _capatity)
        {
            cout << "哈希表已满!" << endl;
            return false;
        }
        int index = _HashFunc(key);
        while (_state[index] == EXIST)
        {
            index++;//哈希冲突，找下一个位置
            //最后一个位置有数据，从头开始找位置
            if (index == _capatity)
            {
                index = 0;
            }
        }
        //哈希不冲突，直接放数据
        _table[index] = key;
        _state[index] = EXIST;
        _size++;
        return true;
    }
    //查找
    int Find(const K& key)
    {
        int index = _HashFunc(key);
        while (_state[index] != EMPTY)
        {
            //找到元素
            if (_table[index] == key&&_state[index] == EXIST)
            {
                return index;
            }
            //如果算出的位置，不是要找的元素，index++;
            index++;
            //最后一个位置不是，就从头开始找
            if (index == _capatity)
            {
                index = 0;
            }
        }
        return -1;
    }
    void print()
    {
        for (int i = 0; i < _capatity; i++)
        {
            if (_state[i] == EXIST)
            {
                printf("[%d]EXIST:%d\n",i, _table[i]);
            }
            else if (_state[i] == DELETE)
            {
                printf("[%d]DELETE:NULL\n", i, _table[i]);
            }
            else
            {
                printf("[%d]EMPTY:NULL\n", i);
            }
        }
    }
    //删除某一位置元素
    bool Remove(const K& key)
    {
        int index = Find(key);//找到这个元素
        //删除这个元素
        if (index != -1)
        {
            _state[index] = DELETE;
            _size--;
            return true;
        }
        return false;
    }
protected:
    //算出数据在哈希表中的位置（哈希不冲突）
    int _HashFunc(const K& key)
    {
        return key%_capatity;
    }
protected:
    K* _table;//数组
    State* _state;//状态数组
    size_t _size;//数组大小
    size_t _capatity;//数组的容量
};
#include <iostream>
using namespace std;
#include "Hash.h"
void Test()
{
    HashTable<int> ht(10);
    ht.Insert(24);
    ht.Insert(20);
    ht.Insert(36);
    ht.Insert(23);
    ht.Insert(30);
    ht.print();

    int ret = ht.Find(30);
    cout << "下标为："<<ret << endl;

    ht.Remove(30);
    ht.print();

}
int main()
{
    Test();
    system("pause");
    return 0;
}
另一种检查容量
bool Insert(const K& key)
    {
        //检测静态哈希表是否已满
        /*if (_size == _capatity)
        {
            cout << "哈希表已满!" << endl;
            return false;
        }*/
        //考虑到载荷因子在0.7~0.8一下比较好，这样检查容量比较好
        if (10 * _size >= 8 * _capatity)
        {
            _CheckCapatity();
        }
        int index = _HashFunc(key);
        while (_state[index] == EXIST)
        {
            index++;//哈希冲突，找下一个位置
            //最后一个位置有数据，从头开始找位置
            if (index == _capatity)
            {
                index = 0;
            }
        }
        //哈希不冲突，直接放数据
        _table[index] = key;
        _state[index] = EXIST;
        _size++;
        return true;
    }


    //交换
    void _Swap(HashTable<K> tmp)
    {
        swap(_size, tmp._size);
        swap(_capatity, tmp._capatity);
        swap(_state, tmp._state);
        swap(_table, tmp._table);
    }
    //检查容量
    void _CheckCapatity()
    {
        HashTable<K> tmp(2 * _capatity);
        for (int i = 0; i < _capatity; i++)
        {
            tmp.Insert(_table[i]);
        }
        _Swap(tmp);
    }
字符串
#include <string>
//哈希表中存放数据的状态
enum State
{
         EMPTY,//没有数据
         DELETE,//删除数据后
         EXIST//有数据
};
template <class K>
//处理
struct DefaultFunc
{
         size_t operator()(const K& key)
        {
                 return key ;
        }
};
//自定义类型
template<>
struct DefaultFunc <string> //特化
{
         size_t value = 0;
         size_t operator()(const string& str)
        {
                 for (int i = 0; i < str.size(); i++)
                {
                        value += str[i];
                }
                 return value;
        }
};
template <class K, template < class>class HashFunc = DefaultFunc>
class HashTable
{
public:
         //构造函数
        HashTable()
                :_table( NULL)
                , state( NULL)
                , _size(0)
                , _capatity(0)
        {}
         //构造函数
        HashTable( size_t size )
                :_table( new K [size])
                , _state( new State [size])
                , _capatity( size)
                , _size(0)
        {
                 for (int i = 0; i < _capatity; i++)
                {
                        _state[i] = EMPTY;
                }
        }
         //插入数据
         bool Insert(const K& key)
        {
                 //检测静态哈希表是否已满
                 /*if (_size == _capatity)
                {
                        cout << "哈希表已满!" << endl;
                        return false;
                }*/
                 //考虑到载荷因子在0.7~0.8一下比较好，这样检查容量比较好
                 if (10 * _size >= 8 * _capatity)
                {
                        _CheckCapatity();
                }
                 int index = _HashFunc(key );
                 while (_state[index] == EXIST )
                {
                        index++; //哈希冲突，找下一个位置
                         //最后一个位置有数据，从头开始找位置
                         if (index == _capatity)
                        {
                                index = 0;
                        }
                }
                 //哈希不冲突，直接放数据
                _table[index] = key;
                _state[index] = EXIST;
                _size++;
                 return true ;
        }
         //查找
         int Find(const K& key)
        {
                 int index = _HashFunc(key );
                 while (_state[index] != EMPTY )
                {
                         //找到元素
                         if (_table[index] == key &&_state[index] == EXIST)
                        {
                                 return index;
                        }
                         //如果算出的位置，不是要找的元素，index++;
                        index++;
                         //最后一个位置不是，就从头开始找
                         if (index == _capatity)
                        {
                                index = 0;
                        }
                }
                 return -1;
        }
         void print()
        {
                 /*for (int i = 0; i < _capatity; i++)
                {
                        if (_state[i] == EXIST)
                        {
                                printf("[%d]EXIST:%d\n",i, _table[i]);
                        }
                        else if (_state[i] == DELETE)
                        {
                                printf("[%d]DELETE:NULL\n", i, _table[i]);
                        }
                        else
                        {
                                printf("[%d]EMPTY:NULL\n", i);
                        }
                }*/
                 for (int i = 0; i < _capatity; i++)
                {
                         if (_state[i] == EXIST )
                        {
                                cout << i << "-"<< "EXIST:" << _table[i] << endl;
                        }
                         else if (_state[i] == DELETE)
                        {
                                cout << i << "-"<< "DELETE:" << "NULL" << endl;
                        }
                         else
                        {
                                cout << i << "-"<< "EMPTY:" << "NULL" << endl;
                        }
                }
        }
         //删除某一位置元素
         bool Remove(const K& key)
        {
                 int index = Find(key );//找到这个元素
                 //删除这个元素
                 if (index != -1)
                {
                        _state[index] = DELETE;
                        _size--;
                         return true ;
                }
                 return false ;
        }
protected:
         //算出数据在哈希表中的位置（哈希不冲突）
         /*int _HashFunc(const K& key)
        {
                return key%_capatity;
        }*/
         int _HashFunc(const K& key)
        {
                 HashFunc<K > ht;
                 return ht(key ) % _capatity;
        }
         //交换
         void _Swap(HashTable <K> tmp)
        {
                swap(_size, tmp._size);
                swap(_capatity, tmp._capatity);
                swap(_state, tmp._state);
                swap(_table, tmp._table);
        }
         //检查容量
         void _CheckCapatity()
        {
                 HashTable<K > tmp(2 * _capatity);
                 for (int i = 0; i < _capatity; i++)
                {
                        tmp.Insert(_table[i]);
                }
                _Swap(tmp);
        }
protected:
         K* _table;//数组
         State* _state;//状态数组
         size_t _size;//数组大小
         size_t _capatity;//数组的容量
};
