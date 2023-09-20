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
using I128=__int128;
constexpr int N=2e5+10;

void solve() {
    int w,h,l,n;
    cin>>w>>h>>l>>n;
    I128 totv=I128(w)*h*l;
    map<tuple<int,int,int>,bool> mp;
    for(int i=1;i<=n;i++) {
        int a,b,c,x,y,z;
        cin>>a>>b>>c>>x>>y>>z;
        totv-=I128(x-a)*(y-b)*(z-c);
        mp[{a,b,c}]^=1;
        mp[{x,b,c}]^=1;
        mp[{a,y,c}]^=1;
        mp[{a,b,z}]^=1;
        mp[{x,y,c}]^=1;
        mp[{a,y,z}]^=1;
        mp[{x,b,z}]^=1;
        mp[{x,y,z}]^=1;
    }
    if(totv) {
        cout<<"No"<<endl;
        return;
    }

    for(auto [p,b]:mp) {
        auto [x,y,z]=p;
        if((x==0||x==w)&&(y==0||y==h)&&(z==0||z==l)) {
            if(!b) {
                cout<<"No"<<endl;
                return;
            }
        }
        else if(b) {
            debug(x,y,z);
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}