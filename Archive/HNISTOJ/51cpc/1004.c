//简单加密
#include<stdio.h>
main()
{
    char s1,s2,s3;
    s1=getchar();
    s2=getchar();
    s3=getchar();
    putchar(s1+2);
    putchar(s2+2);
    putchar(s3+2);

    // ALT
    // int i=0;
    // char str[4];
    // gets(str);
    // while(i<=3)
    // {
    //     str[i]=str[i]+2;
    //     i++;
    // }
    // printf("%s",str);

    // ALT
    // {
    //     char a,b,c;
    //     scanf("%c%c%c",&a,&b,&c);
    //     a=a+2;
    //     b=b+2;
    //     c=c+2;
    //     printf("%c%c%c",a,b,c);
    // }
}