#include<vector>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<cassert>
using namespace std;
#define debug(x) cout<<"[debug]"#x<<"="<<x<<endl
typedef long long ll;

void solve()
{
    vector<__int128_t> last;
    ll k,x,y;
    scanf("%lld%lld%lld",&k,&x,&y);

    last.push_back(1);
    __int128_t sum=1;

    vector<ll> ver1;
    vector<ll> ver2;
    while(sum<=max(x,y))
    {
        sum+=k*sum;
        last.push_back(sum);
    }
    ll now=x;
    ver1.push_back(x);
    while(now!=1)
    {
        int id=lower_bound(last.begin(),last.end(),now)-last.begin();
        now=((now-last[id-1])+k-1)/k;
        ver1.push_back(now);
    }
    now=y;
    ver2.push_back(y);
    while(now!=1)
    {
        int id=lower_bound(last.begin(),last.end(),now)-last.begin();
        now=((now-last[id-1])+k-1)/k;
        ver2.push_back(now);
    }
    for(int i=0;i<ver1.size();i++)
    {
        for(int j=0;j<ver2.size();j++)
        {
            if(ver1[i]==ver2[j])
            {
                printf("%lld\n",ver1[i]);
                return ;
            }
        }
    }
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