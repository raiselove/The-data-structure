#pragma once

#include <stack>
#include <queue>
template <class T>
struct BinaryTreeNode
{
         T _data;//结点值
         BinaryTreeNode<T > *_left;//左孩子
         BinaryTreeNode<T > *_right;//右孩子
        BinaryTreeNode( const T & x)
                :_data( x)
                , _left( NULL)
                , _right( NULL)
        {}
};
template <class T>
class BinaryTree
{
public:
        BinaryTree()
                :_root( NULL)
        {}
        BinaryTree( T *arr , size_t size, const T& invalid)
        {
                 size_t index = 0;
                _root = _CreateBinaryTree( arr, size ,index, invalid);
        }
        BinaryTree( const BinaryTree <T>& s)
        {
                _root = _CopyTree( s._root);
        }
         //传统写法
         BinaryTree<T >& operator=(const BinaryTree<T >& s)
        {
                 if (&s != this)
                {
                         BinaryTreeNode<T >*tmp;
                         tmp = _CopyTree( s._root);
                        _Destory(_root);
                        _root = tmp;
                }
                 return *this ;
        }
         //现代写法
         /*BinaryTree<T>& operator=(BinaryTree<T> s)
        {
                swap(_root, s._root);
                return *this;
        }*/
         /*~BinaryTree()
        {
                        _Destory(_root);
        }*/
         //前序遍历
         void PrevOrder()
        {
                _root = _prev_order(_root);
                cout << endl;
        }
         //中序遍历
         void InOrder()
        {
                _root = _in_order(_root);
                cout << endl;
        }
         //后序遍历
         void PostOrder()
        {
                _root = _post_order(_root);
                cout << endl;
        }
         //层序遍历
         void LevelOrder()
        {
                _root = _level_order(_root);
                cout << endl;
        }
         //结点数
         size_t Size()
        {
                 return _size(_root);
        }
         //深度
         size_t Depth()
        {
                 return _depth(_root);
        }
         //叶子结点个数
         size_t LeafSize()
        {
                 return _leaf_size(_root);
                cout << endl;
        }
         //第K层的结点
         size_t KLevelSize(size_t k)
        {
                 return _k_level_size(_root,k );
                cout << endl;
        }
protected:
         BinaryTreeNode<T >* _CreateBinaryTree(T *arr, size_t size ,size_t& index, const T& invalid)
        {
                 BinaryTreeNode<T > *root = NULL;
                 if (index < size&& arr[index ] != invalid)
                {
                        root = new BinaryTreeNode<T >(arr[index]);
                        root->_left = _CreateBinaryTree( arr, size , ++index, invalid );
                        root->_right = _CreateBinaryTree( arr, size , ++index, invalid );
                }
                 return root;
        }
         BinaryTreeNode<T >*_CopyTree(BinaryTreeNode< T>*root )
        {
                 if (root == NULL)
                {
                         return NULL ;
                }
                 BinaryTreeNode<T >*temp = new BinaryTreeNode<T >(root->_data);
                temp->_left = _CopyTree( root->_left);
                temp->_right = _CopyTree( root->_right);
                 return temp;
        }
         void _Destory(BinaryTreeNode <T>* root)
        {
                 if (root == NULL)
                {
                         return;
                }
                 if (root ->_left == NULL&& root->_right == NULL)
                {
                         delete root ;
                         root = NULL ;
                }
                 else
                {
                        _Destory( root->_left);
                        _Destory( root->_right);
                }
        }
         //前序遍历&&递归写法
         //BinaryTreeNode<T>* _prev_order(BinaryTreeNode<T>*root)
         //{
         //      if (root == NULL)
         //      {
         //              return 0;
         //      }
         //      //先根然后左最后右
         //      cout << root->_data << " ";
         //      root->_left  = _prev_order(root->_left);
         //      root->_right  = _prev_order(root->_right);
         //}
         //前序遍历&&非递归写法
         BinaryTreeNode<T >*_prev_order(BinaryTreeNode< T>*root )
        {
                 stack<BinaryTreeNode <T>*>s;
                 if (root == NULL)
                {
                         return 0;
                }
                s.push( root);
                 while (!s.empty())
                {
                         root = s.top();
                        cout << root->_data << " " ;
                        s.pop();
                         if (root ->_right  != NULL)
                        {
                                s.push( root->_right);
                        }
                         if (root ->_left != NULL)
                        {
                                s.push( root->_left);
                        }
                }
                 return root ;
        }
         //中序遍历&&递归写法
         //BinaryTreeNode<T>* _in_order(BinaryTreeNode<T>*root)
         //{
         //      if (root == NULL)
         //      {
         //              return 0;
         //      }
         //      //先左然后根最后右
         //      root->_left = _in_order(root->_left);
         //      cout << root->_data << " ";
         //      root->_right = _in_order(root->_right);
         //}
         //中序遍历&&非递归写法
         BinaryTreeNode<T >* _in_order(BinaryTreeNode <T>* root)
        {
                 stack<BinaryTreeNode <T>*>s;
                 if (root == NULL)
                {
                         return 0;
                }
                 BinaryTreeNode<T >*cur = root;
                 while (cur || !s.empty())
                {
                         while (cur)
                        {
                                s.push(cur);
                                cur = cur->_left;
                        }
                        cur = s.top();
                        cout << cur->_data << " ";
                        s.pop();
                         if (cur->_right == NULL )
                        {
                                cur= NULL;
                        }
                         else
                        {
                                cur = cur->_right;
                        }
                }
                 return root ;
        }
         //后序遍历&&递归算法
         //BinaryTreeNode<T>*_post_order(BinaryTreeNode<T>*root)
         //{
         //      if (root == NULL)
         //      {
         //              return 0;
         //      }
         //      //先左然后右最后根
         //      root->_left = _in_order(root->_left);
         //      root->_right = _in_order(root->_right);
         //      cout << root->_data << " ";
         //}
         //后序遍历&&非递归算法
         BinaryTreeNode<T >*_post_order(BinaryTreeNode< T>*root )
        {
                 stack<BinaryTreeNode <T>*>s;
                 if (root == NULL)
                {
                         return 0;
                }
                 BinaryTreeNode<T >*cur = root;
                 BinaryTreeNode<T >*prev = NULL;
                 while (cur || !s.empty())
                {
                         while (cur)
                        {
                                s.push(cur);
                                cur = cur->_left;
                        }
                        cur = s.top();
                         if (cur->_right == NULL ||cur->_right == prev)
                        {
                                cout << cur->_data << " ";
                                s.pop();
                                prev = cur;
                                cur = NULL;
                        }
                         else
                        {
                                cur = cur->_right;
                        }
                }
                 return root ;
        }
         //利用队列来层序遍历
         BinaryTreeNode<T >*_level_order(BinaryTreeNode< T>*root )
        {
                 queue<BinaryTreeNode <T>*> q;
                 if (root == NULL)
                {
                         return 0;
                }
                q.push( root);
                 while (!q.empty())
                {
                         if (q.front()->_left != NULL )
                        {
                                q.push(q.front()->_left);
                        }
                         if (q.front()->_right != NULL )
                        {
                                q.push(q.front()->_right);
                        }
                        cout << q.front()->_data << " ";
                        q.pop();
                }
                 return root ;
        }
         size_t _size(BinaryTreeNode <T>* root)
        {
                 if (root == NULL)
                {
                         return 0;
                }
                 return _size(root ->_left) + _size(root->_right) + 1;
        }
         size_t _depth(BinaryTreeNode <T>* root)
        {
                 size_t leftdepth = 0;
                 size_t rightdepth = 0;
                 if (root == NULL)
                {
                         return 0;
                }
                leftdepth = _depth( root->_left);
                rightdepth = _depth( root->_right);
                 if (leftdepth > rightdepth)
                {
                         return leftdepth + 1;
                }
                 else
                {
                         return rightdepth + 1;
                }
        }
         size_t _leaf_size(BinaryTreeNode <T>* root)
        {
                 if (root == NULL)
                {
                         return 0;
                }
                 if (root ->_left == NULL&& root->_right == NULL)
                {
                         return 1;
                }
                 else
                {
                         return _leaf_size(root ->_left) + _leaf_size(root->_right);
                }
        }
         size_t _k_level_size(BinaryTreeNode <T>* root,size_t k)
        {
                 if (root == NULL)
                {
                         return 0;
                }
                 if (k == 1)
                {
                         return 1;
                }
                 else
                {
                         return _k_level_size(root ->_left, k - 1) + _k_level_size(root->_right, k - 1);
                }
        }
protected:
         BinaryTreeNode<T > *_root;//根结点
};

