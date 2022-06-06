//3n+1问题
#include <stdio.h>
int main()
{
    int m;
    scanf("%d", &m);
    int data[m], step[m];
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &data[i]);
        step[i] = 0;
    }
    for (int i = 0; i < m;)
    {
        if (data[i] == 1)
        {
            i++;
        }
        else if (data[i] % 2 == 0)
        {
            data[i] /= 2;
            step[i]++;
        }
        else
        {
            data[i] = 3 * data[i] + 1;
            step[i]++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        printf("%d\n", step[i]);
    }
    return 0;
}