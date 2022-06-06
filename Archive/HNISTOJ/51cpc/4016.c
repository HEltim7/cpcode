//餐厅
#include <stdio.h>
int main()
{
    int n, mon, di_0, di_1 = 0, num = 0;
    int customer[32768];
    scanf("%d%d%d", &n, &mon, &di_0);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &customer[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (customer[i] == 1)
        {
            if (mon > 0)
            {
                mon--;
            }
            else if (di_0 > 0)
            {
                di_0--;
                di_1++;
            }
            else if (di_1 > 0)
            {
                di_1--;
            }
            else
            {
                num++;
            }
        }
        else
        {
            if (di_0 > 0)
            {
                di_0--;
            }
            else
            {
                num += 2;
            }
        }
    }
    printf("%d", num);
}