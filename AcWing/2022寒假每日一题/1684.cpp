#include<vector>
#include<cstring>
#include<iostream>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef vector<int> VI;
const int N=1e2+10;
VI adj[N];
int ans[N];

void dfs(int x){
    bool cnt[5];
    memset(cnt,0,sizeof cnt);
    for(auto s:adj[x]) cnt[ans[s]]=1;
    for(int i=1;i<=4;i++) 
        if(!cnt[i]){
            ans[x]=i;
            break;
        }
    for(auto s:adj[x]) if(!ans[s]) dfs(s);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
}