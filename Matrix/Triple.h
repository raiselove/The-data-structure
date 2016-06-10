#include <vector>
#define ROW 6//宏定义行为6
#define COL 5//宏定义列为5
//三元组
template <class T>
struct Triple
{
         size_t _row;
         size_t _col;
         T _value;
         //构造函数
        Triple( int row ,int col,T& value)
                :_row( row)
                , _col( col)
                , _value( value)
        {}
        Triple()
                :_row(0)
                , _col(0)
                , _value(0)
        {}
};
//稀疏矩阵
template <class T>
class SparseMatrix
{
public:
         //构造函数
        SparseMatrix( T* arr , size_t row, size_t col, const T & invalid)
        {
                 for (int i = 0; i < row; i++)
                {
                         for (int j = 0; j < col; j++)
                        {
                                 if (arr [i*col + j] != invalid)
                                {
                                         //将数据储存在vector中
                                         Triple<T > temp(i, j, arr[i* col + j]);
                                        _arr.push_back(temp);
                                }
                        }
                }
        }
        SparseMatrix()
                :_arr( NULL)
        {}
         //普通转置
         SparseMatrix<T > TrasPortMatirx(T* arr, size_t row , size_t col , const T& invalid )
        {
                 SparseMatrix<T > tmp(arr,row,col,0);
                 size_t count = 0;
                 for (int i = 0; i < col; i++)
                {
                         for (int j = 0; j < _arr.size(); j++)
                        {
                                 if (_arr[j]._col == i)
                                {
                                        tmp._arr[count]._row = _arr[j]._col;
                                        tmp._arr[count]._col = _arr[j]._row;
                                        tmp._arr[count]._value = _arr[j]._value;
                                        count++;
                                }
                        }
                }
                 return tmp;
        }
         //快速转置
         SparseMatrix<T > FastTrasPortMatirx(int row,int col,const T& invalid)
        {
                 SparseMatrix<T > temp;
                temp._arr.resize(_arr.size());
                 //先确定转置后每一行元素的个数
                 vector<int > RowCounts;//为了确定每行元素的个数
                RowCounts.resize( col);
                RowCounts.assign( col, 0);//让RewCounts中的元素为0，size也为0
                 for (int i = 0; i < _arr.size(); i++)
                {
                        RowCounts[_arr[i]._col]++;
                }
         //在确定转置后矩阵每行元素在压缩矩阵中的初始位置
                 vector<int > RowStarts;
                RowStarts.resize( col);
                RowStarts.assign( col, 0);
                 //下一行元素的起始位置=上一行的元素个数+上一行元素的起始位置
                 for (int j = 0; j < col-1; j++)
                {
                        RowStarts[j + 1] = RowStarts[j] + RowCounts[j];
                }
                 //最后行列互换
                 size_t indx = 0;
                 while (indx < _arr.size())//快速定位
                { //RowStarts存放转置后每一行的开始位置，RowStart不断更新同行数据位置,转置后同一行数据的位置不断++，故用&
                         int& RowStart = RowStarts[_arr[indx]._col];
                        temp._arr[RowStart++] = Triple<T >(_arr[indx]._col, _arr[indx]._row, _arr[indx]._value);
                        indx++;
                }
                 /*for (int k = 0; k < _arr.size(); k++)
                                {
                                        temp._arr[RewStarts[_arr[k]._col]]._col = _arr[k]._row;
                                        temp._arr[RewStarts[_arr[k]._col]]._row = _arr[k]._col;
                                        temp._arr[RewStarts[_arr[k]._col]++]._value = _arr[k]._value;
                                }*/
                 return temp;
        }
         //打印函数
         void DisPlay(size_t row,size_t col,const T& invalid)
        {
                 size_t size = 0;
                 for (int i = 0; i < row; i++)
                {
                         for (int j = 0; j < col; j++)
                        {
                                 if (size < _arr.size()
                                        && _arr[size]._row == i
                                        &&_arr[size]._col == j)
                                {
                                        cout << _arr[size]._value << " " ;
                                        size++;
                                }
                                 else
                                {
                                        cout << invalid << " " ;
                                }
                        }
                        cout << endl;
                }
                cout << endl;
        }
protected:
         vector<Triple <T>> _arr;
};
