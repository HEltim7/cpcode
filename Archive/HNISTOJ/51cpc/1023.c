//字符判断
#include<stdio.h>
main()
{
    char inp;
    scanf("%c",&inp);
    if (inp>=65&&inp<=90||inp>=97&&inp<=122)
    {
        printf("A");
    }
    else if(inp>=48&&inp<=57)
    {
        printf("1");
    }
    else
    {
        printf("#");
    }
    
}