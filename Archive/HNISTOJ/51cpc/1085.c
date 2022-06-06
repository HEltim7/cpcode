#include <stdio.h>
int extract(int inp)
{
    int n0 = 0;
    for (inp; inp > 0; inp /= 10)
    {
        if (inp % 10 == 0)
        {
            n0++;
        }
    }
    return n0;
}
int main()
{
    int num, i, extract(int);
    scanf("%d", &num);
    if (num == 0)
    {
        printf("1");
        return 0;
    }
    printf("%d", extract(num));
}