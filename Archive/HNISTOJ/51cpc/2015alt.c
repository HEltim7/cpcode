//递归程序设计3
#include <stdio.h>

int main()
{
    int i, input(), data[10];
    for (i = 0; i < 10; i++)
    {
        data[i] = input();
    }
    for (i = 9; i >= 0; i--)
    {

        for (int j = 0; j < i; j++)
        {
            if (data[j + 1] < data[j])
            {
                data[j + 1] += data[j];
                data[j] = data[j + 1] - data[j];
                data[j + 1] = data[j + 1] - data[j];
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", data[i]);
    }
    return 0;
}
int input()
{
    int ip;
    {
        scanf("%d", &ip);
        return ip;
    }
}