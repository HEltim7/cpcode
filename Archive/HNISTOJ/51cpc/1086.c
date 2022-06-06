//2出现的次数
#include <stdio.h>
int extract(long long inp)
{
    int n2 = 0;
    for (inp; inp > 0; inp /= 10)
    {
        if (inp % 10 == 2)
        {
            n2++;
        }
    }
    return n2;
}
int main()
{
    int i, extract(long long);
    long long num;
    scanf("%lld", &num);
    printf("%d", extract(num));
    return 0;
}