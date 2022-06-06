//hanoi lv.4
//递归实现4柱汉诺塔
#include<stdio.h>
unsigned long long step;

void hanoi_lv4(int disk)
{
    if (disk==3)
    {
        step+=5;
    }
    else
    {
        for (int i = 1; i < disk; i++)//寻找并取最小的hanoi
        {
            hanoi_lv4(disk-i);

        }
        
    }

}

void hanoi(int disk)
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

}

int main()
{
    int disk;
    scanf("%d",&disk);
    switch (disk)
    {
    case 1:
        printf("1");
        return 0;
    case 2:
        printf("3");
        return 0;
    case 3:
        printf("5");
        return 0;
    default:
        break;
    }
    hanoi_lv4(disk);
    printf("%d",step);
    return 0;
}