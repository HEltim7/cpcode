//与3和5无关的数
#include <stdio.h>
int main()
{
    int a, test(int), sum = 0;
    scanf("%d", &a);
    int data[a];
    for (int i = 0; i < a; i++)
    {
        data[i] = 0;
    }
    for (int i = 1; i <= a; i++)
    {
        if (test(i))
        {
            data[i]=i;
            sum += (data[i]*data[i]);
        }
    }
    printf("%d", sum);
    return 0;
}
int test(int i)
{
    //判断是否整除
    if (i % 3 == 0 || i % 5 == 0)
    {
        return 0;
    }
    //分离位数
    int num[32] = {0}, round = 0;
    for (int j = 0; i != 0; j++)
    {
        num[j] = i % 10;
        i /= 10;
        round++;
    }
    for (int j = 0; j < round; j++)
    {
        if (num[j] == 3 || num[j] == 5)
            return 0;
    }
    return 1;
}