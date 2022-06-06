//二维数组及指针形参变量的应用
#include <stdio.h>
int main()
{
    int i, j, data[5][5] = {0}, sum = 0, max = -32768, min = 32768;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            scanf("%d", data[i] + j);
            if (*(data[i] + j) > max)
            {
                max = *(data[i] + j);
            }
            if (*(data[i] + j) < min)
            {
                min = *(data[i] + j);
            }
            sum += *(data[i] + j);
        }
    }
    printf("sum=%d\n", sum);
    printf("max=%d\n", max);
    printf("max=%d,min=%d\n", max, min);
}