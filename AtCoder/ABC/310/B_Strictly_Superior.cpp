#include <algorithm>
#include <array>
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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=110;
int p[N];
set<int> st[N];

void solve() {
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        int c;
        cin>>c;
        while(c--) {
            int in;
            cin>>in;
            st[i].insert(in);
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            if(i==j) continue;
            if(p[j]>p[i]) continue;
            set<int> x=st[i],y=st[j];
            x.merge(y);
            if(x.size()==st[j].size()) {
                if(p[j]<p[i]) {
                    cout<<"Yes"<<endl;
                    return;
                }
                else if(st[j].size()>st[i].size()) {
                    debug(i,j);
                    cout<<"Yes"<<endl;
                    return;
                }
            }
        }
    }
    cout<<"No"<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    solve();
    return 0;
}