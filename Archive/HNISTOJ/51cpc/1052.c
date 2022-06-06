//五子棋盘
#include<stdio.h>
int main()
{
    int n,m,q,i,j;
    scanf("%d%d",&n,&m);
    scanf("%d",&q);
    int board[n][m];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            board[i][j]=0;
        }
    }
    for (q; q > 0; q--)
    {
        scanf("%d%d",&i,&j);
        board[i-1][j-1]=1;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("%d ",board[i][j]);
        }
        printf("\n");
    }
}