//格式化输入输出2
#include<stdio.h>
int main()
{
    int ip;
    float ipf;
    char str[200];
    scanf("%d",&ip);
    scanf("%s",str);
    scanf("%f",&ipf);
    printf("+%d\n",ip);
    printf("%s\n",str);
    printf("+%.2f",ipf);
    return 0;
}