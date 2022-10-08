#include <queue>
#include <vector>
#include <tuple>
#include <iostream>
#include <algorithm>
using namespace std;

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=440;
bool mark[N][N];
int res[N][N];
int n,m;
vector<pair<int,int>> e;

void bfs() {
    queue<tuple<int,int,int>> q;
    q.emplace(1,1,0);
    mark[1][1]=1;
    while(q.size()) {
        auto [r,c,s]=q.front();
        debug(r,c);
        q.pop();
        int mvr[]={1,1,-1,-1};
        int mvc[]={-1,1,-1,1};
        for(auto [x,y]:e) {
            for(int k=0;k<4;k++) {
                int i=mvr[k]*x+r;
                int j=mvc[k]*y+c;
                if(i>=1&&i<=n&&j>=1&&j<=n&&!mark[i][j])
                    mark[i][j]=1,res[i][j]=s+1,q.emplace(i,j,s+1);
            }
        }
    }
}

void solve() {
    cin>>n>>m;
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++) 
            if(i*i+j*j==m) e.emplace_back(i,j);
    bfs();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            cout<<(mark[i][j]?res[i][j]:-1)<<" \n"[j==n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}