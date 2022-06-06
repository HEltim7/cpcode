//提取字串->flag：计算输出空格->输出字串->循环flag
//'' 用于包裹字符 ""用于包裹字符串
//while后不能加；！，会导致出错
#include<stdio.h>
#include<string.h>
int main()
{
    char s1[9],s2[9],s3[9],str[30];
    int len1,len2,len3,i,j;
    //提取字符串
    gets(str);
    j=0;
    for (i = 0; str[i]!=' ';i++,j++)
    {
        s1[j]=str[i];
    }
    i++,j=0;

    for (i; str[i]!=' ';i++,j++)
    {
        s2[j]=str[i];
    }
    i++,j=0;

    for (i; str[i]!='\0';i++,j++)
    {
        s3[j]=str[i];
    }
    //printf("%s\n%s\n%s\n",s1,s2,s3);

    //输出字串
    len1=8-strlen(s1);
    len2=8-strlen(s2);
    len3=8-strlen(s3);
    //printf("%d\n%d\n%d\n",len1,len2,len3);
    
    while (len1!=0)
    {
        printf("%c",' ');
        len1--;
    }
    printf("%s\n",s1);

    while (len2!=0)
    {
        printf("%c",' ');
        len2--;
    }
    printf("%s\n",s2);

    while (len3!=0)
    {
        printf("%c",' ');
        len3--;
    }
    printf("%s",s3);
    return 0;
}