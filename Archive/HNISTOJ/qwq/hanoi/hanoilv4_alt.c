#include <stdio.h>
#include <math.h>
#define MAX 1000000000000

int main()
{
    int i, j, disk = 100;
    unsigned long long step[disk + 1], min_step;
    step[1] = 1;
    printf("1\n");
    step[2] = 3;
    printf("3\n");
    step[3] = 5;
    printf("5\n");
    for (i = 4; i <= disk; i++)
    {
        min_step = MAX;
        for (j = 1; j < i - 1; j++)
        {
            if (min_step > 2 * step[j] + pow(2, i - j) - 1)
                min_step = 2 * step[j] + pow(2, i - j) - 1;
        }
        step[i] = min_step;
        printf("%d\n", step[i]);
    }
    return 0;
}