//日常题看错qwq
//记忆化递归
#include<iostream>
using namespace std;
long long mem[30][30][30];

long long function(long a,long b,long c)
{
    if (a<=0||b<=0||c<=0)
    {
        return 1;
    }
    else if (a>20||b>20||c>20)
    {
        return function(20,20,20);
    }
    else if (mem[a][b][c])
    {
        return mem[a][b][c];
    }
    else if (a<b&&b<c)
    {
        mem[a][b][c]=function(a,b,c-1)+function(a,b-1,c-1)-function(a,b-1,c);
        return mem[a][b][c];
    }
    else
    {
        mem[a][b][c]=function(a-1,b,c)+function(a-1,b-1,c)+function(a-1,b,c-1)-function(a-1,b-1,c-1);
        return mem[a][b][c];
    }
}

int main()
{
    long long a,b,c,ans=0;
    while(cin>>a>>b>>c)
    {
        if (a==-1&&b==-1&&c==-1)
            break;
        ans=function(a,b,c);    
        cout<<"w("<<a<<", "<<b<<", "<<c<<") = "<<ans<<endl;
    }
    return 0;
}