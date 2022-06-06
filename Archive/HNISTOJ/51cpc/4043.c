#include<stdio.h>
#include<string.h>
char str[1024];
int len;

void move(int point)
{
        
        if (str[point]=='+'&&str[point+1]=='(')//type:"+("
        {
            int num=1;
            for (int j = point+2;num > 0; j++)
            {
                if (str[j]=='(')
                {
                    move(point);
                }
                
            }
            
        }
        
    
    
}

int main()
{
    scanf("%[^\n]",&str[1]);
    len=strlen(str);
    for (int i = 1; i <= len; i++)
    {
        if (str[i]=='(')
        {
            move(i);
        }
        
    }
       
    return 0;
}