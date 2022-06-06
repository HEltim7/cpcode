//明明的随机数
#include <stdio.h>
int main()
{
    int n, i, j, same = 0;
    scanf("%d", &n);
    int data[n];
    for (i = 0; i < n - same; i++)
    {
        scanf("%d", &data[i]);
        //去重
        for (j = 0; j < i; j++)
        {
            if (data[j] == data[i])
            {
                i--;
                same++;
                break;
            }
        }
    }
    //排序
    for (i = n - same - 1; i >= 0; i--)
    {
        for (j = 0; j < i; j++)
        {
            if (data[j] > data[j + 1])
            {
                data[j] += data[j + 1];
                data[j + 1] = data[j] - data[j + 1];
                data[j] = data[j] - data[j + 1];
            }
        }
    }
    printf("%d\n", n - same);
    for (i = 0; i < n - same; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}