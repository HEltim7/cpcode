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
    int n,m;
    cin>>n>>m;
    
    int idx=0;
    for(int i=1;i<=m&&!idx;i++) {
        for(int j=1;j<=n&&!idx;j++) {
            char x;
            cin>>x;
            if(x=='#') idx=j;
        }
    }
    if(!idx) idx=1;

    auto odd=[&]() {
        vector<tuple<char,int,int>> ans;
        int t=(idx&1)?idx:idx-1;
        if(t+2>n) t-=2;
        ans.emplace_back('T',2,t);
        for(int i=t-2;i>=1;i-=2) ans.emplace_back('S',0,i);
        for(int i=t+2;i+2<=n;i+=2) ans.emplace_back('Z',0,i);
        ans.emplace_back('T',3,1);
        for(int i=2;i+2<=n-1;i+=2) ans.emplace_back('Z',0,i);
        ans.emplace_back('L',2,n-1);
        return ans;
    };

    auto even=[&]() {
        vector<tuple<char,int,int>> ans;
        int t=(idx&1)?idx:idx-1;
        if(t+2>n) t-=2;
        ans.emplace_back('T',2,t);
        for(int i=t-2;i>=1;i-=2) ans.emplace_back('S',0,i);
        for(int i=t+2;i+2<=n-1;i+=2) ans.emplace_back('Z',0,i);
        ans.emplace_back('T',3,1);
        for(int i=2;i+2<=n-2;i+=2) ans.emplace_back('Z',0,i);
        ans.emplace_back('T',1,n-1);
        ans.emplace_back('T',0,n-2);
        return ans;
    };

    auto even_rev=[&]() {
        vector<tuple<char,int,int>> ans;
        int t=idx-2;
        ans.emplace_back('T',2,t);
        for(int i=t-2;i>=2;i-=2) ans.emplace_back('S',0,i);
        ans.emplace_back('T',1,n-1);
        for(int i=n-3;i>=3;i-=2) ans.emplace_back('S',0,i);
        ans.emplace_back('T',3,1);
        ans.emplace_back('T',0,1);
        return ans;
    };

    vector<tuple<char,int,int>> ans;
    if(n&1) ans=odd();
    else if(idx<n) ans=even();
    else ans=even_rev();

    cout<<ans.size()<<endl;
    for(auto [a,b,c]:ans) cout<<a<<' '<<b<<' '<<c<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}