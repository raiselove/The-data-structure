template <class T>
class Stack
{
public:
        Stack()
                :_arr(NULL)
                , _size(0)
                , _capatity(0)
        {}
        Stack( const Stack & s)
                :_arr( new T [s._arr])
                , _size( s._size)
                , _capatity( s._size)
        {
                 for (int i = 0; i < _size; i++)
                {
                        _arr[i] = s._arr[i];
                }
        }
         /*Stack& operator=(const Stack& s)
        {
                if (this != &s)
                {
                        T*temp = new T[s._size];
                        for (int i = 0; i < s._size; i++)
                        {
                                temp[i] = _arr[i];
                        }
                        delete[] _arr;
                        _arr = temp;
                        _size = s._size;
                        _capatity = s._capatity;
                }
                return *this;
        }*/
         //现代写法
         Stack& operator=(Stack s)
        {
                swap( s._arr, _arr);
                _size = s._size;
                _capacity = s._capacity;
                 return *this ;
        }
        ~Stack()
        {
                 if (_arr)
                {
                         delete[] _arr;
                }
        }
         void Push(const T& x)
        {
                CheckCapatity();
                _arr[_size++] = x;
        }
         T&Top()
        {
                 return _arr[_size - 1];
        }
         void Pop()
        {
                 if (_size <= 0)
                {
                         return;
                }
                _size--;
        }
         size_t Empty()
        {
                 return _size == 0;
        }
         size_t Size()
        {
                 return _size;
        }
private:
         void CheckCapatity()
        {
                 if (_size == _capatity)
                {
                        _capatity = 2 * _capatity + 3;
                         T*temp = new T[_capatity];
                         for (int i = 0; i < _size; i++)
                        {
                                temp[i] = _arr[i];
                        }
                         delete[] _arr;
                        _arr = temp;
                }
        }
protected:
         T *_arr;
         size_t _size;
         size_t _capatity;
};
