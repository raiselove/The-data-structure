//计数排序
void CountSort(int *a, int size)
{
         int min = a [0], max = a[0];
         int i = 0;
         for ( i = 0; i < size ; i++)
        {
                 if (min > a [i])
                {
                        min = a[i];//找出数组中最小的数
                }
                 if (max < a [i])
                {
                        max = a[i];//找出数组中的最大数
                }
        }
         int range = max - min + 1;
         int *count = new int[range];
         //初始化数组
         //memset(count, 0, sizeof(int)*range);
         for (i = 0; i < range; i++)
        {
                count[i] = 0;
        }
         //把数组a中数变成数组count中的0，1，2....
         for (i = 0; i < size ; i++)
        {
                 //把数组count中对应位置制成数字，代表这个位置有几个相同的数
                 //列如制成1，代表这个位置有一个数
                 //列如制成2，代表这个位置有两个相同的数
                count[ a[i] - min]++;
        }
         int j = 0;
         //把count中的数还原回数组a中，它就排好序了
         for (i = 0; i < range; i++)
        {
                 //重复了n次，就拿回去n次
                 while (count[i]>0)
                {
                         a[j++] = i + min;
                        count[i]--;
                }
        }
         delete[] count;
}
