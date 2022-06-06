//矩形面积交
#include <stdio.h>
int main()
{
    int xa1, xa2, xb1, xb2, ya1, ya2, yb1, yb2;
    int x, y;
    scanf("%d%d%d%d", &xa1, &ya1, &xa2, &ya2);
    scanf("%d%d%d%d", &xb1, &yb1, &xb2, &yb2);
    if (xb1 < xa1)
    {
        if (xb2 < xa1)
        {
            printf("0");
            return 0;
        }
        else if (xb2 < xa2)
        {
            x = xb2 - xa1;
        }
        else
        {
            x = xa2 - xa1;
        }
    }
    else if (xb1 < xa2)
    {
        if (xb2 < xa2)
        {
            x = xb2 - xb1;
        }
        else
        {
            x = xa2 - xb1;
        }
    }
    else
    {
        printf("0");
        return 0;
    }

    if (yb1 < ya1)
    {
        if (yb2 < ya1)
        {
            printf("0");
            return 0;
        }
        else if (yb2 < ya2)
        {
            y = yb2 - ya1;
        }
        else
        {
            y = ya2 - ya1;
        }
    }
    else if (yb1 < ya2)
    {
        if (yb2 < ya2)
        {
            y = yb2 - yb1;
        }
        else
        {
            y = ya2 - yb1;
        }
    }
    else
    {
        printf("0");
        return 0;
    }

    printf("%d", x * y);
    return 0;
}