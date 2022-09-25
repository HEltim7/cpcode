#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cassert>
using namespace std;

typedef long long ll;

const int N=100005;
int a[N];
int n;
int cl[N],cr[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    a[n+1]=0x3f3f3f3f;
    a[0]=0x3f3f3f3f;
    for(int i=1;i<=n;i++)//从右往左最多能选多少个数
    {
        if(a[i]<a[i-1]) cr[i]=cr[i-1]+1;
        else cr[i]=1;
    }
    for(int i=n;i>=1;i--)//从左往右最多能选多少个数
    {
        if(a[i]<a[i+1]) cl[i]=cl[i+1]+1;
        else cl[i]=1;
    }
    if(n==1)
    {
        puts("Alice");
        return 0;
    }
    int l=1,r=n;
    int ty=0;
    int now=0;
    while(l<r)
    {
        if(a[l]>now&&a[r]>now)
        {
            if(a[l]==a[r])
            {
                int res=((cl[l]%2)||(cr[r]%2));
                if(res==1)
                {
                    puts(ty==0?"Alice":"Bob");
                    return 0;
                }
                else
                {
                    puts(ty==0?"Bob":"Alice");
                    return 0;
                }
            }
            else if(a[l]>a[r])
            {
                int res=cl[l]%2;
                if(res==1)
                {
                    puts(ty==0?"Alice":"Bob");
                    return 0;
                }
                now=max(now,a[r]);
                r--;
            }
            else if(a[l]<a[r])
            {
                int res=cr[r]%2;
                if(res==1)
                {
                    puts(ty==0?"Alice":"Bob");
                    return 0;
                }

                now=max(now,a[l]);
                l++;
            }
        }
        else if(a[l]>now)
        {
            int res=cl[l]%2;
            if(res==1)
            {
                puts(ty==0?"Alice":"Bob");
                return 0;
            }
            else
            {
                puts(ty==0?"Bob":"Alice");
                return 0;
            }
        }
        else if(a[r]>now)
        {
            int res=cr[r]%2;
            if(res==1)
            {
                puts(ty==0?"Alice":"Bob");
                return 0;
            }
            else
            {
                puts(ty==0?"Bob":"Alice");
                return 0;
            }
        }
        else
        {
            puts(ty==0?"Bob":"Alice");
        }
        ty^=1;
    }
    assert(0);
}