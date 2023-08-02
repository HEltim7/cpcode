#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

#define endl '\n'
using LL=long long;
constexpr int M=1e3+10,N=10,INF=0x3f3f3f3f;
using BS=bitset<N>;
int dp[1<<N];
int d[M],del[M],add[M];
bool mark[1<<N];

void solve() {
    int n,m;
    cin>>n>>m;
    auto read=[&]() {
        BS in;
        cin>>in;
        return in.to_ulong();
    };

    memset(mark, 0, sizeof mark);
    memset(dp, 0x3f, sizeof dp);
    int init=read();
    dp[init]=0;
    for(int i=1;i<=m;i++) {
        cin>>d[i];
        del[i]=~read();
        add[i]=read();
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> heap;
    heap.emplace(dp[init],init);
    while(heap.size()) {
        auto [day,status]=heap.top();
        heap.pop();
        if(mark[status]) continue;
        mark[status]=1;
        for(int i=1;i<=m;i++) {
            int st=status&del[i]|add[i];
            if(day+d[i]<dp[st]) {
                dp[st]=day+d[i];
                heap.emplace(dp[st],st);
            }
        }
    }

    cout<<(dp[0]==INF?-1:dp[0])<<endl;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}