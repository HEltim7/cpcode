//简单的汉诺塔游戏
#include<stdio.h>
#include<math.h>

int process(int n)
{
    return pow(2,n)-1;
}

int main()
{
    for (int i = 1; i <= 12; i++)
    {
        printf("%d\n",process(i));
    }
    return 0;
}