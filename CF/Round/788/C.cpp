#include<vector>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e5+10,mod=1e9+7;
int arr[N],loc[N];
int c[N];
bool mark[N];

void dfs(int u) {
    while(!mark[u]){
        mark[u]=1;
        u=loc[arr[u]];
    }
}

void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>arr[i];
    for(int i=1;i<=n;i++) {
        int in;
        cin>>in;
        loc[in]=i;
    }
    for(int i=1;i<=n;i++) cin>>c[i];
    memset(mark,0,sizeof (bool)*(n+1));

    LL ans=1;
    for(int i=1;i<=n;i++) 
        if(c[i]&&!mark[i]) dfs(i);
        
    for(int i=1;i<=n;i++) 
        if(!mark[i]) {
            if(loc[arr[i]]!=i) ans=ans*2%mod;
            dfs(i);
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