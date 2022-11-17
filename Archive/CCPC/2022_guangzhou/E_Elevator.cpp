#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;
const int N=500005;
typedef pair<int,int> pii;
typedef long long ll;
int a[N],b[N];
pii c[N];
int tr[N];
ll w[N];
int lowbit(int x)
{
    return x&-x;
}
void add(int x,int c)
{
    while(x<N)
    {
        tr[x]+=c;
        x+=lowbit(x);
    }
}
int query(int x)
{
    int res=0;
    while(x)
    {
        res+=tr[x];
        x-=lowbit(x);
    }
    return res;
}
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int> ver;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),ver.push_back(a[i]),c[i]={a[i],i};
    sort(ver.begin(),ver.end());
    ver.erase(unique(ver.begin(),ver.end()),ver.end());
    for(int i=1;i<=n;i++)
    {
        b[i]=(lower_bound(ver.begin(),ver.end(),a[i])-ver.begin())+1;
    }
    sort(c+1,c+n+1);

    ll t=0;
    for(int i=1;i<=n;i++)
    {
        w[c[i].second]+=1ll*c[i].first*(i-1)-t;
        t+=c[i].first;
    }
    for(int i=1;i<=n;i++)
    {
        w[i]+=query(b[i]);
        add(b[i],1);
    }
    for(int i=1;i<=n;i++)
    {
        if(w[i]<=m-2) printf("%lld\n",w[i]);
        else puts("-1");
    }
}