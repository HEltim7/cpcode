//C语言成绩统计分析2
#include<stdio.h>
int main()
{
    int p,i,m,j,head,btm;
    float avg=0;
    scanf("%d",&p);
    int score[p];
    for(i=0;i<p;i++)
    {
        scanf("%d",&score[i]);
    }
    scanf("%d",&m);
    int request[m];
    for(i=0;i<2*m;i++)
    {
        scanf("%d",&request[i]);
    }
    for(i=0;i<2*m;i+=2)
    {
        head=request[i]-1;
        btm=request[i+1]-1;
        j=btm-head+1;
        //printf("j=%d\n",btm);
        for(head;head<=btm;head++)
        {
            avg=avg+score[head];
            //printf("test%d",score[head]);
            //printf("test%f",avg);
        }
        avg=avg/j;
        printf("avg=%.2f\n",avg);
        //printf("%.2f\n",avg*1./j);
        avg=0;
    }
    return 0;
}