#pragma once

#include <assert.h>
enum Type
{
         HEAD,//头类型
         VALUE,//值类型
         SUB//字表类型
};
struct GeneralizedNode
{
         Type _type;
         GeneralizedNode *_next;
         union
        {
                 int _value;
                 GeneralizedNode* _sublink;
        };
        GeneralizedNode( Type type )
                :_type( type)
                , _next( NULL)
        {}
        GeneralizedNode( Type type , int value)
                :_type( type)
                , _next( NULL)
                , _value( value)
        {}
};
class Generalize
{
public:
        Generalize()
                :_head( NULL)
        {}
        Generalize( const char * arr)
        {
                _head = CreateGeneralize( arr);
        }
        Generalize( const Generalize & g)
        {
                _head = CopyList( g._head);
        }
         //现代写法
         //Generalize& operator=( Generalize g)
         //{
         //      swap(_head, g._head);
         //      return *this;
         //}
         //传统写法
         Generalize& operator=(const Generalize& g)
        {
                 if (this != &g)
                {
                         GeneralizedNode* tmp;
                        tmp=CopyList( g._head);
                        Destory(_head);
                        _head = tmp;
                }
                 return *this ;
        }
        ~Generalize()
        {
                Destory(_head);
        }
         size_t Size()
        {
                 return _size(_head);
        }
         size_t Depth()
        {
                 return _depth(_head);
        }
         void PrintList()
        {
                _PrintList(_head);
        }
protected:
         //打印广义表
         void _PrintList(GeneralizedNode * head)
        {
                 GeneralizedNode* cur = head ;
                 while (cur)
                {
                         if (cur->_type ==HEAD )
                        {
                                cout << "(";
                        }
                         else if (cur->_type == VALUE)
                        {
                                cout << ( char)cur->_value;
                                 if (cur->_next)
                                {
                                        cout << ",";
                                }
                        }
                         else if (cur->_type == SUB)
                        {
                                _PrintList(cur->_sublink);
                                 if (cur->_next)
                                {
                                        cout << ",";
                                }
                        }
                        cur = cur->_next;
                }
                cout << ")";
        }
         bool _IsValue(const char* arr)
        {
                 if (*arr >= '0'&&* arr <= '9'
                        || * arr>='a' &&*arr<= 'z'
                        || * arr>='A' &&*arr <= 'Z')
                {
                         return true ;
                }
                 else
                {
                         return false ;
                }
        }
         //创建广义表
         GeneralizedNode* CreateGeneralize(const char*& arr)
        {
                 assert(*arr == '(' );
                         arr++;
                 GeneralizedNode* head = new GeneralizedNode(HEAD );
                 GeneralizedNode* cur = head;
                 while (cur)
                {
                         if (_IsValue(arr ))
                        {
                                cur->_next = new GeneralizedNode(VALUE , *arr);
                                cur = cur->_next;
                                 arr++;
                        }
                         else if (*arr == '(')
                        {
                                 GeneralizedNode* subnode = new GeneralizedNode(SUB );
                                cur->_next = subnode;
                                cur = cur->_next;
                                subnode->_sublink = CreateGeneralize(arr );
                        }
                         else if (*arr == ')')
                        {
                                 arr++;
                                 return head;
                        }
                         else
                        {
                                 arr++;
                        }
                }
                 assert(false );
                 return head;
        }
         //拷贝广义表
         GeneralizedNode* CopyList(GeneralizedNode * head)
        {
                 GeneralizedNode* newhead = new GeneralizedNode(HEAD );
                 GeneralizedNode* newcur = newhead;
                 GeneralizedNode* cur = head ->_next;
                 while (cur)
                {
                         if (cur->_type == VALUE )
                        {
                                newcur->_next = new GeneralizedNode(VALUE , cur->_value);
                                newcur = newcur->_next;
                        }
                         else if (cur->_type == SUB)
                        {
                                 GeneralizedNode* subnode = new GeneralizedNode(SUB );
                                newcur->_next = subnode;
                                newcur = newcur->_next;
                                newcur->_sublink = CopyList(cur->_sublink);
                        }
                        cur = cur->_next;
                }
                 return newhead;
        }
         //释放广义表
         void Destory(GeneralizedNode * head)
        {
                 GeneralizedNode* cur = head ;
                 while(cur)
                {
                         GeneralizedNode* del = cur;
                         if (cur->_type == HEAD )
                        {
                                cur = cur->_next;
                        }
                         else if (cur->_type == VALUE)
                        {
                                cur = cur->_next;
                                 delete del;
                        }
                         else if (cur->_type == SUB)
                        {
                                Destory(cur->_sublink);
                                cur = cur->_next;
                        }
                }
        }
         //广义表值结点的多少
         size_t _size(GeneralizedNode * head)
        {
                 GeneralizedNode* cur = head ;
                 size_t size = 0;
                 while (cur)
                {
                         if (cur->_type == VALUE )
                        {
                                size++;
                        }
                         else if (cur->_type == SUB)
                        {
                                size += _size(cur->_sublink);
                        }
                        cur = cur->_next;
                }
                 return size;
        }
         //广义表深度
         size_t _depth(GeneralizedNode * head)
        {
                 size_t depth = 1;
                 GeneralizedNode* cur = head ;
                 while (cur)
                {
                         if (cur->_type == SUB )
                        {
                                 size_t count = _depth(cur->_sublink);
                                 if (count + 1 > depth)
                                {
                                        depth = count + 1;
                                }
                        }
                        cur = cur->_next;
                }
                 return depth;
        }
protected:
         GeneralizedNode* _head;
};
