template <class T>
struct Node
{
         T _data;
         Node<T >*_next;
        Node( const T & x)
                :_data( x)
        {}
};
template <class T>
class Queue
{
public:
        Queue()
                : _head( NULL)
                , _tail( NULL)
                , _size(0)
        {}
         void Push(const T& x)
        {
                 if (_head == NULL )
                {
                        _head = _tail = new Node <T>( x);
                         //_tail->_next = NULL;
                        _size++;
                }
                 else
                {
                         Node<T >* temp = new Node< T>(x );
                        _tail->_next = temp;
                        _tail = temp;
                        _size++;
                }
        }
         void Pop()
        {
                 if (_head == NULL )
                {
                         return;
                }
                 else if (_head->_next == NULL)
                {
                         delete _head;
                        _head = _tail = NULL;
                        _size--;
                }
                 else
                {
                         Node<T > *cur = _head;
                        _head = _head->_next;
                         delete cur;
                        _size--;
                }
        }
         T& Front()
        {
                 return _head->_data;
        }
         T& Back()
        {
                 return _tail->_data;
        }
         size_t Size()
        {
                 return _size;
        }
         size_t Empty()
        {
                 return _size == 0;
        }
protected:
         Node<T >*_head;
         Node<T >*_tail;
         size_t _size;
};
