//矩形的和
#include<stdio.h>
int main()
{
    int m,n,q,i,j;
    scanf("%d%d",&m,&n);
    int matrix[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    scanf("%d",&q);
    int rqst[q][2];
    for (i = 0; i < q; i++)
    {
        scanf("%d%d",&rqst[i][0],&rqst[i][1]);   
    }
    for ( i = 0; i < q; i++)
    {
        printf("%d\n",matrix[rqst[i][0]-1][rqst[i][1]-1]);
    }
    return 0;
}