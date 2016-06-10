#include <vector>

//template<class K>
//size_t DefaultFunc(const K *str)
//{
//      register size_t hash = 0;
//      while (size_t ch = (size_t)*str++)
//      {
//              hash = hash * 131 + ch;
//      }
//      return hash;
//}
template<class K,class V>
struct HashTableNode
{
         K _key;
         V _value;
         HashTableNode* _next;
        HashTableNode( const K & key, const V & value)
                :_key( key)
                , _value( value)
                , _next( NULL)
        {}
};
template <class K, class V>
class HashTable
{
         typedef HashTableNode <K, V> Node;
public:
         //拷贝构造
        HashTable()
                :_table( NULL)
                , _size(0)
        {}
         //拷贝构造
        HashTable( const HashTable & ht)
        {
                _table.resize( ht._table.size());
                 for (int i = 0; i < ht._table.size(); i++)
                {
                         Node* cur = ht ._table[i];
                         while (cur)
                        {
                                 Node* tmp = new Node(cur->_key, cur->_value);
                                tmp->_next = _table[i];
                                _table[i] = tmp;
                                _size++;
                                cur = cur->_next;
                        }
                }
        }
         //赋值运算符的重载
         HashTable<K , V> operator=( HashTable<K ,V> ht)
        {
                 if (this != &ht)
                {
                        swap(_table, ht._table);
                        swap(_size, ht._size);
                }
                 return *this ;
        }
         //析构函数
        ~HashTable()
        {
                 if (_table.size())
                {
                         for (int i = 0; i < _table.size(); i++)
                        {
                                 Node* cur = _table[i];
                                 while (cur)
                                {
                                         Node* del = cur;
                                        cur = cur->_next;
                                         delete del;
                                        del = NULL;
                                }
                        }
                }
        }
         bool Insert(const K& key, const V& value)
        {
                 //是否需要扩容
                 if (_size == _table.size())
                {
                        _ExpandCapatity();
                }
                 size_t index = _HashFunc(key );
                 Node* cur = _table[index];
                 //防冗余
                 while (cur)
                {
                         if (cur->_key == key )
                        {
                                 return false ;
                        }
                        cur = cur->_next;
                }
                 //插入节点
                 Node* tmp = new Node( key, value );
                tmp->_next = _table[index];
                _table[index] = tmp;
                _size++;
                 return true ;
        }
         Node* Find(const K& key)
        {
                 size_t index = _HashFunc(key );
                 Node* cur = _table[index];
                 while (cur)
                {
                         if (cur->_key == key )
                        {
                                 return cur;
                        }
                        cur = cur->_next;
                }
                 return NULL ;
        }
         bool Remove(const K& key)
        {
                 size_t index = _HashFunc(key );
                 Node* cur = _table[index];
                 Node* prev = NULL ;
                 //找到要删除的元素
                 while (cur)
                {
                         if (cur->_key == key )
                        {
                                 break;
                        }
                        prev = cur;
                        cur = cur->_next;
                }
                 if (cur)
                {
                         //头删
                         if (cur == _table[index])
                        {
                                _table[index] = cur->_next;
                        }
                         //删除中间元素
                         else
                        {
                                 Node* next = cur->_next;
                                prev->_next = next;
                        }
                         delete cur;
                        cur = NULL;
                        _size--;
                         return true ;
                }
                 return false ;
        }
         void Print()
        {
                 for (int i = 0; i < _table.size(); i++)
                {
                         Node* cur = _table[i];
                        cout << i << ":";
                         while (cur)
                        {
                                cout << cur->_key << " ";
                                cout << cur->_value << " ";
                                cur = cur->_next;
                        }
                         if (_table[i] == NULL )
                        {
                                cout << "NULL";
                        }
                        cout <<endl;
                }
                cout << endl;
        }
protected:
         //算出应该链接到哈希桶的那个位置
         size_t _HashFunc(const K& key)
        {
                 return  key %_table.size();
        }
         //新的容量
         size_t _NewSize()
        {
                 // 使用素数表对齐做哈希表的容量，降低哈希冲突
                 const int _PrimeSize = 28;
                 static const unsigned long _PrimeList[_PrimeSize] =
                {
                        53ul, 97ul, 193ul, 389ul, 769ul,
                        1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
                        49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
                        1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
                        50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
                        1610612741ul, 3221225473ul, 4294967291ul
                };
                 for (int i = 0; i < _PrimeSize; i++)
                {
                         if (_PrimeList[i]>_table.size())
                        {
                                 return _PrimeList[i];//按照素数表来设置容量大小
                        }
                }
                 //当需要的容量超过素数表的最大容量，我们就按照最大的来扩容
                 return _PrimeList[_PrimeSize - 1];
        }
         //哈希桶扩张容量
         void _ExpandCapatity()
        {
                 //开辟一个新的更大容量哈希桶
                 size_t newsize = _NewSize();
                 vector<Node *> newtable;
                newtable.resize(newsize);
                 //把原来哈希桶中的元素再下来，插入到新的哈希桶
                 for (int i = 0; i < _table.size(); i++)
                {
                         Node* cur = _table[i];
                         while (cur)
                        {
                                 Node* tmp = cur;
                                 int index = _HashFunc(tmp->_key);
                                 //头插法
                                tmp->_next = newtable[index];
                                newtable[index] = tmp;
                                cur = cur->_next;
                        }
                        _table[i] = NULL;
                }
                _table.swap(newtable);
        }
protected:
         vector<Node *> _table;
         size_t _size;//数据的多少
};
