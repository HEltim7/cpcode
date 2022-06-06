#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int a[N],b[N];
vector<int> adj[N*2];
bool ans;
bool pass[N][2];
int n,k;

void dfs(int x,bool type){
    pass[x][type]=1;
    if(x==n){
        ans=1;
        return;
    }
    if(type){
        if(!pass[x+1][1]&&abs(a[x+1]-a[x])<=k) dfs(x+1,1);
        if(!pass[x+1][0]&&abs(b[x+1]-a[x])<=k) dfs(x+1,0);
    }
    else{
        if(!pass[x+1][0]&&abs(b[x+1]-b[x])<=k) dfs(x+1,0);
        if(!pass[x+1][1]&&abs(a[x+1]-b[x])<=k) dfs(x+1,1);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    dfs(1,1);
    dfs(1,0);
    if(ans) cout<<"Yes";
    else cout<<"No";
    return 0;
}