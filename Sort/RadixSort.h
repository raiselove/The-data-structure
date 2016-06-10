//获取最大位数
static int GetMaxRadix(int * a, int size)
{
         int radix = 10;
         int count = 1;
         for (int i = 0; i < size; i++)
        {
                 //注意这里必须是">=",假如你的最大数是100，如果
                 //没有“=”的话，你获取最大位就是两位
                 while (a [i]>=radix)
                {
                        radix *= 10;
                        count++;
                }
        }
         return count;
}
static void _RadixSort(int* a, int size, int divisor , int* tmp)
{
         int count[10] = { 0 };
         int start[10] = { 0 };
         //如果你处理的是个位，count代表就是数据个位在
         //count对应位置出现的个数。十位，百位类似。
         for (int i = 0; i < size; i++)
        {
                 int num1 = a [i] / divisor;
                count[num1 % 10]++;
        }
         //个位，十位，百位等出现的起始位置
         for (int j = 1; j < 10; j++)
        {
                start[j] = start[j - 1] + count[j - 1];
        }
         //根据start，将a中的数据放在tmp中,已排好序
         for (int k = 0; k < size; k++)
        {
                 int num2 = a [k] / divisor;
                 tmp[start[num2 % 10]++] = a [k];
        }
         //把排好序的数据放回a中
         for (int n = 0; n < size; n++)
        {
                 a[n] = tmp [n];
        }
}
void RadixSort(int *arr, int size )
{
         assert(arr );
         int *tmp = new int[size];
         int n = GetMaxRadix(arr , size);
         for (int i = 1; i <= n; i++)
        {
                 int divisor = 1;
                 int k = i;
                 while (--k)
                {
                        divisor *= 10;
                }
                _RadixSort( arr, size , divisor, tmp);
        }
         delete[] tmp;
}
