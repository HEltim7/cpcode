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

void solve() {
    int k;
    vector<int> n(2);
    vector<LL> sum(2);
    vector<multiset<int>> st(2);
    cin>>n[0]>>n[1]>>k;
    
    for(int i=0,in;i<n[0];i++) cin>>in,st[0].insert(in),sum[0]+=in;
    for(int i=0,in;i<n[1];i++) cin>>in,st[1].insert(in),sum[1]+=in;

    vector<pair<LL,LL>> vec;
    set<pair<LL,LL>> mark;
    mark.emplace(sum[0],sum[1]);
    vec.emplace_back(sum[0],sum[1]);
    int r=0,t=0;
    for(int i=0;i<k;i++) {
        r++;
        bool x=i&1;
        int a=*st[x].begin();
        int b=*st[!x].rbegin();
        if(b-a>=0) {
            sum[x]+=b-a,sum[!x]+=a-b;
            st[x].erase(st[x].begin());
            st[x].insert(b);
            st[!x].erase(prev(st[!x].end()));
            st[!x].insert(a);
        }

        if(x) {
            if(mark.find({sum[0],sum[1]})!=mark.end()) {
                if((k-r)%2==0) cout<<sum[0]<<endl;
                else cout<<vec.back().first<<endl;
                return;
            }
            mark.emplace(sum[0],sum[1]);
        }
        vec.emplace_back(sum[0],sum[1]);
    }

    cout<<sum[0]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}