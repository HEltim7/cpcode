#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include<debug>
#else
#define debug(...)
#endif

#define endl '\n'
const int N=5e5+10;
using PII=pair<int,int>;
vector<PII> adj[N];

void dfs() {
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].emplace_back(b,c);
        adj[b].emplace_back(a,c);
    }

}