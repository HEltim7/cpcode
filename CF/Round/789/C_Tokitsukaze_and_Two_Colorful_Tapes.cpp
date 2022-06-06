#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10;
int a[N],b[N],idx[N];
bool mark[N];

int dfs(int u) {
    int res=0;
    while(!mark[u]){
        mark[u]=1;
        u=idx[a[u]];
        res++;
    }
    return res/2*2;
}

void solve() {
    int n,cnt=0;
    cin>>n;
    memset(mark,0,sizeof (bool)*(n+1));
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],idx[b[i]]=i;
    for(int i=1;i<=n;i++) if(!mark[i]) cnt+=dfs(i);
    LL ans=0;
    for(int i=1,v=n-1;i<=cnt/2;i++,v-=2) ans+=v*2;
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