#include <stdio.h>
long int a[30];
long int b[30];
long int T;
int n;
long int sum = 0;
void f(int long t, int pos, int i)
{
    int j;

    if (t == T && pos != 0 && i < 1) //终止条件 注意全部遍历完再进行判断(防止 -1 1 -2 2 3 -3的特例) 并且 不能不选
    {
        sum++;
        for (j = pos - 1; j >= 0; j--) //倒着遍历倒着输出
            printf("%ld ", b[j]);
        printf("\n");
    }
    else
    {
        if (i < 1)
            return; //遍历到数组第一项还未满足t==T;则返回

        f(t, pos, i - 1);
        t += a[i];
        b[pos] = a[i];
        f(t, pos + 1, i - 1);
        t -= a[i];
    }
}
int main()
{
    int i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        scanf("%ld", &a[i]);
    scanf("%ld", &T);
    f(0, 0, n);
    printf("%d\n", sum);
    return 0;
}