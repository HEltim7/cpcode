#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
// #define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const double eps=1e-8;
const int INF=0x3f3f3f3f,mod=998244353;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

const int N=3003;
char s[N][N];
int main()
{
    int n;
    scanf("%d",&n);
    if(n%2)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j%2==0) s[i][j]='.';
                else s[i][j]='U';
            }
        }
    }
    else
    {
        for(int i=1;i<=n-1;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(j%2==0) s[i][j]='.';
                else s[i][j]='U';
            }
        }
        for(int j=1;j<=n;j++)
        {
            if(j%2) s[n][j]='R';
            else s[n][j]='.';
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("%c",s[i][j]);
        }
        puts("");
    }
}