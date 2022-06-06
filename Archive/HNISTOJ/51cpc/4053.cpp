#include <iostream>
#include <stdio.h>
using namespace std;
int isly[10000];
int m1[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //平年
int m2[13] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; //闰年
int main()
{
    int n;
    char trash;
    void leap(int);
    cin >> n;
    int y[n], m[n], d[n], sum[n] = {0};
    for (int i = 0; i < n; i++)
    {
        scanf("%4d%1c%2d%1c%2d", &y[i], &trash, &m[i], &trash, &d[i]);
    }

    leap(1);

    //计算日期
    for (int j = 0; j < n; j++)
    {
        //计算年
        for (int i = 1; i < 18; i++)
        {
            if (isly[y[j] + i])
                sum[j] += 366;
            else
                sum[j] += 365;
        }
        //计算月&日
        if (!isly[y[j]])
        {
            for (int i = m[j] + 1; i < 13; i++)
                sum[j] += m1[i];
            sum[j] += m1[m[j]] - d[j];
        }
        else
        {
            for (int i = m[j] + 1; i < 13; i++)
                sum[j] += m2[i];
            sum[j] += m2[m[j]] - d[j];
        }

        if (!isly[y[j + 18]])
        {
            for (int i = m[j] - 1; i > 0; i--)
                sum[j] += m1[i];
            sum[j] += d[j];
        }
        else
        {
            for (int i = m[j] - 1; i > 0; i--)
                sum[j] += m2[i];
            sum[j] += d[j];
        }
    }

    //输出
    for (int i = 0; i < n; i++)
    {
        cout << sum[i] << endl;
    }

    return 0;
}

void leap(int y)
{
    for (y; y <= 10000; y++)
    {
        if (y % 4 == 0 && y % 100 != 0)
            isly[y] = 1;
        else if (y % 400 == 0 && y % 3200 != 0)
            isly[y] = 1;
    }
}