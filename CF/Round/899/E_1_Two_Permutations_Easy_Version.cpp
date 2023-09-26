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
#include <string>
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
constexpr int N=2.5e3+10;

void solve() {
    using P=basic_string<int>;

    int n,m;
    cin>>n>>m;
    array<vector<int>,2> op{};
    array<P,2> s({P(n,0),P(m,0)});
    for(int &x:s[0]) cin>>x;
    for(int &x:s[1]) cin>>x;

    auto rot=[&](int id,int x) {
        s[id]=s[id].substr(x+1)+s[id][x]+s[id].substr(0,x);
        op[id].emplace_back(x+1);
    };

    auto work=[&](int id) {
        int n=s[id].size();
        for(int i=1;i<=n;i++) {
            int p=find(s[id].begin(),s[id].end(),i)-s[id].begin();
            if(i>1) rot(id, p);
            p=find(s[id].begin(),s[id].end(),i)-s[id].begin();
            if(i<n&&p!=n-1) rot(id, p+1);
        }
    };

    work(0),work(1);
    if(op[0].size()!=op[1].size()) {
        bool id=op[0].size()<=op[1].size()?0:1;
        int d=op[!id].size()-op[id].size();
        if(d%2==1) {
            if(n%2==0&&m%2==0) {
                cout<<-1<<endl;
                return;
            }
            else {
                if(n&1) for(int i=0;i<n;i++) rot(0, n-1);
                else for(int i=0;i<m;i++) rot(1, m-1);
            }
        }
        id=op[0].size()<=op[1].size()?0:1;
        d=op[!id].size()-op[id].size();
        for(int i=1;i<=d/2;i++) rot(id, 0),rot(id, s[id].size()-1);
    }

    assert(is_sorted(s[0].begin(),s[0].end()));
    assert(is_sorted(s[1].begin(),s[1].end()));
    cout<<op[0].size()<<endl;
    for(int i=0;i<op[0].size();i++) {
        cout<<op[0][i]<<' '<<op[1][i]<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}