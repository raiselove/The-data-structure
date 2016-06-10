#pragma once
template <class K, class V>
struct SearchBinaryTreeNode
{
         SearchBinaryTreeNode<K , V>*_left;
         SearchBinaryTreeNode<K , V>*_right;
         K _key;
         V _value;
        SearchBinaryTreeNode( const K & key, const V & value)
                :_key( key)
                , _value( value)
                , _left( NULL)
                , _right( NULL)
        {}
};

template <class K, class V>
class SearchBinaryTree
{
         typedef SearchBinaryTreeNode <K, V> Node;
public:
        SearchBinaryTree()
                :_root( NULL)
        {}
         //插入-非递归
         bool Insert(const K& key, const V& value)
        {
                 //判空
                 if (_root == NULL )
                {
                        _root = new Node (key, value);
                }
                 //找到要插入的位置
                 Node* cur = _root;
                 Node*parent = NULL ;
                 while (cur)
                {
                         if (cur->_key > key )
                        {
                                parent = cur;
                                cur = cur->_left;
                        }
                         else if (cur->_key < key)
                        {
                                parent = cur;
                                cur = cur->_right;
                        }
                         else
                        {
                                 return false ;
                        }
                }
                 Node*tmp = new Node( key, value );//新建一个节点
                 //节点的值小于插入位置的父节点，插到左边
                 if (parent->_key > key )
                {
                         Node* left = parent->_left;
                        parent->_left = tmp;
                         if (left)
                        {
                                 if (tmp->_key > left->_key)
                                {
                                        tmp->_left = left;
                                }
                                 else
                                {
                                        tmp->_right = left;
                                }
                        }
                }
                 //节点的值大于等于插入位置的父节点，插到右边
                 else
                {
                         Node* right = parent->_right;
                        parent->_right = tmp;
                         if (right)
                        {
                                 if (tmp->_key > right->_key)
                                {
                                        tmp->_left = right;
                                }
                                 else
                                {
                                        tmp->_right = right;
                                }
                        }
                }
                 return true ;
        }
         //插入-递归
         bool Insert_R(const K& key, const V& value)
        {
                 return _Insert_R(_root, key , value);
        }
         //查找-非递归
         Node* Find(const K& key)
        {
                 Node* cur = _root;
                 while (cur)
                {
                         if (cur->_key > key )
                        {
                                cur = cur->_left;
                        }
                         else if (cur->_key < key)
                        {
                                cur = cur->_right;
                        }
                         else
                        {
                                 return cur;
                        }
                }
                 return NULL ;
        }
         //查找-递归
         Node* Find_R(const K& key)
        {
                _root = _Find_R(_root, key);
        }
         //删除某一个位置的节点-非递归
         bool Rmove(const K& key)
        {
                 //判空
                 if (_root == NULL )
                {
                         return false ;
                }
                 //一个节点
                 if (_root->_left == NULL &&_root->_right == NULL)
                {
                         if (_root->_key == key )
                        {
                                 delete _root;
                                _root = NULL;
                                 return true ;
                        }
                         return false ;
                }
                 //多个节点
                 Node* cur = _root;
                 Node* parent = NULL ;
                 while (cur)
                {
                         //找到节点
                         if (cur->_key > key )
                        {
                                parent = cur;
                                cur = cur->_left;
                        }
                         else if (cur->_key < key)
                        {
                                parent = cur;
                                cur = cur->_right;
                        }
                         else
                        {
                                 Node* del = cur;
                                 //左子树为空
                                 if (cur->_left == NULL )
                                {
                                         if (parent == NULL )
                                        {
                                                cur = cur->_right;
                                        }
                                         //删除左子数的节点
                                         if (parent->_key > cur->_key)
                                        {
                                                parent->_left = cur->_right;
                                        }
                                         //删除右子数的节点
                                         if (parent->_key < cur->_key)
                                        {
                                                parent->_right = cur->_right;
                                        }
                                }
                                 //右子树为空
                                 else if (cur->_right == NULL)
                                {
                                         if (parent == NULL )
                                        {
                                                cur = cur->_left;
                                        }
                                         //删除左子数的节点
                                         if (parent->_key > cur->_key)
                                        {
                                                parent->_left = cur->_left;
                                        }
                                         //删除右子数的节点
                                         if (parent->_key < cur->_key)
                                        {
                                                parent->_right = cur->_left;
                                        }
                                }
                                 //左右子数都不为空
                                 else
                                {
                                         Node* RFrist = cur->_right;//右边第一个节点
                                         //右边第一个节点的左节点为空
                                                 if (RFrist->_left == NULL )
                                                {
                                                        swap(cur->_key, RFrist->_key);
                                                        swap(cur->_value, RFrist->_value);
                                                        del = RFrist;
                                                        cur->_right = RFrist->_right;
                                                }
                                                 //右边第一个节点的左节点不为空
                                                 else
                                                {
                                                         while (RFrist->_left)
                                                        {
                                                                parent = RFrist;
                                                                RFrist = RFrist->_left;
                                                        }
                                                        swap(cur->_key, RFrist->_key);
                                                        swap(cur->_value, RFrist->_value);
                                                        del = RFrist;
                                                        parent->_left = RFrist->_right;
                                                }
                                }
                                 delete del;
                                del = NULL;
                                 return true ;
                        }
                }
                 return false ;
        }
         //删除某一个位置的节点-递归
         bool Rmove_R(const K& key)
        {
                 return _Rmove_R(_root, key );
        }
         void InOrder()
        {
                _InOrder(_root);
                cout << endl;
        }
protected:
         void _InOrder(Node * root)
        {
                 if (root == NULL)
                {
                         return;
                }
                 _InOrder( root->_left);
                cout << root->_key << " " ;
                 _InOrder( root->_right);
        }
         bool _Insert_R(Node *& root, const K & key, const V& value )
        {
                 if (root == NULL)
                {
                         root = new Node( key, value );
                         return true ;
                }
                 if (root ->_key > key)
                {
                         return _Insert_R(root ->_left, key, value);
                }
                 else if (root->_key < key)
                {
                         return _Insert_R(root ->_right, key, value);
                }
                 else
                {
                         return false ;
                }
        }
         Node* _Find_R(Node * root, const K & key)
        {
                 if (root == NULL)
                {
                         return NULL ;
                }
                 if (root ->_key > key)
                {
                         root->_left = _Find_R(root ->_left, key);
                }
                 else if (root->_key < key)
                {
                         root->_right = _Find_R(root ->_right, key);
                }
                 else
                {
                         return root ;
                }
        }
         bool _Rmove_R(Node *& root, const K & key)
        {
                 if (root == NULL)
                {
                         return false ;
                }
                 if (root ->_left == NULL&& root->_right == NULL)
                {
                         if (root ->_key == key)
                        {
                                 delete root ;
                                 root = NULL ;
                                 return true ;
                        }
                         return false ;
                }
                 if (root ->_key > key)
                {
                        _Rmove_R( root->_left, key );
                }
                 else if (root->_key < key)
                {
                        _Rmove_R( root->_right, key );
                }
                 else
                {
                         //root和前面roo->_left或root->_right是一样的，因为传的是引用
                         Node* del = root ;
                         if (root ->_left == NULL)
                        {
                                 root = root ->_right;
                                 delete del;
                                del = NULL;
                                 return true ;
                        }
                         //root和前面roo->_left或root->_right是一样的，因为传的是引用
                         else if (root->_right == NULL)
                        {
                                 root = root ->_left;
                                 delete del;
                                del = NULL;
                                 return true ;
                        }
                         else
                        {
                                 Node* RFrist = root ->_right;
                                 while (RFrist->_left)
                                {
                                        RFrist = RFrist->_left;
                                }
                                swap( root->_key, RFrist->_key);
                                swap( root->_value, RFrist->_value);
                                 //这里的递归调用root->_right,就明显体现了引用的好处。
                                _Rmove_R( root->_right, key );
                                 return true ;
                        }
                }
                 return false ;
        }
protected:
         Node* _root;
};
