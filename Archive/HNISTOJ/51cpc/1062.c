//最多字符
#include <stdio.h>
#include <string.h>
int main()
{
    int alpha[52] = {0};
    int i;
    int max[2] = {0}, j = 0;
    char *p1, maxalpha = ' ';
    char str[2][1000];
    gets(str[0]);
    gets(str[1]);
    for (j = 0; j < 2; j++)
    {
        for (p1 = &str[j][0]; p1 <= &str[j][strlen(str[j])]; p1++)
        {
            switch (*p1)
            {
            case 'a':
                alpha[0]++;
                break;
            case 'b':
                alpha[1]++;
                break;
            case 'c':
                alpha[2]++;
                break;
            case 'd':
                alpha[3]++;
                break;
            case 'e':
                alpha[4]++;
                break;
            case 'f':
                alpha[5]++;
                break;
            case 'g':
                alpha[6]++;
                break;
            case 'h':
                alpha[7]++;
                break;
            case 'i':
                alpha[8]++;
                break;
            case 'j':
                alpha[9]++;
                break;
            case 'k':
                alpha[10]++;
                break;
            case 'l':
                alpha[11]++;
                break;
            case 'm':
                alpha[12]++;
                break;
            case 'n':
                alpha[13]++;
                break;
            case 'o':
                alpha[14]++;
                break;
            case 'p':
                alpha[15]++;
                break;
            case 'q':
                alpha[16]++;
                break;
            case 'r':
                alpha[17]++;
                break;
            case 's':
                alpha[18]++;
                break;
            case 't':
                alpha[19]++;
                break;
            case 'u':
                alpha[20]++;
                break;
            case 'v':
                alpha[21]++;
                break;
            case 'w':
                alpha[22]++;
                break;
            case 'x':
                alpha[23]++;
                break;
            case 'y':
                alpha[24]++;
                break;
            case 'z':
                alpha[25]++;
                break;
            case 'A':
                alpha[26]++;
                break;
            case 'B':
                alpha[27]++;
                break;
            case 'C':
                alpha[28]++;
                break;
            case 'D':
                alpha[29]++;
                break;
            case 'E':
                alpha[30]++;
                break;
            case 'F':
                alpha[31]++;
                break;
            case 'G':
                alpha[32]++;
                break;
            case 'H':
                alpha[33]++;
                break;
            case 'I':
                alpha[34]++;
                break;
            case 'J':
                alpha[35]++;
                break;
            case 'K':
                alpha[36]++;
                break;
            case 'L':
                alpha[37]++;
                break;
            case 'M':
                alpha[38]++;
                break;
            case 'N':
                alpha[39]++;
                break;
            case 'O':
                alpha[40]++;
                break;
            case 'P':
                alpha[41]++;
                break;
            case 'Q':
                alpha[42]++;
                break;
            case 'R':
                alpha[43]++;
                break;
            case 'S':
                alpha[44]++;
                break;
            case 'T':
                alpha[45]++;
                break;
            case 'U':
                alpha[46]++;
                break;
            case 'V':
                alpha[47]++;
                break;
            case 'W':
                alpha[48]++;
                break;
            case 'X':
                alpha[49]++;
                break;
            case 'Y':
                alpha[50]++;
                break;
            case 'Z':
                alpha[51]++;
                break;
            default:
                break;
            }
        }
        for (i = 51; i > 0; i--)
        {
            if (alpha[i - 1] > max[j])
            {
                max[j] = alpha[i - 1];
                if (i < 27)
                {
                    maxalpha = (int)'a' + i - 1;
                }
                else
                {
                    maxalpha = (int)'A' + i - 27;
                }
            }
        }
        printf("%c ", maxalpha);
        printf("%d\n", max[j]);
        for (i = 0; i < 52; i++)
        {
            alpha[i] = 0;
        }
        max[j] = 0;
        maxalpha = ' ';
    }
    return 0;
}