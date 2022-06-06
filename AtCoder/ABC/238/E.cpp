#include<iostream>
#include<vector>
using namespace std;

#define endl '\n'
typedef long long LL;
typedef vector<int> VI;
const int N=2e5+10;
bool pass[N];
VI adj[N];

void dfs(int root,int fa){
    pass[root]=1;
    for(int x:adj[root]){
        if(x==fa||pass[x]) continue;
        dfs(x,root);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=q;i++){
        int l,r;
        cin>>l>>r;
        adj[l-1].push_back(r);
        adj[r].push_back(l-1);
    }
    dfs(0,-1);
    if(pass[n]) cout<<"Yes";
    else cout<<"No";
    return 0;
}