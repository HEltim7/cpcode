//fuck the shit balloom

#include <stdio.h>
#include <string.h>
char balloom[1000][1000], bin[1000][1000], *p[1000][1000];
int isnew, kind = -1, num[1000], point;
void judge(int i)
{
    int k, j;
    for (j = 0; j <= i; j++) //judge every word
    {
        int flag = 1;
        for (k = 0; k < strlen(balloom[i]) || k < strlen(bin[j]); k++) //judge a word
        {
            if (balloom[i][k] != bin[j][k])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            isnew = 0;
            point = j;
            break;
        }
    }
}

int issmaller(char *p1, char *tmp)
{

    for (;;)
    {
        if (*p1 == *tmp)
        {
            p1++;
            tmp++;
        }
        else if (*p1 < *tmp)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &balloom[i]);
        //isnew?
        isnew = 1;
        judge(i);
        if (isnew)
        {
            //write in
            kind++;
            for (int j = 0; j < strlen(balloom[i]); j++)
            {
                bin[kind][j] = balloom[i][j];
            }
            num[kind]++;
        }
        else
        {
            num[point]++;
        }
    }
    for (int i = 0; i <= kind; i++)
    {
        p[i][0] = &bin[i][0];
    }
    //sort
    char *tmp = NULL;
    for (int j = kind; j >= 0; j--)
    {
        for (int i = 0; i < j; i++)
        {
            if (num[i + 1] > num[i])
            {
                int t = num[i];
                num[i] = num[i + 1];
                num[i + 1] = t;
                tmp = p[i][0];
                p[i][0] = p[i + 1][0];
                p[i + 1][0] = tmp;
            }
        }
    }

    for (int i = 0; i < kind; i++)
    {
        if (num[i] == num[i + 1])
        {
            int end = i + 1, step = 2, max;
            while (num[end + 1] == num[i])
            {
                end++;
                step++;
            }
            char *tmp = p[i][0];
            for (; step > 1; i++)
            {
                for (int j = i + 1; j <= end; j++)
                {
                    if (issmaller(p[j][0], tmp))
                    {
                        tmp = p[j][0];
                        max = j;
                    }
                }
                if (max != 0)
                {
                    p[max][0] = p[i][0];
                    p[i][0] = tmp;
                }
                tmp = p[i + 1][0];
                step--;
            }
            i += step - 1;
        }
    }

    //output
    printf("%d\n", kind + 1);
    printf("%d\n", num[0]);
    puts(*p[0]);
    for (int i = 1; i <= kind; i++)
    {
        if (num[i] != num[i - 1])
        {
            printf("%d\n", num[i]);
        }
        puts(*p[i]);
    }

    return 0;
}