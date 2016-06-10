//合并数组
static void _MergeArr(int * arr, int left, int right , int* tmp)
{
         int begin1 = left ;
         int end = right ;
         int mid = left - (left - right)/2;
         int begin2 = mid + 1;
         int index = 0;
         //把左右两个数组的数从大到小放到tmp中
         while (begin1 <= mid&&begin2 <= end)
        {
                 if (arr [begin1] <= arr[begin2])
                {
                         tmp[index++] = arr [begin1++];
                }
                 else
                {
                         tmp[index++] = arr [begin2++];
                }
        }
         //左边数组长，把剩下数放到tmp中
         while (begin1 <= mid)
        {
                 tmp[index++] = arr [begin1++];
        }
         //右边数组长，把剩下的数放到tmp中
         while (begin2 <= end)
        {
                 tmp[index++] = arr [begin2++];
        }
         //把tmp中的数给arr
         for (int i = 0; i < index; i++)
        {
                 arr[left + i] = tmp[i];
        }
}
//递归调用
static void _MergeSort(int arr[], int left , int right, int *tmp )
{
         //把数组分成若干个子序列
         if (left < right)
        {
                 int mid = left - (left - right) / 2;
                _MergeSort( arr, left , mid, tmp);
                _MergeSort( arr, mid + 1, right , tmp);
                _MergeArr( arr, left , right, tmp);
        }
}
//归并排序
void MergeSort(int *arr, int size )
{
         int *tmp = new int[size];
         if (arr == NULL)
        {
                 return;
        }
        _MergeSort( arr, 0, size - 1, tmp);
         delete[] tmp;
}

  
