#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int N=4e3+10;
vector<int> adj[N];
bool mark[N];

void dfs(int u,vector<int> &res) {
    res.push_back(u);
    mark[u]=1;
    for(int v:adj[u]) if(!mark[v]) dfs(v,res);
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        mark[i]=0;
        adj[i].clear();
        for(int j=1;j<=n;j++) {
            char in;
            cin>>in;
            if(in=='1') adj[i].push_back(j);
        }
    }

    int flag=0,tot=0,minn=1e9,id;
    for(int i=1;i<=n;i++) if(!mark[i]) {
        tot++;
        vector<int> cur;
        dfs(i,cur);
        int cnt=0;
        for(auto v:cur) cnt+=adj[v].size()+1;
        if(cnt==cur.size()*cur.size()) {
            if(cur.size()<=minn) {
                minn=cur.size();
                id=i;
            }
        }
        else flag=i;
    }

    auto find=[&](int x) {
        for(int i=1;i<=n;i++) mark[i]=0;
        vector<int> res;
        dfs(x,res);
        
        sort(res.begin(),res.end(),[](int x,int y) {
            return adj[x].size()<adj[y].size();
        });
        return res.front();
    };

    if(tot==1) cout<<0<<endl;
    else if(tot==n) cout<<1<<endl<<1<<endl;
    else if(flag) cout<<1<<endl<<find(flag)<<endl;
    else if(minn==1) cout<<1<<endl<<id<<endl;
    else if(tot==2) {
        cout<<minn<<endl;
        cout<<id<<' ';
        for(auto x:adj[id]) cout<<x<<' ';
        cout<<endl;
    }
    else {
        cout<<2<<endl;
        cout<<id<<' ';
        
        vector<bool> mark(n+1);
        for(auto v:adj[id]) mark[v]=1;
        mark[id]=1;
        adj[id].clear();
        for(int i=1;i<=n;i++) if(!mark[i]) {
            adj[id].push_back(i);
            adj[i].push_back(id);
        }
        cout<<find(id)<<endl;
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