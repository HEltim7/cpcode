#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=1e6+10;
vector<pair<int,int>> adj[N];
int ind[N],ans[N];

void dfs(int x,int fa){
    for(auto [s,d]:adj[x]){
        if(d==1) ans[x]+=ind[s];
        if(s!=fa) dfs(s,x);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        int a,b;
        cin>>a>>b;
        adj[a].emplace_back(i,b);
        adj[i].emplace_back(a,b);
        if(b==1) ind[a]++,ind[i]++;
        else if(b==2) ans[i]++,ans[a]++;
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++) cout<<ans[i]+1<<endl;
    return 0;
}