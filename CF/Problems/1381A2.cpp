#include <algorithm>
#include <array>
#include <cassert>
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
    int n;
    string a,b;
    cin>>n>>a>>b;
    
    a=" "+a;
    b=" "+b;
    vector<int> ans;

    bool rev=0;
    for(int i=n,l=1,r=n;i>=1;i--) {
        int pre=rev?r:l;
        int suf=rev?l:r;
        int x=(a[suf]-'0')^rev;
        int y=b[i]-'0';
        int z=(a[pre]-'0')^rev;

        if(x==y) {
            if(!rev) r--;
            else l++;
        }
        else {
            if(z==y) ans.emplace_back(1);
            ans.emplace_back(i);
            if(!rev) l++;
            else r--;
            rev^=1;
        }
    }

    cout<<ans.size()<<' ';
    for(int x:ans) cout<<x<<' ';
    cout<<endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}