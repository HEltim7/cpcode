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
    LL k,a,b;
    cin>>k>>a>>b;
    if(a==b) cout<<a*k<<endl;
    else {
        using T=tuple<LL,LL,LL>;
        map<LL,pair<LL,LL>> mp;
        mp[0]={0,0};
        for(int i=0;i<k;i++) {
            auto [sum,p]=*mp.begin();
            auto [x,y]=p;
            mp[sum+a]={x+1,y};
            mp[sum+b]={x,y+1};
            mp.erase(mp.begin());
        }
        auto [sum,_]=*mp.begin();
        cout<<sum<<endl;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}