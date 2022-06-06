//优秀职员评定
#include <stdio.h>
int main()
{
    int t, i, p = 0, max = 0;
    scanf("%d", &t);
    int score[t][5], finscore[t];
    for (i = 0; i < t; i++)
    {
        scanf("%d%d%d%d%d", &score[i][0], &score[i][1], &score[i][2], &score[i][3], &score[i][4]);
        finscore[i] = score[i][0] + score[i][1] + score[i][2] + score[i][3] + score[i][4];
        if (finscore[i] < 85)
        {
            p++;
        }
        if (finscore[i] > max)
        {
            max = finscore[i];
        }
    }
    if (p == t)
    {
        printf("No");
    }
    else
    {
        printf("%d %d", p, max);
    }
    return 0;
}