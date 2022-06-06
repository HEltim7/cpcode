//hanoi lv.3
//递归实现三柱汉诺塔
#include <stdio.h>
unsigned long long step;

int hanoi(int disk)
{
    if (disk == 1)
    {
        step++;
    }
    else
    {
        hanoi(disk - 1);
        hanoi(1);
        hanoi(disk - 1);
    }

    return 1;
}

int main()
{
    int disk;
    scanf("%d", &disk);
    hanoi(disk);
    printf("%lld", step);
    return 0;
}