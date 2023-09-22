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

// #define ONLINE_JUDGE
#ifndef ONLINE_JUDGE
#include <heltim7/debug>
#else
#define debug(...) 7
#endif

#define endl '\n'
using LL=long long;
constexpr int N=1e7+10;
string s,ans;

void solve() {
    cin>>s;
    int n=s.size();
    auto pos=vector(10,vector<int>());
    vector<int> idx(10);
    for(int i=0;i<n;i++) {
        pos[s[i]-'0'].emplace_back(i);
    }
    
    ans.clear();
    vector<int> mn(10),pre(10),suf(10);
    for(int i=0;i<n;i++) {
        for(int j=0;j<10;j++) {
            mn[j]=idx[j]>=pos[j].size()?N:pos[j][idx[j]];
            if(j) pre[j]=min(pre[j-1],mn[j]);
            else pre[j]=mn[j];
        }
        suf[9]=mn[9];
        for(int j=8;j>=0;j--) suf[j]=min(suf[j+1],mn[j]);
        
        bool zero=idx[0]<pos[0].size();
        for(int k=2;k<9&&zero;k++) {
            if(mn[k]<pos[0][idx[0]]) zero=false;
        }
        if(zero) {
            ans.push_back('0');
            idx[0]++;
            continue;
        }

        for(int j=1;j<10;j++) {
            if(idx[j]>=pos[j].size()) continue;
            int x=j-2>=0?pre[j-2]:N;
            int y=j+2<10?suf[j+2]:N;
            if(pos[j][idx[j]]<min(x,y)) {
                ans.push_back(j+'0');
                idx[j]++;
                break;
            }
        }
    }

    assert(ans.size()==n);
    cout<<ans<<endl;
}

int main() {
    s.reserve(N);
    ans.reserve(N);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}