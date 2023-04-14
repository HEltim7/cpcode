#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=1e5+10;
int arr[N],sum;
vector<int> adj[N];
bool valid;

pair<int,bool> dfs(int u,int fa) {
    int cnt=0;
    int res=arr[u];
    for(int v:adj[u]) {
        if(v!=fa) {
            auto [x,y]=dfs(v,u);
            res^=x;
            cnt+=y;
        }
    }
    if(res==0&&cnt||cnt>=2) valid=1;
    if(res==sum) cnt++;
    return {res,cnt};
}

void solve() {
    int n,k;
    cin>>n>>k;
    sum=0;
    valid=0;
    for(int i=1;i<=n;i++) adj[i].clear();
    for(int i=1;i<=n;i++) cin>>arr[i],sum^=arr[i];
    for(int i=2;i<=n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(sum==0) cout<<"YES"<<endl;
    else {
        if(k==2) cout<<"NO"<<endl;
        else {
            dfs(1,0);
            if(valid) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}