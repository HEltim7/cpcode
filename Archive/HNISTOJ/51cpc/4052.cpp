#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char str[1000], word[100][100], s1[100], s2[100], s3[100];

int main()
{
    s1[0] = 'b';
    s1[1] = 'o';
    s1[2] = 'w';
    s1[3] = 'l';

    s2[0] = 'f';
    s2[1] = 'o';
    s2[2] = 'r';
    s2[3] = 'k';

    s3[0] = 'c';
    s3[1] = 'h';
    s3[2] = 'o';
    s3[3] = 'p';
    s3[4] = 's';
    s3[5] = 't';
    s3[6] = 'i';
    s3[7] = 'c';
    s3[8] = 'k';
    s3[9] = 's';

    gets(str);
    int i = 0, j = 0, num = 1;
    str[strlen(str)] = ' ';
    do
    {
        word[0][i++] = str[j++];
    } while (str[i] != ' ');
    for (int k = 0; j < strlen(str) - 1; j++)
    {
        i = 0;
        k++;
        if (str[j] == ' ')
        {
            while (str[j + 1] != ' ')
            {
                word[k][i++] = str[++j];
            }
            num++;
        }
    }
    for (int i = 0; i < num; i++)
    {
        int flag = 1;
        for (int j = 0; j < strlen(word[i]); j++)
        {
            if (word[i][j] != s1[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
        {
            flag = 1;
            for (int j = 0; j < strlen(word[i]); j++)
            {
                if (word[i][j] != s2[j])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag == 0)
        {
            flag = 1;
            for (int j = 0; j < strlen(word[i]); j++)
            {
                if (word[i][j] != s3[j])
                {
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            cout << word[i] << ' ';
        }
    }

    return 0;
}