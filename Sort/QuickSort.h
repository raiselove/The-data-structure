int SingleSort(int *a, int left, int right)
{
assert(a);
int tmp = a[right];//临时变量保存值
while (left < right)
{
//找左边大于等于tmp的数
while (left < right&&tmp >= a[left])
{
left++;
}
if (left < right)
{
a[right--] = a[left];//把值给右边，然后--
}
//找右边小于等于tmp的值
while (left < right&&tmp <= a[right])
{
right--;
}
if (left < right)
{
a[left++] = a[right];//把值给左边，然后++
}
}
a[left] = tmp;
return left;
}
void QuickSort(int *arr, int left, int right)
{
if (arr == NULL)
{
return;
}
if (left < right)
{
//递归调用
int div = SingleSort(arr, left, right);
QuickSort(arr, left, div - 1);
QuickSort(arr, div + 1, right);
}
}
