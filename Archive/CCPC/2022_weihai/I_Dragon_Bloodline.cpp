#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

typedef long long ll;
const int N=50004,M=55;
int a[N];
ll b[M];
ll nb[M];
ll num[M];
int n,k;
bool check(ll mid)
{
    memset(num,0,sizeof num);
    for(int i=1;i<=n;i++)
    {
        ll t=a[i]*mid;
        for(int j=0;j<M;j++) if(t>>j&1) num[j]++;
    }
    for(int i=0;i<k;i++) nb[i]=b[i];
    // int id=M-1;
    // for(int i=M-1;i>=0;i--)
    // {
    //     while(num[i])
    //     {
    //         // cout<<num[i]<<endl;
    //         while(id>=0&&!nb[id]) id--;

    //         if(id<0) return false;
    //         if(id<i)
    //         {
    //             ll bei=(1<<(i-id));
    //             ll cha=min(num[i],nb[id]/bei);
    //             num[i]-=cha;
    //             nb[id]-=cha*bei;
    //             if(num[i]&&id>0) nb[id]=0,nb[id-1]+=nb[id]*2;
    //             id--;
    //         }
    //         else 
    //         {
    //             ll cha=min(num[i],nb[id]);
    //             num[i]-=cha;
    //             nb[id]-=cha;
    //         }
    //     }
    // }
    
    return true;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&k);

        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<k;i++) scanf("%lld",&b[i]);

        ll l=0,r=2e10;
        while(l<r)
        {
            ll mid=(l+r+1)>>1;
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("%lld\n",l);
    }
}
