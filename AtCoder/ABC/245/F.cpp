#include<vector>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

#define endl '\n'
using LL=long long;
const int N=2e5+10;
int ind[N],outd[N];
vector<int> adj[N];
int n,m;

int bfs(){
    queue<int> q;
    int ans=0;
    for(int i=1;i<=n;i++) if(outd[i]==0) q.push(i),ans++;
    while(q.size()){
        int h=q.front();
        q.pop();
        for(auto x:adj[h]){
            outd[x]--;
            if(outd[x]==0) q.push(x),ans++;
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        ind[b]++;
        outd[a]++;
        adj[b].push_back(a);
    }
    cout<<n-bfs();
    return 0;
}