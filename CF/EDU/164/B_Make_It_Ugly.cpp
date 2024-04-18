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

void solve() {
    int n;
    cin>>n;
    vector<int> arr(n);
    vector<pair<int,int>> seg;
    for(int &x:arr) cin>>x;
    for(int x:arr) {
        if(seg.empty()||seg.back().first!=x) seg.emplace_back(x,1);
        else seg.back().second++;
    }
    if(seg.size()==1) cout<<-1<<endl;
    else if(seg.size()%2==0) cout<<0<<endl;
    else {
        for(int i=1;i+1<seg.size();i+=2) {
            if(seg[i-1].first!=seg[i+1].first) {
                cout<<0<<endl;
                return;
            }
        }
        int res=1e9;
        for(int i=0;i<seg.size();i+=2) res=min(res,seg[i].second);
        cout<<res<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}