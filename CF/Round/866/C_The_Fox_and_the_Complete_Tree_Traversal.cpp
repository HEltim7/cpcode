#include <array>
#include <vector>
#include <random>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
mt19937 gen=mt19937(random_device{}());

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
using PII=pair<int,int>;
constexpr int N=2e5+10; // !!
vector<int> adj[N];
vector<int> ans;
 
bool valid=1;
void dfs(int u,int fa,bool type) {
    if(!valid) return;
    if(!type) ans.push_back(u);
    int cnt=0,idx=0;
    for(int v:adj[u]) {
        if(v!=fa) {
            if(adj[v].size()>1) {
                if(adj[v].size()==2) {
                    dfs(v,u,type^1);
                }
                else {
                    cnt++;
                    idx=v;
                }
            }
        }
    }
    if(cnt==0) {
        for(int v:adj[u]) {
            if(v!=fa) {
                ans.push_back(v);
            }
        }
        if(type) ans.push_back(u);
    }
    else if(cnt==1) {
        dfs(idx,u,type^1);
        for(int v:adj[u]) if(v!=fa&&v!=idx&&adj[v].size()<=1) ans.push_back(v);
        if(type) ans.push_back(u);
    }
    else valid=0;
}

void solve() {
    int n;
    cin>>n;
    for(int i=1;i<n;i++) {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1,0,0);

    auto output=[&]() {
        cout<<"Yes"<<endl;
        for(int v:ans) cout<<v<<' ';
    };

    auto work=[&]() {
        valid=1;
        ans.clear();
        int u=gen()%n+1;
        dfs(u,0,0);
    };

    for(int z=1;z<=100;z++) {
        work();
        if(valid) {
            output();
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}