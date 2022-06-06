#include <stdio.h>
int isly[2048] = {0};
int main()
{
    int birth, y, m, d, sum = 0;
    void leap(int);
    scanf("%d", &birth);
    d = birth % 100;
    m = (birth / 100) % 100;
    y = birth / 10000;
    leap(y);

    if (y < 2013)
    {
        int month[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        for (y; y < 2012; y++)
        {
            if (isly[y])
                sum += 366;
            else
                sum += 365;
        }

        for (int i = m + 1; i < 13; i++)
        {
            sum += month[i];
        }
        sum += (month[m] - d + 68);
    }
    else
    {
        if (m == 1)
        {
            sum += (31 - d + 28 + 9);
        }
        else if (m == 2)
        {
            sum += (28 - d + 9);
        }
        else if (m == 3)
        {
            sum += (9 - d);
        }
    }

    printf("%d", sum);
    return 0;
}

void leap(int y)
{
    for (y; y <= 2013; y++)
    {
        if (y % 4 == 0 && y % 100 != 0)
            isly[y] = 1;
        else if (y % 400 == 0 && y % 3200 != 0)
            isly[y] = 1;
    }
}