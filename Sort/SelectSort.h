#include<assert.h>
void SelectSort(int *arr, int size )
{
         assert(arr );
         int min;
         for (int i = 0; i < size; i++)
        {
                min = i;
                 //选出最小的数，把最小数的下标给成min
                 for (int j = i + 1; j < size ; j++)
                {
                         if (arr [j]< arr[min])
                        {
                                min = j;
                        }
                }
                 //把最小的数放在i位置
                 int tmp = arr [i];
                 arr[i] = arr [min];
                 arr[min] = tmp;
        }
}
