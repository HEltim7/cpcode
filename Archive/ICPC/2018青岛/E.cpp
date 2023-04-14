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

// #ifndef ONLINE_JUDGE
// #define debug(...)
// #include<debug>
// #else
// #define debug(...)
// #endif

const int N=100005;
int a[N];
ll b[N];//需要浇水的次数
int n;
ll m;
bool check(ll mid)
{
    for(int i=1;i<=n;i++)
    {
        b[i]=(mid+a[i]-1)/a[i];
    }

    __int128 res=0;
    for(int i=1;i<=n;i++)
    {
        if(i==n&&b[i]<=0) break;
        res+=1;
        b[i]-=1;
        if(b[i]>0)
        {
            ll t=b[i];
            b[i+1]-=t;
            b[i]-=t;
            res+=2*t;
        }
    }
    return res<=m;
}
void solve()
{
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll l=0,r=1e18;//最小植物的防御值是否能为这么多
    while(l<r)
    {
        ll mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    printf("%lld\n",l);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        solve();
    }
}