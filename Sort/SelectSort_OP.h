void SelectSort_OP(int *arr, int size )
{
         assert(arr );
         int left = 0;
         int right = size - 1;
         while (left < right)
        {
                 int min = left;
                 int max = right;
                 //选出最大和最小的放在两边，然后缩小区间，循环
                 for (int i = min; i < right; i++)
                {
                         if (arr [i] < arr[min])
                        {
                                swap( arr[i], arr [min]);
                        }
                         else if (arr[i]> arr[max])
                        {
                                swap( arr[i], arr [max]);
                        }
                }
                ++left;
                --right;
        }
}
