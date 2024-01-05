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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

using Hash=pair<int,int>;
constexpr int p1=998244353,p2=int(1e9)+7;
Hash operator*(Hash x,Hash y) {
    return Hash(1LL*x.first*y.first%p1,1LL*x.second*y.second%p2);
}
Hash operator+(Hash x,Hash y) {
    return Hash((x.first+y.first)%p1,(x.second+y.second)%p2);
}
Hash operator-(Hash x,Hash y) {
    return Hash((x.first-y.first+p1)%p1,(x.second-y.second+p2)%p2);
}

struct HashArray {
    constexpr static Hash base{114514,1919810};
    vector<Hash> hsh,pw;

    void push_back(int x) {
        hsh.push_back(hsh.back()*base+Hash(x,x));
        pw.push_back(pw.back()*base);
    }

    template<class S> void append(const S &s) {
        for(auto x:s) push_back(x);
    }

    Hash query(int l,int r) {
        // if(l>r) return {};
        return hsh[r+1]-hsh[l]*pw[r-l+1];
    }

    void clear() {
        hsh.clear(),pw.clear();
        hsh.emplace_back(),pw.emplace_back(1,1);
    }
    
    HashArray(int sz=0) {
        hsh.reserve(sz),pw.reserve(sz);
        clear();
    }
};

void solve() {
    int n;
    string s;
    cin>>n>>s;
    
    constexpr int N=5e3+10,INF=N*N*2;
    auto dp=vector(n+1,vector(n+1,N));
    auto mn=vector(n+1,vector(n+1,INF));
    HashArray pre(n+1),suf(n+1);
    pre.append(s);
    for(auto &x:s) x=x=='v'?'^':'v';
    reverse(s.begin(),s.end());
    suf.append(s);

    vector<vector<int>> L(n+1),R(n+1);

    auto check=[&](int l,int r) {
        if(l==r) return true;
        int m=(l+r)/2;
        return pre.query(l-1, m-2)==suf.query(n-r, n-m-1);
    };

    for(int len=1;len<=n;len+=2) {
        for(int l=1,r=l+len-1;r<=n;l++,r++) {
            if(check(l,r)) {
                L[r].emplace_back(l);
                R[l].emplace_back(r);
            }
        }
    }

    dp[1][n]=0,mn[1][n]=0;
    for(int len=n;len>=2;len--) {
        for(int l=1,r=l+len-1;r<=n;l++,r++) {
            for(int x:R[l]) {
                if(x>r) break;
                int m=(l+x)/2;
                if(dp[l][r]+1<dp[m+1][r]) {
                    dp[m+1][r]=dp[l][r]+1;
                    mn[m+1][r]=mn[l][r]+r-x;
                }
                else if(dp[l][r]+1==dp[m+1][r]) {
                    mn[m+1][r]=min(mn[m+1][r],mn[l][r]+r-x);
                }
            }
            for(int x:L[r]) {
                if(x<l) break;
                int m=(x+r)/2;
                if(dp[l][r]+1<dp[l][m-1]) {
                    dp[l][m-1]=dp[l][r]+1;
                    mn[l][m-1]=mn[l][r]+x-l;
                }
                else if(dp[l][r]+1==dp[l][m-1]) {
                    mn[l][m-1]=min(mn[l][m-1],mn[l][r]+x-l);
                }
            }
        }
    }

    int step=N,asym=INF;
    for(int i=1;i<=n;i++) step=min(step,dp[i][i]+1);
    for(int i=1;i<=n;i++) if(dp[i][i]+1==step) asym=min(asym,mn[i][i]);
    cout<<step<<' '<<asym<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}