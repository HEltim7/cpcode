#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

#define endl '\n'
typedef long long LL;
const int N=1e5+10;
const LL INF=-1e12;
LL a[N],p[N];
bool type[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) cin>>type[i];
    LL ans=0,res[2]={0},suf[2]={0};
    multiset<LL> st[2];
    for(int i=n;i>=1;i--) {
        int t=type[i];
        if(a[i]>0) {
            res[t]+=a[i];
            if(-p[i]>a[i]) st[t].insert(-p[i]-a[i]),suf[t]+=(-p[i]-a[i]);
            if(a[i]-p[i]>0) st[t^1].insert(a[i]-p[i]),suf[t^1]+=a[i]-p[i];
        }
        else if(-p[i]>0){
            st[t].insert(-p[i]),suf[t]+=-p[i];
            st[t^1].insert(-p[i]),suf[t^1]+=-p[i];
        }
        while(st[t].size()>m){
            auto it=st[t].lower_bound(INF);
            suf[t]-=*it;
            st[t].erase(it);
        }
        while(st[t^1].size()>m){
            auto it=st[t^1].lower_bound(INF);
            suf[t^1]-=*it;
            st[t^1].erase(it);
        }
        ans=max({ans,res[0]+suf[0],res[1]+suf[1]});
    }
    cout<<ans;
    return 0;
}