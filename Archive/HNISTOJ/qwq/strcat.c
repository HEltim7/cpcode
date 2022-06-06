#include<stdio.h>
#include<string.h>
int main()
{
    char str1[20],str2[20];
    gets(str1),gets(str2);
    int i=0,j=strlen(str1);//数组第一位不是1而是0，所以i=0
    while (i<=strlen(str2))
    {
        str1[j]=str2[i];
        i++,j++;
    }
    puts(str1);

    //strcat原理，等价于：
    //char str1[20],str2[20];
    //gets(str1),gets(str2);
    //strcat(str1,str2);
    //puts(str1);

    return 0;
}