#include <stdio.h>
int num[1024];
int step;
int main()
{
    long long alpha;
    scanf("%lld", &alpha);
    if (alpha < 0)
        alpha = -alpha;

    for (;;)
    {
        if (alpha < 10)
        {
            printf("%lld", alpha);
            return 0;
        }
        else
        {
            int i;
            for (i = 0; alpha != 0; i++)
            {
                num[i] = alpha % 10;
                if (num[i] == 0)
                {
                    i--;
                }

                alpha /= 10;
            }
            i--;
            for (alpha = 1; i >= 0; i--)
            {
                alpha *= num[i];
            }
        }
    }
}