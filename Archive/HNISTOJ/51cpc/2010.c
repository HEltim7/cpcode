//一维数组应用
#include <stdio.h>
int main()
{
    int name[5];
    float avg[5], grade[5][3];
    for (int i = 0; i < 5; i++)
    {
        scanf("%d%f%f%f", &name[i], &grade[i][0], &grade[i][1], &grade[i][2]);
        avg[i] = (grade[i][0] + grade[i][1] + grade[i][2]) * 1. / 3;
    }
    for (int j = 0; j < 4; j++)
    {
        for (int i = 0; i < 4; i++)
        {
            if (avg[i] < avg[i + 1])
            {
                //头铁交换
                avg[i] += avg[i + 1];
                avg[i + 1] = avg[i] - avg[i + 1];
                avg[i] = avg[i] - avg[i + 1];

                grade[i][0] += grade[i + 1][0];
                grade[i + 1][0] = grade[i][0] - grade[i + 1][0];
                grade[i][0] = grade[i][0] - grade[i + 1][0];

                grade[i][1] += grade[i + 1][1];
                grade[i + 1][1] = grade[i][1] - grade[i + 1][1];
                grade[i][1] = grade[i][1] - grade[i + 1][1];

                grade[i][2] += grade[i + 1][2];
                grade[i + 1][2] = grade[i][2] - grade[i + 1][2];
                grade[i][2] = grade[i][2] - grade[i + 1][2];

                name[i] += name[i + 1];
                name[i + 1] = name[i] - name[i + 1];
                name[i] = name[i] - name[i + 1];
            }
        }
    }
    printf("Num     C1      C2      C3      Ave\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%-8d%-8.2f%-8.2f%-8.2f%-8.2f\n", name[i], grade[i][0], grade[i][1], grade[i][2], avg[i]);
    }
    return 0;
}