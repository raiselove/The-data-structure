template < class T>
class Symmetry
{
public:
        Symmetry( T* arr , size_t size)
                :_arr( new T [size*( size+1)/2])
                , _size( size*(size + 1)/2)
        {
                 for (int i = 0; i < size; i++)
                {
                         for (int j = 0; j < size; j++)
                        {
                                 if (i >= j)
                                {
                                        _arr[i*(i + 1) / 2 + j] = arr [i*size + j];
                                }
                        }
                }
        }
         void Print(size_t size)
        {
                 for (int i = 0; i < size; i++)
                {
                         for (int j = 0; j < size; j++)
                        {
                                 int row = i;
                                 int col = j;
                                 if (row < col)
                                {
                                        swap(row, col);
                                }
                                        cout << _arr[row*(row+ 1) / 2 + col] << " " ;
                        }
                        cout << endl;
                }
                cout << endl;
        }
protected:
         T *_arr;
         size_t _size;
};
