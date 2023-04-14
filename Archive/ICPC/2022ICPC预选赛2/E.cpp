#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;

const int N=103;
int primes[N],idx;
bool st[N];
void init(int n)
{
    st[1]=true;

    for(int i=2;i<=n;i++)
    {
        if(!st[i]) primes[idx++]=i;
        for(int j=0;primes[j]<=n/i;j++)
        {
            int t=primes[j]*i;
            st[t]=true;
            if(i%primes[j]==0) break;
        }
    }
}
int main() {
    init(N-1);
    int n,k;
    scanf("%d%d",&n,&k);

    ll res=0;
    int fi;
    for(int i=0;i<idx;i++)
    {
        if(k%primes[i]!=0)
        {
            fi=primes[i];
            res+=k;
            break;
        }
    }
    res+=fi;
    n-=2;
    if(fi!=2)
    {
        res+=3*(n/2)+2*(n-n/2);
    }
    else
    {
        res+=2*(n/2)+3*(n-n/2);
    }
    printf("%lld\n",res);
}