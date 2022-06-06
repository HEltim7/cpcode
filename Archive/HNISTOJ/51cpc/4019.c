//小红搬新
#include <stdio.h>
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int plugs[m];

    for (int i = 0; i < m; i++)
    {
        scanf("%d", &plugs[i]);
    }

    if (n == 1)
    {
        printf("0");
        return 0;
    }

    for (int i = m - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (plugs[j + 1] > plugs[j])
            {
                plugs[j + 1] += plugs[j];
                plugs[j] = plugs[j + 1] - plugs[j];
                plugs[j + 1] = plugs[j + 1] - plugs[j];
            }
        }
    }
    int used;
    for (used = 0; used <= m - 1; used++)
    {
        n -= plugs[used];
        if (used >= 1)
        {
            n++;
        }

        if (n <= 0)
        {
            printf("%d", used + 1);
            return 0;
        }
    }
    printf("Impossible");
    return 0;
}