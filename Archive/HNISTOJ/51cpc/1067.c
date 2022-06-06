//总分排序
#include <stdio.h>
int main()
{
    int p, ptmp, i, change(int, int);
    scanf("%d", &p);
    char name[p][100],id[p][100];
    int grade[p][5], total[p], rank[p], totaltmp[p];
    ptmp = p;
    for (i = 0; i < p; i++) //编序
    {
        rank[i] = i;
    }
    for (p = 0; p < ptmp; p++) //输入数据
    {
        scanf("%s",&name[p]);
        scanf("%s",&id[p]);
        scanf("%d%d%d%d%d", &grade[p][0], &grade[p][1], &grade[p][2], &grade[p][3], &grade[p][4]);
        total[p] = grade[p][0] + grade[p][1] + grade[p][2] + grade[p][3] + grade[p][4];
        totaltmp[p] = total[p];
    }
    for (p = ptmp; p > 0; p--)//排序输出
    {
        for (i = 0; i < p - 1; i++)
        {
            if (totaltmp[i + 1] < totaltmp[i])
            {
                totaltmp[i + 1]+=totaltmp[i];
                totaltmp[i]=totaltmp[i + 1]-totaltmp[i];
                totaltmp[i + 1]=totaltmp[i + 1]-totaltmp[i];
                rank[i+1]+=rank[i];
                rank[i]=rank[i+1]-rank[i];
                rank[i+1]=rank[i+1]-rank[i];
            }
        }
        i=rank[i];
        printf("%s",name[i]);
        printf(" %s ", id[i]);
        printf("total=%d\n",total[i]);
    }
    return 0;
}