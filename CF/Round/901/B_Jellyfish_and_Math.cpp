#include <algorithm>
#include <array>
#include <cassert>
#include <cstring>
#include <functional>
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
using ARR=array<int,8>;
constexpr int N=390624;
vector<int> adj[N+10];
int ans[N+10];
constexpr ARR nil={4,4,4,4,4,4,4,4};

int id(const ARR &arr) {
    int res=0;
    for(int i=0,pw=1;i<8;i++) res+=pw*arr[i],pw*=5;
    return res;
}

void init() {
    fill(ans,ans+N+10,-1);
    vector<bool> mark(N+10);
    queue<int> q;
    for(int i=0;i<=N;i++) {
        int t=i;
        ARR arr{};
        bool ok=true;

        for(int j=0;j<8;j++) {
            arr[j]=t%5,t/=5;
            bool x=j>>0&1;
            bool y=j>>1&1;
            bool m=j>>2&1;
            if(arr[j]==4||x==(arr[j]>>0&1)&&y==(arr[j]>>1&1));
            else ok=false;
        }
        if(ok) q.emplace(i),ans[i]=0,mark[i]=true;
        
        auto op1=[](bool x,bool y,bool m) { return tuple{x&y,y,m}; };
        auto op2=[](bool x,bool y,bool m) { return tuple{x|y,y,m}; };
        auto op3=[](bool x,bool y,bool m) { return tuple{x,x^y,m}; };
        auto op4=[](bool x,bool y,bool m) { return tuple{x,y^m,m}; };

        auto add_edge=[&](auto f) {
            ARR ne=nil;
            for(int k=0;k<8;k++) {
                if(arr[k]==4) continue;
                auto [x,y,m]=f(k>>0&1,k>>1&1,k>>2&1);
                int idx=x<<0|y<<1|m<<2;
                if(ne[idx]!=4&&ne[idx]!=arr[k]) return;
                ne[idx]=arr[k];
            }
            adj[id(ne)].emplace_back(i);
        };

        add_edge(op1);
        add_edge(op2);
        add_edge(op3);
        add_edge(op4);
    }

    while(q.size()) {
        int u=q.front();
        q.pop();
        for(int v:adj[u]) {
            if(!mark[v]) {
                ans[v]=ans[u]+1;
                mark[v]=1;
                q.emplace(v);
            }
        }
    }
}

void solve() {
    array<int,5> in;
    cin>>in[0]>>in[1]>>in[3]>>in[4]>>in[2];
    ARR arr=nil;
    for(int i=0;i<30;i++) {
        int abm=0,cd=0;
        for(int j=0;j<3;j++) abm|=(in[j]>>i&1)<<j;
        for(int j=3;j<5;j++) cd|=(in[j]>>i&1)<<(j-3);
        if(arr[abm]!=4&&arr[abm]!=cd) {
            cout<<-1<<endl;
            return;
        }
        arr[abm]=cd;
    }
    
    cout<<ans[id(arr)]<<endl;
}

int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}