#include <array>
#include <cassert>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using ll = long long;

namespace fastio {
    constexpr int MAXBUF=1<<20;
    char buf[MAXBUF],*pl,*pr;
    #define gc()\
    (pl==pr&&(pr=(pl=buf)+fread(buf,1,MAXBUF,stdin),pl==pr)?EOF:*pl++)

    template<typename T> T rd(T &x) {
        x=0;
        T f=1;
        char c=gc();
        while(!isdigit(c)) {
            if(c=='-') f=-1;
            c=gc();
        }
        while(isdigit(c)) x=x*10+(c^48),c=gc();
        return x=x*f;
    }

    template<typename... T> auto read(T&... x) { return (rd(x),...); }
    #undef gc
    
    struct IO {
        template<typename T> friend IO&
        operator>>(IO &io,T& x) { rd(x);return io; }
    } static io;
}
using fastio::read,fastio::io;

constexpr int N = 2e5 + 10;
constexpr int UP = 200;

int g[UP+1][UP+1][UP+1];

int mex(const vector<int>& a) {
    vector<bool> vis(a.size()+1);
    for(int x:a) {
        if(x<a.size()) {
            vis[x]=true;
        }
    }
    int p=0;
    while(vis[p])
        p++;
    return p;
}

int dfs(array<int, 3> x) {
    if(g[x[0]][x[1]][x[2]]!=-1) {
        return g[x[0]][x[1]][x[2]];
    }

    vector<int> nxt;
    for(int i=0; i<3; ++i) {
        int a=min(x[0],x[1]);
        int b=max(x[0],x[1]);
        int d=(b-a)/2;
        for(int i=1; i<=d; ++i) {
            nxt.push_back(dfs({a+i,b-i,x[2]}));
        }
        rotate(x.begin(),x.begin()+1,x.end());
    }
    return g[x[0]][x[1]][x[2]]=mex(nxt);
}

void pre() {
    memset(g, -1, sizeof g);
    vector<int> alls;
    for(int i=0; i<=UP; ++i) {
        for(int j=0; j<=UP; ++j) {
            int re=dfs({i,j,0});

            // a!=b, b!=c, a!=c
            // if(i && j && i!=j) {
            //     assert(re>0);
            // }

            // 2+4k
            // if(i==j && (i-2)%4==0) {
            //     assert(re>0);
            // }
            
            if(i==j && re && (i-2)%4!=0) {
                alls.push_back(i);
            }
                // cerr<< "" << i <<"," << j <<" : " << re << endl;
        }
    }
    for(int i=1; i<alls.size(); ++i) {
        cout<<alls[i]-alls[i-1]<<" ";
    }
    exit(0);
}

void solve() {
    // pre();
    int n;
    read(n);
    vector<ll> a(n);
    map<ll,int> cnt;
    for(ll& x:a) {
        read(x);
        cnt[x]++;
    }

    ll ans=1ll*n*(n-1)*(n-2)/3;
    for(auto& [x,y]:cnt) {
        ans-=1ll*y*(y-1)/2 * (n-y);
        ans-=1ll*y*(y-1)*(y-2)/6;
    }

        
}

int main() {
    // ios::sync_with_stdio(0), cin.tie(0);
    solve();
    return 0;
}
/*
16 8 8 
16 16 16 8 8 
16 8 8 
16 8 8 
16 16 16 8 8 
16 16 16 8 8 
16 16 16 8 8 
16 8 8 
16 8 8 
16 16 16 8 8
*/