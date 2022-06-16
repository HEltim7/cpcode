#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int p[N],ind[N];
LL l[N],r[N],val[N];

void solve() {
    int n;
    cin>>n;
    memset(ind,0,sizeof (int)*(n+1));
    memset(val,0,sizeof (LL)*(n+1));
    queue<int> q;
    for(int i=2;i<=n;i++) cin>>p[i],ind[p[i]]++;
    for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
    for(int i=1;i<=n;i++) if(!ind[i]) q.push(i);
    LL ans=0;
    while(q.size()) {
        int u=q.front();
        q.pop();
        LL tmp=0;
        if(val[u]>=l[u]) tmp=min(val[u],r[u]);
        else ans++,tmp=r[u];
        if(u!=1) {
            val[p[u]]+=tmp;
            ind[p[u]]--;
            if(ind[p[u]]==0) q.push(p[u]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}